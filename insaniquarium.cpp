#include "insaniquarium.h"
#include "config.h"
#include <QDebug>

Insaniquarium::Insaniquarium(QWidget *parent)
    : QGraphicsView(parent),
      m_alienAttack(false), m_gaming(false),
      m_maxFoodCount(Config::INIT_FOODS_RESTRICT),
      m_currentFoodCount(0), m_alienName(""),
      m_maxFoodLevel(4), m_foodLevel(0),
      m_step(0), m_money(Config::INIT_MONEY)
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

    // load btn images
    m_startGameBtnPix = QPixmap(Config::BTN_STARTGAME_PATH);
    qreal width = m_startGameBtnPix.width();
    qreal height = m_startGameBtnPix.height();
    m_startGameBtnPix = m_startGameBtnPix.scaled(width * Config::SCALE_RATIO,
                                                 height * Config::SCALE_RATIO,
                                                 Qt::KeepAspectRatioByExpanding);

    // set random seed
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
}

void Insaniquarium::showMenu()
{
    // set bg image
    setBackgroundBrush(m_bgMenuPix);

    // set start game btn
    QPixmaps startGameBtnPixs = PixmapsMaker::createQPixmaps(Config::BTN_STARTGAME_PATH,
                                                             Config::MENU_BTN_COUNT);
    MenuBtn * startGameBtn = new MenuBtn("startGameBtn",
                                         (Config::SCREEN_WIDTH - Config::MENU_BTN_WIDTH) / 2.0,
                                         Config::SCREEN_HEIGHT * 2.0 / 3.0,
                                         Config::MENU_BTN_WIDTH,
                                         Config::MENU_BTN_HEIGHT,
                                         startGameBtnPixs,
                                         m_scene);

    connect(startGameBtn, SIGNAL(sgn_startGame()),
            this, SLOT(slt_start()));


}

void Insaniquarium::mousePressEvent(QMouseEvent *event)
{
    if (m_gaming){
        if (event->button() == Qt::LeftButton){
            event->accept();
            if (!m_alienAttack){ // feed fish
                if ((m_scene->items(event->pos())).size() == 0){ // if not press on other item
                    if (m_currentFoodCount < m_maxFoodCount){
                        QPointF pos = event->pos();
                        QPointF foodPos;
                        qreal deltaX = Config::FOODS_WIDTH / 2;
                        qreal deltaY = Config::FOODS_HEIGHT / 2;
                        foodPos.rx() = pos.rx() - deltaX;
                        foodPos.ry() = pos.ry() - deltaY;
                        addFood(foodPos);
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
    Food * food = FoodFactory::createFood(Config::FOODS_NAME[m_foodLevel], pos, m_scene);
    connect(food, SIGNAL(sgn_foodWasted()), this, SLOT(slt_foodReduce()));
    m_scene->addItem(food);
    m_currentFoodCount++;
}

void Insaniquarium::addFish(const QString &name, const QPointF &pos)
{
    AbstractFish * fish = FishFactory::creatFish(name, pos, m_scene);
    connect(fish, SIGNAL(sgn_fishUpgrade(QString,QPointF,qreal)),
            this, SLOT(slt_fishUpgrade(QString,QPointF,qreal)));
    connect(fish, SIGNAL(sgn_yieldFish(QString,QPointF)),
            this, SLOT(slt_yieldFish(QString,QPointF)));
    connect(fish, SIGNAL(sgn_yieldMoney(QString,QPointF)),
            this, SLOT(slt_yieldMoney(QString,QPointF)));
    connect(fish, SIGNAL(sgn_yieldFood(QPointF)),
            this, SLOT(slt_yieldFood(QPointF)));
    m_scene->addItem(fish);
}

void Insaniquarium::addFish(const QString &name, const QPointF &pos, const qreal dir)
{
    AbstractFish * fish = FishFactory::creatFish(name, pos, m_scene);
    fish->setDirection(dir);
    connect(fish, SIGNAL(sgn_fishUpgrade(QString,QPointF,qreal)),
            this, SLOT(slt_fishUpgrade(QString,QPointF,qreal)));
    connect(fish, SIGNAL(sgn_yieldFish(QString,QPointF)),
            this, SLOT(slt_yieldFish(QString,QPointF)));
    connect(fish, SIGNAL(sgn_yieldMoney(QString,QPointF)),
            this, SLOT(slt_yieldMoney(QString,QPointF)));
    connect(fish, SIGNAL(sgn_yieldFood(QPointF)),
            this, SLOT(slt_yieldFood(QPointF)));
    m_scene->addItem(fish);
}

void Insaniquarium::addMoney(const QString &name, const QPointF &pos)
{
    AbstractMoney * money = MoneyFactory::createMoney(name, pos, m_scene);
    connect(money, SIGNAL(sgn_moneyPicked(int)),
            this, SLOT(slt_moneyPicked(int)));
    m_scene->addItem(money);
}

void Insaniquarium::alienAttack()
{
    int alienIndex = RandomMaker::creatRandom(Config::ALIENS_NAME.size());
    m_alienName = Config::ALIENS_NAME[alienIndex];
    m_alienAttack = true;
    QPointF initPos = RandomMaker::createRandomPoint(0, Config::SCREEN_WIDTH,
                                                     Config::POOL_UPPER_BOUND,
                                                     Config::POOL_LOWER_BOUND);

    AbstractAlien * alien = AlienFactory::createAlien(m_alienName, initPos, m_scene);
    connect(alien, SIGNAL(sgn_alienDie()),
            this, SLOT(slt_attatckEnd()));
    connect(alien, SIGNAL(sgn_yieldMoney(QString,QPointF)),
            this, SLOT(slt_yieldMoney(QString,QPointF)));
    connect(this, SIGNAL(sgn_attackAlien(QPointF)),
            alien, SLOT(slt_attacked(QPointF)));
    m_scene->addItem(alien);
}

void Insaniquarium::slt_start()
{
    m_scene->clear();
    setBackgroundBrush(m_bgGamePix);

    for (int i = 0; i < Config::INIT_FISH_COUNT; i++){ // init small Guppy

        QPointF initPos = RandomMaker::createRandomPoint(0, Config::SCREEN_WIDTH,
                                                         Config::POOL_UPPER_BOUND,
                                                         Config::POOL_LOWER_BOUND);

        addFish("smallGuppy", initPos);
    }

    m_timer->start(20);

    m_gaming = true;
}

void Insaniquarium::slt_nextLevel(int level)
{

}

void Insaniquarium::slt_gameOver()
{

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
}

void Insaniquarium::slt_yieldFish(const QString &, const QPointF &)
{

}

void Insaniquarium::slt_yieldMoney(const QString & name, const QPointF & pos)
{
    addMoney(name, pos);
}

void Insaniquarium::slt_yieldFood(const QPointF &)
{

}

void Insaniquarium::slt_attatckEnd()
{
    m_alienAttack = false;
    m_alienName = "";
}
