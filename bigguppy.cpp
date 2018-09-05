#include "bigguppy.h"

BigGuppy::BigGuppy(qreal w, qreal h, const QPointF &pos,
                   const QPixmaps2 &pixs2, QGraphicsScene *scene,
                   QGraphicsItem *parent)
    : Guppy(w, h, pos, pixs2, scene, parent),
      m_name("bigGuppy")
{

}

const QString &BigGuppy::name() const
{
    return m_name;
}

void BigGuppy::doCollide()
{
    Guppy::doCollide();
}

void BigGuppy::upgrade()
{
    emit sgn_fishUpgrade("kingGuppy", scenePos(), direction());
    vanish();
}

void BigGuppy::yield()
{
    emit sgn_yieldMoney("gold", scenePos());
}

void BigGuppy::advance(int)
{
    if (!isVisible())
    {
        return;
    }
    Guppy::advance(0);
}
