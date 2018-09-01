#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include "abstractmovableitem.h"

class AbstractCreature : public AbstractMovableItem
{
public:
    AbstractCreature(qreal blood, qreal w, qreal h, const QPointF &pos,
                     qreal speed, const QPixmaps2 &pixs2, QGraphicsScene *scene,
                     QGraphicsItem *parent = nullptr);
    ~AbstractCreature() {}
    // virtual void eat(Food *) = 0;
    virtual void die();


protected:
    qreal m_blood;

};

#endif // ABSTRACTCREATURE_H
