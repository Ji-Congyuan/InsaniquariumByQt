#include "money.h"

Money::Money(qreal w, qreal h, const QPointF &pos,
             const QPixmaps2 &pixs2, QGraphicsScene *scene,
             QGraphicsItem *parent)
    : AbstractDropdownItem(w, h, pos, pixs2, scene, parent)
{
}

void Money::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        event->accept();
        emit sgn_moneyPicked(value());
        vanish();
    } else {
        event->ignore();
    }
}
