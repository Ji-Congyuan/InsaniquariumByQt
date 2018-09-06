#include "treasure.h"

Treasure::Treasure(qreal w, qreal h, const QPointF &pos,
                   const QPixmaps2 &pixs2, QGraphicsScene *scene,
                   QGraphicsItem *parent)
    : AbstractMoney(w, h, pos, pixs2, scene, parent),
      m_name("treasure"),
      m_value(Config::MONEY_VALUE["treasure"])
{
}

const QString &Treasure::name() const
{
    return m_name;
}

const int Treasure::value() const
{
    return m_value;
}
