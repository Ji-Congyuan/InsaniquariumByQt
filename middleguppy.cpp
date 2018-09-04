#include "middleguppy.h"
#include <QDebug>

MiddleGuppy::MiddleGuppy(qreal w, qreal h, const QPointF &pos,
                         const QPixmaps2 &pixs2, QGraphicsScene *scene,
                         QGraphicsItem *parent)
    : Guppy(w, h, pos, pixs2, scene, parent), m_name("middleGuppy")
{

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
    // FIXME
}

void MiddleGuppy::yield()
{
    // FIXME
}

void MiddleGuppy::advance(int)
{
    if (!isVisible())
    {
        return;
    }
    Guppy::advance(0);
}
