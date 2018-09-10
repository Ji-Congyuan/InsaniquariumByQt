#ifndef ABSTRACTFISH_H
#define ABSTRACTFISH_H

#include "abstractcreature.h"
#include <QSoundEffect>

class AbstractFish : public AbstractCreature
{
    Q_OBJECT
public:
    AbstractFish(qreal w, qreal h, const QPointF &pos,
                 const QPixmaps2 &pixs2, QGraphicsScene *scene,
                 QGraphicsItem *parent = nullptr);

    ~AbstractFish(){}
    void advance(int);
    void move();
    void eat(const int exp);
    virtual void upgrade() = 0;
    virtual void gettingHungry();
    void vanish();

    bool isHungry();
    bool isFull();

public slots:
    virtual void slt_yieldMoney();

signals:
    void sgn_die();

protected:
    // hungry: 0 will die and 100 is full
    int m_hungry;

    int m_exp;
    QTimer * m_timer;

    QSoundEffect * m_slurpSound;
};

#endif // ABSTRACTFISH_H
