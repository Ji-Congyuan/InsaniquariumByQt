#ifndef ABSTRACTMOVABLEITEM_H
#define ABSTRACTMOVABLEITEM_H

#include "abstractgameitem.h"

class AbstractMovableItem : public AbstractGameItem
{
    Q_OBJECT
public:
    AbstractMovableItem(qreal w, qreal h, const QPointF &pos,
                        qreal speed, const QPixmaps2 &pixs2,
                        QGraphicsScene *scene, QGraphicsItem *parent = nullptr);
    ~AbstractMovableItem() {}
    virtual QString name() const = 0;
    virtual void doCollide() = 0;
    // check if item in the view
    EDGE checkPos();
    virtual void aimAt(QGraphicsObject *target) = 0;


protected:
    qreal m_speed;
    // rad
    qreal m_direction;
    QPixmaps2 m_pixs2;
    int m_pixStateIndex;
    QPointF m_pos;
    bool m_hasTarget;
    QGraphicsObject * m_target;
};

#endif // ABSTRACTMOVABLEITEM_H
