#ifndef MENUBTN_H
#define MENUBTN_H

#include "abstractbtn.h"

class MenuBtn : public AbstractBtn
{
    Q_OBJECT
public:
    MenuBtn(const QString & name,
            qreal pos_x, qreal pos_y,
            qreal w, qreal h,
            const QPixmaps &pixs,
            QGraphicsScene *scene,
            QGraphicsObject *parent = nullptr);
    ~MenuBtn() {}
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    const QString & name() const;
    void advance(int);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void sgn_startGame();

private:
    const QString m_name;
};

#endif // MENUBTN_H
