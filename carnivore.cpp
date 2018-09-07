#include "carnivore.h"

Carnivore::Carnivore(qreal w, qreal h, const QPointF &pos,
                     const QPixmaps2 &pixs2, QGraphicsScene *scene,
                     QGraphicsItem *parent)
    : AbstractFish(w, h, pos, pixs2, scene, parent),
      m_name("carnivore")
{
    m_hungry = Config::FISH_INIT_HUNGRY[m_name];
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
        AbstractGameItem * gameItem
                = dynamic_cast<AbstractGameItem *> (t);
        if (Config::COLLIDABLE_ITEMS[name()]
                .contains(gameItem->name())){
            AbstractFish * fish = dynamic_cast<AbstractFish *> (gameItem);
            eat(fish->eatenExp());
            fish->vanish();
        }
    }
}

void Carnivore::findFood()
{
    QList<QGraphicsItem*> items_ = scene()->items();
    QVector<AbstractMovableItem*> edibleItems;
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
