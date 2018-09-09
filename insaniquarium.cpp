#include "insaniquarium.h"
#include "config.h"
#include <QDebug>

Insaniquarium::Insaniquarium(QWidget *parent)
    : QGraphicsView(parent),
      m_alienAttack(false), m_gaming(false),
      m_maxFoodCount(Config::INIT_FOODS_RESTRICT),
      m_currentFoodCount(0), m_alienName(""),
      m_maxFoodLevel(2), m_foodLevel(0),
      m_step(0), m_money(0),
      m_fishCount(0), m_gameLevel(0), m_eggLevel(0),
      m_feedable(true)
{
    // set screen sizes
    setFixedSize(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT);

    // set geometry
    QDesktopWidget w;
    setGeometry((w.width() - Config::SCREEN_WIDTH) / 2,
                (w.height() - Config::SCREEN_HEIGHT) / 2,
                Config::SCREEN_WIDTH,
                Config::SCREEN_HEIGHT);

    // add scene
    m_scene = new QGraphicsScene;
    m_scene->setSceneRect(0, 0, Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT);
    m_scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    setScene(m_scene);

    // add timer
    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()),
            this, SLOT(slt_update()));

    // cache
    setCacheMode(QGraphicsView::CacheBackground);

    // turn off scroll bar
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // load bg images
    m_bgMenuPix = QPixmap(Config::BG_MENU_PATH)
            .scaled(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT,
                    Qt::KeepAspectRatioByExpanding);
    m_bgGamePix = QPixmap(Config::BG_GAME_PATH_1)
            .scaled(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT,
                    Qt::KeepAspectRatioByExpanding);

    // set random seed
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    showStartGameMenu();

}

void Insaniquarium::showStartGameMenu()
{
    // set bg image
    setBackgroundBrush(m_bgMenuPix);

    // set start game btn
    addBtn("startGameBtn");
}

void Insaniquarium::showRestartMenu()
{
    m_scene->clear();
    m_chosenPets.clear();
    QPixmap pix(Config::LABELS_PATH["restartLabel"]);
    QGraphicsPixmapItem * pixmapItem = m_scene->addPixmap(pix);
    pixmapItem->setOffset(230, 0);
    addBtn("restartBtn");
}

void Insaniquarium::showNextLevelMenu()
{
    m_timer->stop();
    m_scene->clear();
    m_gaming = false;
    m_chosenPets.clear();
    QPixmap pix(Config::LABELS_PATH["nextLevelLabel"]);
    QGraphicsPixmapItem * pixmapItem = m_scene->addPixmap(pix);
    pixmapItem->setOffset(230, 0);
    addBtn("nextLevelBtn");
}

void Insaniquarium::choosePets()
{
    m_scene->clear();
    QPixmap pix(Config::LABELS_PATH["choosePetLabel"]);
    QGraphicsPixmapItem * pixmapItem = m_scene->addPixmap(pix);
    pixmapItem->setOffset(230, 0);
    addBtn("confirmBtn");
    int petCount = Config::PETS_TYPE.size();
    if (m_gameLevel < petCount + 1
            && m_gameLevel > 0){
        m_availPets.append(Config::PETS_TYPE.at(m_gameLevel - 1));
    }
    foreach (QString petName, m_availPets) {
        QString btn = petName.append("Btn");
        addBtn(btn);
    }
}

void Insaniquarium::init()
{
    m_scene->clear();
    m_maxFoodCount = Config::INIT_FOODS_RESTRICT;
    m_currentFoodCount = 0;
    m_eggLevel = 0;
    m_fishCount = 0;
    m_foodLevel = 0;
    m_alienAttack = false;
    m_alienName = "";
    m_feedable = true;
    m_gaming = true;
    m_step = 0;

    // init money
    addDisplayer();

    slt_moneyPicked(Config::INIT_MONEY);

    // init fish
    for (int i = 0; i < Config::INIT_FISH_COUNT; i++){

        QPointF initPos = RandomMaker::createRandomPoint(0, Config::SCREEN_WIDTH,
                                                         Config::POOL_UPPER_BOUND,
                                                         Config::POOL_LOWER_BOUND);
        addFish("smallGuppy", initPos);
    }

    // init pets

    foreach (QString petName, m_chosenPets) {
        int x = Config::PETS_INIT_POS_X[petName];
        int y = Config::PETS_INIT_POS_Y[petName];
        QPointF pos = QPointF(x, y);
        addPet(petName, pos);
    }

    // init buttons
    addBtn("smallGuppyBtn");
    addBtn("middleBreederBtn");
    addBtn("carnivoreBtn");
    addBtn("ulturavoreBtn");
    addBtn("grubberBtn");
    addBtn("gekkoBtn");
    addBtn("moreFoodBtn");
    addBtn("foodUpgradeBtn");
    addBtn("eggBtn");


    m_timer->start(20);
}

