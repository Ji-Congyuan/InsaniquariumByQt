#include "middleguppy.h"
#include <QDebug>

MiddleGuppy::MiddleGuppy(qreal w, qreal h, const QPointF &pos,
                         const QPixmaps2 &pixs2, QGraphicsScene *scene,
                         QGraphicsItem *parent)
    : Guppy(w, h, pos, pixs2, scene, parent),
      m_name("middleGuppy")
{
    m_hungry = Config::FISH_INIT_HUNGRY[m_name];
}

const QString &MiddleGuppy::name() const
{
    return m_name;
}

void MiddleGuppy::doCollide()
{
    Guppy::doCollide();
}

void MiddleGuppy::upgrade()
{
    emit sgn_fishUpgrade("bigGuppy", scenePos(), direction());
    vanish();
}

void MiddleGuppy::yield()
{
    emit sgn_yieldMoney("silver", scenePos());
}

void MiddleGuppy::advance(int)
{
    if (!isVisible())
    {
        return;
    }
    Guppy::advance(0);
}
