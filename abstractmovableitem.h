#ifndef ABSTRACTMOVABLEITEM_H
#define ABSTRACTMOVABLEITEM_H

#include "abstractgameitem.h"
#include <QObject>

class AbstractMovableItem : public AbstractGameItem
{
    Q_OBJECT
public:
    AbstractMovableItem(qreal w, qreal h, const QPointF &pos,
                        const QPixmaps2 &pixs2, QGraphicsScene *scene,
                        QGraphicsItem *parent = nullptr);
    ~AbstractMovableItem() {}

    // deal with collide event,
    // include eat food, pick money, etc
    virtual void doCollide() = 0;

    // return collision size of the item
    QRectF boundingRect() const;

    // return the paint path of the item
    QPainterPath shape() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    // check if item in the view
    EDGE checkPos();

    // control the animation
    void advance(int);

    // towards the target
    virtual void aimAt(AbstractMovableItem *target);

    virtual void move();

    // change m_left, m_right corresponding to direction
    virtual void updateDirection();

    // vanish after eaten / die / drop out of screen
    virtual void vanish();

    // return the centre pos of the pixmap
    QPointF centrePos();

    // keep the item in the screen
    virtual void keepInScene();

    qreal speed() const;
    qreal direction() const;
    void setSpeed(const qreal speed);
    void setDirection(const qreal dir);
    bool left() const;
    bool right() const;
    bool turning() const;
    void toLeft();
    void toRight();
    void turning(const bool turn);
    void setPaintWidth(const qreal w);
    void setPaintHeight(const qreal h);
    void setState(const int state);
    qreal paintWidth() const;
    qreal paintHeight() const;
    void setEatenExp(const int e);
    int eatenExp() const;


signals:
    // emit when deleted
    void sgn_deleting();

public slots:
    // the target deleted
    void slt_lostAim();

protected:
    qreal m_speed;

    // rad
    qreal m_direction;

    QPixmaps2 m_pixs2;
    int m_pixStateIndex;

    bool m_hasTarget;
    AbstractMovableItem * m_target;

    // control turning
    bool m_left;
    bool m_right;
    bool m_turning;

    // size to paint
    qreal m_paintWidth;
    qreal m_paintHeight;

    int m_eatenExp;
};

#endif // ABSTRACTMOVABLEITEM_H