void Insaniquarium::mousePressEvent(QMouseEvent *event)
{
    if (m_gaming){
        if (event->button() == Qt::LeftButton){
            event->accept();
            if (m_feedable){ // feed fish
                if ((m_scene->items(event->pos())).size() == 0){ // if not press on other item
                    if (m_currentFoodCount < m_maxFoodCount
                            && m_money >= 5){
                        slt_moneyPicked(-5);
                        slt_yieldFood(event->pos());
                    }
                }
            } else { // aliens attack
                emit sgn_attackAlien(event->pos());
            }
        } else {
            event->ignore();
        }
    } else {
        event->ignore();
    }
    QGraphicsView::mousePressEvent(event);

}

void Insaniquarium::addFood(const QPointF & pos)
{
    Food * food = Factory::createFood(Config::FOODS_NAME[m_foodLevel], pos, m_scene);
    connect(food, SIGNAL(sgn_foodWasted()), this, SLOT(slt_foodReduce()));
    m_scene->addItem(food);
    m_currentFoodCount++;
}

void Insaniquarium::addFish(const QString &name, const QPointF &pos)
{
    AbstractFish * fish = Factory::creatFish(name, pos, m_scene);
    connect(fish, SIGNAL(sgn_fishUpgrade(QString,QPointF,qreal)),
            this, SLOT(slt_fishUpgrade(QString,QPointF,qreal)));
    connect(fish, SIGNAL(sgn_yieldFish(QString,QPointF)),
            this, SLOT(slt_yieldFish(QString,QPointF)));
    connect(fish, SIGNAL(sgn_yieldMoney(QString,QPointF)),
            this, SLOT(slt_yieldMoney(QString,QPointF)));
    connect(fish, SIGNAL(sgn_yieldFood(QPointF)),
            this, SLOT(slt_yieldFood(QPointF)));
    connect(fish, SIGNAL(sgn_die()),
            this, SLOT(slt_fishDie()));
    if (Config::GUPPY_TYPE.contains(name)){
        connect(this, SIGNAL(sgn_yieldMoney()),
                fish, SLOT(slt_yieldMoney()));
    }
    m_scene->addItem(fish);
    m_fishCount++;
}

void Insaniquarium::addFish(const QString &name, const QPointF &pos, const qreal dir)
{
    AbstractFish * fish = Factory::creatFish(name, pos, m_scene);
    fish->setDirection(dir);
    connect(fish, SIGNAL(sgn_fishUpgrade(QString,QPointF,qreal)),
            this, SLOT(slt_fishUpgrade(QString,QPointF,qreal)));
    connect(fish, SIGNAL(sgn_yieldFish(QString,QPointF)),
            this, SLOT(slt_yieldFish(QString,QPointF)));
    connect(fish, SIGNAL(sgn_yieldMoney(QString,QPointF)),
            this, SLOT(slt_yieldMoney(QString,QPointF)));
    connect(fish, SIGNAL(sgn_yieldFood(QPointF)),
            this, SLOT(slt_yieldFood(QPointF)));
    connect(fish, SIGNAL(sgn_die()),
            this, SLOT(slt_fishDie()));
    if (Config::GUPPY_TYPE.contains(name)){
        connect(this, SIGNAL(sgn_yieldMoney()),
                fish, SLOT(slt_yieldMoney()));
    }
    m_scene->addItem(fish);
    m_fishCount++;
}

