#include "food.h"
#include <QDebug>

Food::Food(qreal w, qreal h, const QPointF &pos,
           const QPixmaps2 &pixs2, QGraphicsScene *scene,
           QGraphicsItem *parent)
    : AbstractDropdownItem(w, h, pos, pixs2, scene, parent),
      m_name("food")
{

}

const QString &Food::name() const
{
    return m_name;
}

void Food::advance(int)
{
    if (!isVisible())
    {
        return;
    }
    AbstractDropdownItem::advance(0);
}

void Food::vanish()
{
    emit sgn_foodWasted();
    AbstractMovableItem::vanish(); 
}

void Food::doCollide()
{

}

void Food::aimAt(QGraphicsObject *target)
{
    Q_UNUSED(target);
}
