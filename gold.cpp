#include "gold.h"

Gold::Gold(qreal w, qreal h, const QPointF &pos,
           const QPixmaps2 &pixs2, QGraphicsScene *scene,
           QGraphicsItem *parent)
    : AbstractMoney(w, h, pos, pixs2, scene, parent),
      m_name("gold"),
      m_value(Config::MONEY_VALUE["gold"])
{
}

const QString &Gold::name() const
{
    return m_name;
}

const int Gold::value() const
{
    return m_value;
}