void Insaniquarium::addMoney(const QString &name, const QPointF &pos)
{
    AbstractMoney * money = Factory::createMoney(name, pos, m_scene);
    connect(money, SIGNAL(sgn_moneyPicked(int)),
            this, SLOT(slt_moneyPicked(int)));
    m_scene->addItem(money);
}

void Insaniquarium::addPet(const QString &name, const QPointF &pos)
{
    AbstractPet * pet = Factory::createPet(name, pos, m_scene);
    connect(pet, SIGNAL(sgn_specialSkill(QString, QPointF)),
            this, SLOT(slt_petSkill(QString, QPointF)));
    connect(this, SIGNAL(sgn_alienComes(QString)),
            pet, SLOT(slt_alienComes(QString)));
    connect(this, SIGNAL(sgn_alienDies()),
            pet, SLOT(slt_alienDies()));
    m_scene->addItem(pet);
}

void Insaniquarium::addBtn(const QString &name)
{
    Btn * btn = Factory::creatBtn(name, m_scene);

    connect(btn, SIGNAL(sgn_btnReleased(QString)),
            this, SLOT(slt_btnClicked(QString)));
    m_scene->addItem(btn);
}

void Insaniquarium::addTick(const QString &btn)
{
    QPixmap pix(Config::LABELS_PATH["tickLabel"]);
    pix = pix.scaled(Config::TICK_WIDTH,
                     Config::TICK_HEIGHT,
                     Qt::KeepAspectRatioByExpanding);
    QGraphicsPixmapItem * pixmapItem = m_scene->addPixmap(pix);
    pixmapItem->setOffset(Config::TICK_POS[btn]);
}

void Insaniquarium::addDisplayer()
{
    for ( int i = 0; i < 6; i++){
        MoneyDisplayer * displayer = new MoneyDisplayer(m_scene);
        if (i != 0){
            displayer->setIndex(0);
        } else {
            displayer->setIndex(10);
        }
        displayer->setDigital(i);
        displayer->setPos(Config::NUMBERS_INIT_POS[i]);

        connect(this, SIGNAL(sgn_moneyChanged(int)),
                displayer, SLOT(slt_moneyChanged(int)));

        m_scene->addItem(displayer);
    }

}

void Insaniquarium::alienAttack()
{
    int alienIndex = RandomMaker::creatRandom(Config::ALIENS_NAME.size());
    m_alienName = Config::ALIENS_NAME[alienIndex];
    if (m_alienName != "gus"){
        m_feedable = false;
    }
    m_alienAttack = true;
    QPointF initPos = RandomMaker::createRandomPoint(0, Config::SCREEN_WIDTH,
                                                     Config::POOL_UPPER_BOUND,
                                                     Config::POOL_LOWER_BOUND);

    AbstractAlien * alien = Factory::createAlien(m_alienName, initPos, m_scene);
    connect(alien, SIGNAL(sgn_alienDie()),
            this, SLOT(slt_attatckEnd()));
    connect(alien, SIGNAL(sgn_yieldMoney(QString,QPointF)),
            this, SLOT(slt_yieldMoney(QString,QPointF)));
    connect(this, SIGNAL(sgn_attackAlien(QPointF)),
            alien, SLOT(slt_attacked(QPointF)));
    m_scene->addItem(alien);
    emit sgn_alienComes(alien->name());
}

void Insaniquarium::gameOver()
{
    showRestartMenu();
}

void Insaniquarium::slt_start()
{
    m_scene->clear();
    setBackgroundBrush(m_bgGamePix);
    init();
}

void Insaniquarium::slt_choosePets()
{
    // FIXME
}

void Insaniquarium::slt_update()
{
    if (!m_gaming){
        return;
    }
    m_scene->advance();
    m_step++;
    if (m_step == 999999){
        m_step = 0;
    }
    if (m_step % 500 == 0){
        foreach (QGraphicsItem * item, m_scene->items()) {
            if (!item->isVisible()){
                m_scene->removeItem(item);
                delete item;
            }
        }
    }
    if (m_step % Config::ALIENS_ATTACK_BASE_STEP == 0){
        alienAttack();
    }
}

