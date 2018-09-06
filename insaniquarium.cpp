#include "insaniquarium.h"
#include "config.h"
#include <QDebug>

Insaniquarium::Insaniquarium(QWidget *parent)
    : QGraphicsView(parent),
      m_alienAttack(false), m_gaming(false),
      m_maxFoodCount(Config::INIT_FOODS_RESTRICT),
      m_currentFoodCount(0), m_alienName(""),
      m_maxFoodLevel(2), m_foodLevel(0),
      m_step(0), m_money(Config::INIT_MONEY),
      m_fishCount(0), m_gameLevel(0), m_eggLevel(0),
      m_feedable(true)
{
    // set screen sizes
    setFixedSize(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT);

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

    // !!! delete later !!!
    m_chosenPets.append("stinky");
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
    // FIXME
}

void Insaniquarium::showNextLevelMenu()
{
    m_timer->stop();
    m_gaming = false;
    QPixmap pix(Config::NEXT_LEVEL_LABEL);
    QGraphicsPixmapItem * pixmapItem = m_scene->addPixmap(pix);
    pixmapItem->setOffset(230, 0);
}

void Insaniquarium::init()
{
    // FIXME init consts
}

void Insaniquarium::mousePressEvent(QMouseEvent *event)
{
    if (m_gaming){
        if (event->button() == Qt::LeftButton){
            event->accept();
            if (m_feedable){ // feed fish
                if ((m_scene->items(event->pos())).size() == 0){ // if not press on other item
                    if (m_currentFoodCount < m_maxFoodCount){
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
    connect(pet, SIGNAL(sgn_specialSkill(QString)),
            this, SLOT(slt_petSkill(QString)));
    connect(this, SIGNAL(sgn_alienComes(QString)),
            pet, SLOT(slt_alienComes(QString)));
    connect(this, SIGNAL(sgn_alienDies()),
            pet, SLOT(slt_alienDies()));
    m_scene->addItem(pet);
}

void Insaniquarium::addBtn(const QString &name)
{
    Btn * btn = Factory::creatBtn(name, m_scene);

    connect(btn, SIGNAL(sgn_btnClicked(QString)),
            this, SLOT(slt_btnClicked(QString)));
    m_scene->addItem(btn);
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
}

void Insaniquarium::gameOver()
{
    qDebug() << "gameover";
}

void Insaniquarium::slt_start()
{
    m_scene->clear();
    setBackgroundBrush(m_bgGamePix);

    // init small Guppy
    for (int i = 0; i < Config::INIT_FISH_COUNT; i++){

        QPointF initPos = RandomMaker::createRandomPoint(0, Config::SCREEN_WIDTH,
                                                         Config::POOL_UPPER_BOUND,
                                                         Config::POOL_LOWER_BOUND);

        addFish("smallGuppy", initPos);
        QPointF initPos1 = RandomMaker::createRandomPoint(0, Config::SCREEN_WIDTH,
                                                         Config::POOL_UPPER_BOUND,
                                                         Config::POOL_LOWER_BOUND);

        addFish("carnivore", initPos1);
        QPointF initPos2 = RandomMaker::createRandomPoint(0, Config::SCREEN_WIDTH,
                                                         Config::POOL_UPPER_BOUND,
                                                         Config::POOL_LOWER_BOUND);

        addFish("ulturavore", initPos2);
        QPointF initPos3 = RandomMaker::createRandomPoint(0, Config::SCREEN_WIDTH,
                                                         Config::POOL_UPPER_BOUND,
                                                         Config::POOL_LOWER_BOUND);

        addFish("middleBreeder", initPos3);
    }

    // init pets
    foreach (QString petName, m_chosenPets) {
        int x = Config::PETS_INIT_POS_X[petName];
        int y = Config::PETS_INIT_POS_Y[petName];
        QPointF pos = QPointF(x, y);
        addPet(petName, pos);
    }

    // init buttons
    addBtn("guppyBtn");
    addBtn("breederBtn");
    addBtn("carnivoreBtn");
    addBtn("ulturavoreBtn");
    addBtn("moreFoodBtn");
    addBtn("foodUpgradeBtn");
    addBtn("eggBtn");

    m_timer->start(20);

    m_gaming = true;
}

void Insaniquarium::slt_nextLevel(int level)
{
    // FIXME
}

void Insaniquarium::slt_choosePets()
{
    // FIXME
}

void Insaniquarium::slt_update()
{
    m_scene->advance();
    m_step++;
    if (m_step == 999999){
        m_step = 0;
    }
    if (m_step % 100 == 0){
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
    qDebug() << "money: " << m_money;
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
    m_alienName = "";
    emit sgn_alienDies();
}

void Insaniquarium::slt_fishDie()
{
    m_fishCount--;
    if (m_fishCount == 0){
        gameOver();
    }
}

void Insaniquarium::slt_petSkill(const QString & name)
{
    // FIXME
}

void Insaniquarium::slt_btnClicked(const QString & btnName)
{
    if (m_money < Config::BTNS_COST[btnName]){
        return;
    }
    m_money -= Config::BTNS_COST[btnName];

    if (btnName == "startGameBtn"){
        slt_start();
    }
    else if (btnName == "guppyBtn"){
        int x = RandomMaker::creatRandom(Config::SCREEN_WIDTH * 0.2,
                                         Config::SCREEN_WIDTH * 0.8);
        int y = Config::POOL_UPPER_BOUND;
        slt_yieldFish("smallGuppy", QPointF(x, y));
    }
    else if (btnName == "breederBtn"){
        int x = RandomMaker::creatRandom(Config::SCREEN_WIDTH * 0.2,
                                         Config::SCREEN_WIDTH * 0.8);
        int y = Config::POOL_UPPER_BOUND;
        slt_yieldFish("middleBreeder", QPointF(x, y));
    }
    else if (btnName == "carnivoreBtn"){
        int x = RandomMaker::creatRandom(Config::SCREEN_WIDTH * 0.2,
                                         Config::SCREEN_WIDTH * 0.8);
        int y = Config::POOL_UPPER_BOUND;
        slt_yieldFish("carnivore", QPointF(x, y));
    }
    else if (btnName == "ulturavoreBtn"){
        int x = RandomMaker::creatRandom(Config::SCREEN_WIDTH * 0.2,
                                         Config::SCREEN_WIDTH * 0.8);
        int y = Config::POOL_UPPER_BOUND;
        slt_yieldFish("ulturavore", QPointF(x, y));
    }
    else if (btnName == "foodUpgradeBtn"){
        if (m_foodLevel < m_maxFoodLevel){
            m_foodLevel++;
        }
    }
    else if (btnName == "moreFoodBtn"){
        if (m_maxFoodCount < 6){
            m_maxFoodCount++;
        }
    }
    else if (btnName == "eggBtn") {
        if (m_eggLevel < 2){
            m_eggLevel++;
        } else {
            qDebug() << "next level";
            showNextLevelMenu();
        }
    }
}
