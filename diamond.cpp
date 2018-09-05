#include "diamond.h"

Diamond::Diamond(qreal w, qreal h, const QPointF &pos,
                 const QPixmaps2 &pixs2, QGraphicsScene *scene,
                 QGraphicsItem *parent)
    : AbstractMoney(w, h, pos, pixs2, scene, parent),
      m_name("diamond"),
      m_value(Config::MONEY_VALUE["diamond"])
{
}

const QString &Diamond::name() const
{
    return m_name;
}

const int Diamond::value() const
{
    return m_value;
}
