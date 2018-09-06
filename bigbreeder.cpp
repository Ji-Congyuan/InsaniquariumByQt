#include "bigbreeder.h"

BigBreeder::BigBreeder(qreal w, qreal h, const QPointF &pos,
                       const QPixmaps2 &pixs2, QGraphicsScene *scene,
                       QGraphicsItem *parent)
    : Breeder(w, h, pos, pixs2, scene, parent),
      m_name("bigBreeder")
{
    m_hungry = Config::FISH_INIT_HUNGRY[m_name];
}

const QString &BigBreeder::name() const
{
    return m_name;
}

void BigBreeder::doCollide()
{
    Breeder::doCollide();
}

void BigBreeder::upgrade()
{
    // do nothing
}

void BigBreeder::yield()
{
    emit sgn_yieldFish("smallGuppy", scenePos());
}

void BigBreeder::advance(int)
{
    if (!isVisible())
    {
        return;
    }
    Breeder::advance(0);
}
