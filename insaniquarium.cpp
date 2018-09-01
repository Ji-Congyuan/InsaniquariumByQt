#include "insaniquarium.h"
#include "config.h"
#include <QDebug>

Insaniquarium::Insaniquarium(QWidget *parent)
    : QGraphicsView(parent)
{
    // set screen size
    setFixedSize(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT);

    // add scene
    m_scene = new QGraphicsScene;
    m_scene->setSceneRect(0, 0, Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT);
    setScene(m_scene);

    // cache
    setCacheMode(QGraphicsView::CacheBackground);

    // turn off scroll bar
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // load bg images
    m_bgMenuPix = QPixmap(Config::BG_MENU_PATH).scaled(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT,
                                                       Qt::KeepAspectRatioByExpanding);
    m_bgGamePix = QPixmap(Config::BG_GAME_PATH_1).scaled(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT,
                                                          Qt::KeepAspectRatioByExpanding);

    // load btn images
    m_startGameBtnPix = QPixmap(Config::BTN_STARTGAME);
    qreal width = m_startGameBtnPix.width();
    qreal height = m_startGameBtnPix.height();
    m_startGameBtnPix = m_startGameBtnPix.scaled(width * Config::SCALE_RATIO,
                                                 height * Config::SCALE_RATIO,
                                                 Qt::KeepAspectRatioByExpanding);

}

void Insaniquarium::showMenu()
{
    // set bg image
    setBackgroundBrush(m_bgMenuPix);

    // set start game btn
    QPixmaps startGameBtnPixs = PixmapsMaker::createQPixmaps(m_startGameBtnPix,
                                                             Config::MENU_BTN_COUNT);
    MenuBtn * startGameBtn = new MenuBtn("startGameBtn",
                                         (Config::SCREEN_WIDTH - Config::MENU_BTN_WIDTH) / 2.0,
                                         Config::SCREEN_HEIGHT * 2.0 / 3.0,
                                         Config::MENU_BTN_WIDTH,
                                         Config::MENU_BTN_HEIGHT,
                                         startGameBtnPixs,
                                         m_scene);
    qDebug() << startGameBtn->scenePos().rx();
    qDebug() << startGameBtn->pos();
    connect(startGameBtn, SIGNAL(sgn_startGame()),
            this, SLOT(slt_start()));


}

void Insaniquarium::slt_start()
{
    m_scene->clear();
    setBackgroundBrush(m_bgGamePix);
}

void Insaniquarium::slt_nextLevel(int level)
{

}

void Insaniquarium::slt_gameOver()
{

}
