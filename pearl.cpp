#include "pearl.h"

Pearl::Pearl(qreal w, qreal h, const QPointF &pos,
             const QPixmaps2 &pixs2, QGraphicsScene *scene,
             QGraphicsItem *parent)
    : AbstractMoney(w, h, pos, pixs2, scene, parent),
      m_name("pearl"),
      m_value(Config::MONEY_VALUE["pearl"])
{
}

const QString &Pearl::name() const
{
    return m_name;
}

const int Pearl::value() const
{
    return m_value;
}
