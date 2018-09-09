#include "insect.h"

Insect::Insect(qreal w, qreal h, const QPointF &pos,
               const QPixmaps2 &pixs2, QGraphicsScene *scene,
               QGraphicsItem *parent)
    : AbstractMoney(w, h, pos, pixs2, scene, parent),
      m_name("insect"),
      m_value(Config::MONEY_VALUE["insect"])
{
}

const QString &Insect::name() const
{
    return m_name;
}

const int Insect::value() const
{
    return m_value;
}
