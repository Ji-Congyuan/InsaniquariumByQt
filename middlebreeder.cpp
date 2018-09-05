#include "middlebreeder.h"

MiddleBreeder::MiddleBreeder(qreal w, qreal h, const QPointF &pos,
                             const QPixmaps2 &pixs2, QGraphicsScene *scene,
                             QGraphicsItem *parent)
    : Breeder(w, h, pos, pixs2, scene, parent),
      m_name("middleBreeder")
{
}

const QString &MiddleBreeder::name() const
{
    return m_name;
}

void MiddleBreeder::doCollide()
{
    Breeder::doCollide();
}

void MiddleBreeder::upgrade()
{
    emit sgn_fishUpgrade("bigBreeder", scenePos(), direction());
    vanish();
}

void MiddleBreeder::yield()
{
    emit sgn_yieldFish("smallGuppy", scenePos());
}

void MiddleBreeder::advance(int)
{
    if (!isVisible())
    {
        return;
    }
    Breeder::advance(0);
}
