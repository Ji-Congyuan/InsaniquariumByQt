#include "food.h"

Food::Food(qreal w, qreal h, const QPointF &pos,
           const QPixmaps2 &pixs2, QGraphicsScene *scene,
           QGraphicsItem *parent)
    : AbstractDropdownItem(w, h, pos, pixs2, scene, parent),
      m_name("Food")
{

}

const QString &Food::name() const
{
    return m_name;
}

void Food::vanish()
{
    AbstractMovableItem::vanish();
    emit sgn_foodWasted();
}

void Food::doCollide()
{

}

void Food::aimAt(QGraphicsObject *target)
{

}

void Food::setExp(int exp)
{
    m_exp = exp;
}

int Food::exp() const
{
    return m_exp;
}
