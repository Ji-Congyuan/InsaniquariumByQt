#include "breeder.h"

Breeder::Breeder(qreal w, qreal h, const QPointF &pos,
                 const QPixmaps2 &pixs2, QGraphicsScene *scene,
                 QGraphicsItem *parent)
    : AbstractFish(w, h, pos, pixs2, scene, parent)
{
}

void Breeder::advance(int)
{
    AbstractFish::advance(0);
}

void Breeder::doCollide()
{
    if (!m_hasTarget){
        return;
    }
    foreach (QGraphicsItem * t, collidingItems()) {
        AbstractMovableItem * movableItem
                = dynamic_cast<AbstractMovableItem *> (t);
        if (Config::COLLIDABLE_ITEMS[name()]
                .contains(movableItem->name())){
            Food * food = dynamic_cast<Food *> (movableItem);
            eat(food->eatenExp());
            food->vanish();
        }
    }
}

void Breeder::findFood()
{
    QList<QGraphicsItem*> items_ = scene()->items();
    QList<AbstractMovableItem*> edibleItems;
    foreach (QGraphicsItem * item, items_) {
        AbstractGameItem * gameItem
                = dynamic_cast<AbstractGameItem *> (item);
        if (Config::COLLIDABLE_ITEMS[name()]
                .contains(gameItem->name())
                && gameItem->isVisible()){
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
