#include "balrog.h"

Balrog::Balrog(qreal w, qreal h, const QPointF &pos,
               const QPixmaps2 &pixs2, QGraphicsScene *scene,
               QGraphicsItem *parent)
    : AbstractAlien(w, h, pos, pixs2, scene, parent),
      m_name("balrog")
{
    m_health = Config::ALIENS_MAX_HEALTH["balrog"];
}

const QString &Balrog::name() const
{
    return m_name;
}

void Balrog::eat(const int)
{
    // do nothing
}
