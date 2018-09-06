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
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    const QString & name() const;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void sgn_btnClicked(const QString &);

protected:
    // pixs list of the item
    QPixmaps2 m_pixs2;
    const QString m_name;
    int m_pixStateIndex;
};

#endif // ABSTRACTBTN_H
