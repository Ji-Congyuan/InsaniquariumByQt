#ifndef ABSTRACTBTN_H
#define ABSTRACTBTN_H

#include "abstractgameitem.h"

class Btn : public AbstractGameItem
{
    Q_OBJECT
public:
    Btn(const QString & name,
        const QPointF & pos,
        qreal w, qreal h,
        const QPixmaps2 &pixs2,
        QGraphicsScene *scene,
        QGraphicsObject *parent = nullptr);
    ~Btn() {}

    // return the collide rect of the item
    QRectF boundingRect() const;

    // return the paint path of the pixmap
    QPainterPath shape() const;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    const QString & name() const;

    // control the pixmaps shown
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    // emit when button is released
    void sgn_btnReleased(const QString &);

public slots:
    // interact with main ctrler
    void slt_clickReceived(const QString &);

protected:
    // pixs list of the item
    QPixmaps2 m_pixs2;

    const QString m_name;
    int m_pixStateIndex;
};

#endif // ABSTRACTBTN_H
