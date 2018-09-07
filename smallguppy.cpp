#include "smallguppy.h"
#include <QDebug>

SmallGuppy::SmallGuppy(qreal w, qreal h, const QPointF &pos,
                       const QPixmaps2 &pixs2, QGraphicsScene *scene,
                       QGraphicsItem *parent)
    : Guppy(w, h, pos, pixs2, scene, parent), m_name("smallGuppy")
{
    m_hungry = Config::FISH_INIT_HUNGRY[m_name];
}

const QString & SmallGuppy::name() const
{
    return m_name;
}

void SmallGuppy::doCollide()
{
    Guppy::doCollide();
}

void SmallGuppy::upgrade()
{
    emit sgn_fishUpgrade("middleGuppy", scenePos(), direction());
    vanish();
}

void SmallGuppy::yield()
{
    // do nothing
}

void SmallGuppy::advance(int)
{
    if (!isVisible())
    {
        return;
    }
    Guppy::advance(0);
}
