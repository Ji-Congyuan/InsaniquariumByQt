#ifndef INSANIQUARIUM_H
#define INSANIQUARIUM_H

#include "pixmapsmaker.h"
#include "btn.h"
#include "factory.h"
#include "moneydisplayer.h"
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QColor>
#include <QPixmap>
#include <QTime>
#include <QTimer>
#include <QSet>
#include <QDesktopWidget>

class Insaniquarium : public QGraphicsView
{
    Q_OBJECT

public:
    Insaniquarium(QWidget *parent = nullptr);
    // show start menu
    void showStartGameMenu();
    void showRestartMenu();
    void showNextLevelMenu();
    void choosePets();
    void init();
    void mousePressEvent(QMouseEvent *event);
    // void paintEvent(QPaintEvent *event);
    void addFood(const QPointF &pos);
    void addFish(const QString &name, const QPointF &pos);
    void addFish(const QString & name, const QPointF &pos, const qreal dir);
    void addMoney(const QString & name, const QPointF &pos);
    void addPet(const QString & name, const QPointF &pos);
    void addBtn(const QString & name);
    void addTick(const QString & btn);
    void addDisplayer();
    void alienAttack();
    void gameOver();

public slots:
    void slt_start();
    void slt_choosePets();
    // update scene
    void slt_update();
    void slt_foodReduce();
    void slt_fishUpgrade(const QString &, const QPointF &, const qreal);
    void slt_moneyPicked(int);
    // yield
    void slt_yieldFish(const QString &, const QPointF &);
    void slt_yieldMoney(const QString &, const QPointF &);
    void slt_yieldFood(const QPointF &);
    // alien attack ends
    void slt_attatckEnd();
    void slt_fishDie();
    void slt_petSkill(const QString &, const QPointF &);
    void slt_btnClicked(const QString &);

signals:
    void sgn_attackAlien(const QPointF &);
    void sgn_alienComes(const QString &);
    void sgn_alienDies();
    void sgn_moneyChanged(const int);
    void sgn_yieldMoney();

private:
    QGraphicsScene *m_scene;
    // bg images
    QPixmap m_bgGamePix;
    QPixmap m_bgMenuPix;

    // QPixmap m_startGameBtnPix;

    int m_maxFoodCount;
    int m_currentFoodCount;

    int m_eggLevel;

    int m_fishCount;

    int m_foodLevel;
    int m_maxFoodLevel;

    int m_gameLevel;

    QTimer * m_timer;

    bool m_alienAttack;
    QString m_alienName;

    bool m_feedable;

    bool m_gaming;

    int m_step;

    int m_money;

    QSet<QString> m_chosenPets;
    QStringList m_availPets;

    // MoneyManager *m_manager;

};

#endif // INSANIQUARIUM_H
