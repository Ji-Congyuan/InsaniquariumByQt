#ifndef INSANIQUARIUM_H
#define INSANIQUARIUM_H

#include "pixmapsmaker.h"
#include "menubtn.h"
#include "fishfactory.h"
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QColor>
#include <QPixmap>
#include <QTime>
#include <QTimer>

class Insaniquarium : public QGraphicsView
{
    Q_OBJECT

public:
    Insaniquarium(QWidget *parent = nullptr);
    // show start menu
    void showMenu();

public slots:
    // game start
    void slt_start();
    // next level
    void slt_nextLevel(int);
    // game over
    void slt_gameOver();
    // update scene
    void slt_update();

signals:


private:
    QGraphicsScene *m_scene;
    // bg images
    QPixmap m_bgGamePix;
    QPixmap m_bgMenuPix;

    // btn images
    QPixmap m_startGameBtnPix;

    QTimer * m_timer;

};

#endif // INSANIQUARIUM_H
