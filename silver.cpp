#include "silver.h"

Silver::Silver(qreal w, qreal h, const QPointF &pos,
               const QPixmaps2 &pixs2, QGraphicsScene *scene,
               QGraphicsItem *parent)
    : AbstractMoney(w, h, pos, pixs2, scene, parent),
      m_name("silver"),
      m_value(Config::MONEY_VALUE["silver"])
{
}

const QString &Silver::name() const
{
    return m_name;
}

const int Silver::value() const
{
    return m_value;
}
