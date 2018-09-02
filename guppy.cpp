#include "guppy.h"

Guppy::Guppy(qreal w, qreal h, const QPointF &pos,
             const QPixmaps2 &pixs2, QGraphicsScene *scene,
             QGraphicsItem *parent)
    : AbstractFish(w, h, pos, pixs2, scene, parent)
{

}

void Guppy::advance(int)
{
    AbstractFish::advance(0);
}
