#include "smallguppy.h"

SmallGuppy::SmallGuppy(qreal w, qreal h, const QPointF &pos,
                       const QPixmaps2 &pixs2, QGraphicsScene *scene,
                       QGraphicsItem *parent)
    : Guppy(w, h, pos, pixs2, scene, parent), m_name("smallGuppy")
{
    m_upgradable = true;
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
    // FIXME
}

void SmallGuppy::yield()
{
    // do nothing
}

void SmallGuppy::advance(int)
{
    Guppy::advance(0);
    // FIXME
}
