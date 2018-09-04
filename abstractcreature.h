#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include "abstractmovableitem.h"

class AbstractCreature : public AbstractMovableItem
{
    Q_OBJECT
public:
    AbstractCreature(qreal w, qreal h, const QPointF &pos,
                     const QPixmaps2 &pixs2, QGraphicsScene *scene,
                     QGraphicsItem *parent = nullptr);
    ~AbstractCreature() {}
    void advance(int);
    virtual void eat(const int exp) = 0;
    virtual void die();
    virtual void findFood() = 0;
    void move();
    void aimAt(AbstractMovableItem *target);
    bool isAlive();
    bool willDie();

protected:
    bool m_alive;
    bool m_willDie;
};

#endif // ABSTRACTCREATURE_H
