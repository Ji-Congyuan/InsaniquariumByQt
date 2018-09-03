#ifndef ABSTRACTFISH_H
#define ABSTRACTFISH_H

#include "abstractcreature.h"

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
    virtual void upgrade() = 0;
    virtual void gettingHungry();
    virtual void yield() = 0;
    bool isHungry();
    bool isFull();

protected:
    // hungry: 0 will die and 100 is full
    int m_hungry;
    // related to upgrade
    int m_exp;

};

#endif // ABSTRACTFISH_H