void Insaniquarium::slt_foodReduce()
{
    m_currentFoodCount--;
}

void Insaniquarium::slt_fishUpgrade(const QString & name, const QPointF & pos, const qreal dir)
{
    addFish(name, pos, dir);
}

void Insaniquarium::slt_moneyPicked(int value)
{
    m_money += value;
    if (m_money > 99999){
        m_money = 99999;
    }
    emit sgn_moneyChanged(m_money);
}

void Insaniquarium::slt_yieldFish(const QString & name, const QPointF & pos)
{
    addFish(name, pos);
}

void Insaniquarium::slt_yieldMoney(const QString & name, const QPointF & pos)
{
    addMoney(name, pos);
}

void Insaniquarium::slt_yieldFood(const QPointF & pos)
{
    QPointF foodPos;
    qreal deltaX = Config::FOODS_WIDTH / 2;
    qreal deltaY = Config::FOODS_HEIGHT / 2;
    foodPos.rx() = pos.x() - deltaX;
    foodPos.ry() = pos.y() - deltaY;
    addFood(foodPos);
}

void Insaniquarium::slt_attatckEnd()
{
    m_alienAttack = false;
    m_feedable = true;
    m_alienName = "";
    emit sgn_alienDies();
}

void Insaniquarium::slt_fishDie()
{
    m_fishCount--;
    if (m_fishCount == 0){
        m_timer->stop();
        m_gaming = false;
        gameOver();
    }
}

void Insaniquarium::slt_petSkill(const QString & name, const QPointF & pos)
{
    if (name == "vert"){
        addMoney("silver", pos);
    }
    else if (name == "prego"){
        addFish("smallGuppy", pos);
    }
    else if (name == "niko"){
        slt_moneyPicked(300);
    }
    else if (name == "meryl"){
        emit sgn_yieldMoney();
    }
}

void Insaniquarium::slt_btnClicked(const QString & btnName)
{
    if (m_money < Config::BTNS_COST[btnName]){
        return;
    }

    if (btnName == "startGameBtn"
            || btnName == "nextLevelBtn"
            || btnName == "restartBtn"){
        choosePets();
    }
    else if (btnName == "confirmBtn"){
        slt_start();
    }
    else if (btnName == "smallGuppyBtn"
             || btnName == "middleBreederBtn"
             || btnName == "carnivoreBtn"
             || btnName == "ulturavoreBtn"
             || btnName == "grubberBtn"
             || btnName == "gekkoBtn"){
        QString name = btnName.mid(0, btnName.size() - 3);
        int x = RandomMaker::creatRandom(Config::SCREEN_WIDTH * 0.2,
                                         Config::SCREEN_WIDTH * 0.8);
        int y = Config::POOL_UPPER_BOUND;
        slt_yieldFish(name, QPointF(x, y));
        m_money -= Config::BTNS_COST[btnName];
        emit sgn_moneyChanged(m_money);
    }
    else if (btnName == "foodUpgradeBtn"){
        if (m_foodLevel < m_maxFoodLevel){
            m_foodLevel++;
            m_money -= Config::BTNS_COST[btnName];
            emit sgn_moneyChanged(m_money);
        }
    }
    else if (btnName == "moreFoodBtn"){
        if (m_maxFoodCount < 6){
            m_maxFoodCount++;
            m_money -= Config::BTNS_COST[btnName];
            emit sgn_moneyChanged(m_money);
        }
    }
    else if (btnName == "eggBtn") {
        if (m_eggLevel < 2){
            m_eggLevel++;
            m_money -= Config::BTNS_COST[btnName];
            emit sgn_moneyChanged(m_money);
        } else {
            m_gameLevel++;
            showNextLevelMenu();
        }
    }
    else if (btnName == "stinkyBtn"
             || "vertBtn"
             || "clydeBtn"
             || "pregoBtn"
             || "nikoBtn"
             || "merylBtn"){
        if (m_chosenPets.size() < 3){
            addTick(btnName);
            QString pet = btnName.mid(0, btnName.size() - 3);
            m_chosenPets.insert(pet);
        }
    }
}
