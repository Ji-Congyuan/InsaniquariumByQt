#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include "abstractmovableitem.h"

class AbstractCreature : public AbstractMovableItem
{
public:
    AbstractCreature(qreal w, qreal h, const QPointF &pos,
                     const QPixmaps2 &pixs2, QGraphicsScene *scene,
                     QGraphicsItem *parent = nullptr);
    ~AbstractCreature() {}
    // FIXME virtual void eat(Food *);
    virtual void die();
    // FIXME virtual void findFood();
    void move();
    bool isAlive();

protected:
    bool m_alive;
};

#endif // ABSTRACTCREATURE_H
