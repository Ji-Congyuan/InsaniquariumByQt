#ifndef ABSTRACTMOVABLEITEM_H
#define ABSTRACTMOVABLEITEM_H

#include "abstractgameitem.h"

class AbstractMovableItem : public AbstractGameItem
{
    Q_OBJECT
public:
    AbstractMovableItem(qreal w, qreal h, const QPointF &pos,
                        const QPixmaps2 &pixs2, QGraphicsScene *scene,
                        QGraphicsItem *parent = nullptr);
    ~AbstractMovableItem() {}
    virtual void doCollide() = 0;
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    // check if item in the view
    EDGE checkPos();
    void advance(int);
    // FIXME virtual void aimAt(QGraphicsObject *target);
    virtual void move();
    qreal speed() const;
    qreal direction() const;
    void setSpeed(const qreal speed);
    void setDirection(const qreal dir);
    qreal calDistance(QPointF &pos);
    bool left() const;
    bool right() const;
    bool turning() const;
    void toLeft();
    void toRight();
    void turning(const bool turn);
    void setPaintWidth(const qreal w);
    void setPaintHeight(const qreal h);
    qreal paintWidth() const;
    qreal paintHeight() const;
    void updateDirection();
    virtual void vanish();

protected:
    qreal m_speed;
    // rad
    qreal m_direction;

    QPixmaps2 m_pixs2;
    int m_pixStateIndex;

    bool m_hasTarget;
    QGraphicsObject * m_target;

    // distance to
    qreal m_distance;

    // control turning
    bool m_left;
    bool m_right;
    bool m_turning;

    // size to paint
    qreal m_paintWidth;
    qreal m_paintHeight;
};

#endif // ABSTRACTMOVABLEITEM_H
