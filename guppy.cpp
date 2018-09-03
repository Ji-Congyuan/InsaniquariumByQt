#include "guppy.h"
#include <QDebug>

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

void Guppy::findFood()
{
    QList<QGraphicsItem*> items_ = scene()->items();
    QList<AbstractMovableItem*> edibleItems;
    foreach (QGraphicsItem * item, items_) {
        AbstractGameItem * gameItem = dynamic_cast<AbstractGameItem *> (item);
        if (gameItem->name() == "food"){
            edibleItems.append(dynamic_cast<AbstractMovableItem *>(gameItem));
        }
    }
    if (edibleItems.size() > 0){
        m_target = edibleItems.at(RandomMaker::creatRandom(edibleItems.size()));
        m_hasTarget = true;

        connect(m_target, SIGNAL(sgn_deleting()),
                this, SLOT(slt_lostAim()));
    }
}
