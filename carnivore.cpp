#include "carnivore.h"

Carnivore::Carnivore(qreal w, qreal h, const QPointF &pos,
                     const QPixmaps2 &pixs2, QGraphicsScene *scene,
                     QGraphicsItem *parent)
    : AbstractFish(w, h, pos, pixs2, scene, parent),
      m_name("carnivore")
{
}

void Carnivore::advance(int)
{
    if (!isVisible()){
        return;
    }
    AbstractFish::advance(0);
}

void Carnivore::doCollide()
{
    if (!m_hasTarget){
        return;
    }
    foreach (QGraphicsItem * t, collidingItems()) {
        AbstractMovableItem * movableItem
                = dynamic_cast<AbstractMovableItem *> (t);
        if (Config::COLLIDABLE_ITEMS[name()]
                .contains(movableItem->name())){
            AbstractFish * fish = dynamic_cast<AbstractFish *> (movableItem);
            eat(fish->eatenExp());
            fish->vanish();
        }
    }
}

void Carnivore::findFood()
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

const QString &Carnivore::name() const
{
    return m_name;
}

void Carnivore::upgrade()
{
    // do nothing
}

void Carnivore::yield()
{
    emit sgn_yieldMoney("diamond", scenePos());
}
