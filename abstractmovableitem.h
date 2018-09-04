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
    virtual void doCollide() = 0;
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    // check if item in the view
    EDGE checkPos();
    void advance(int);
    virtual void aimAt(AbstractMovableItem *target);
    virtual void move();
    void updateDirection();
    virtual void vanish();
    QPointF centrePos();

    qreal calDistance(QPointF &pos);
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
    void sgn_deleting();

public slots:
    void slt_lostAim();

protected:
    qreal m_speed;
    // rad
    qreal m_direction;

    QPixmaps2 m_pixs2;
    int m_pixStateIndex;

    bool m_hasTarget;
    AbstractMovableItem * m_target;

    // distance to
    qreal m_distance;

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
