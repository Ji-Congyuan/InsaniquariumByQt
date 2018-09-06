#include "ulturavore.h"

Ulturavore::Ulturavore(qreal w, qreal h, const QPointF &pos,
                       const QPixmaps2 &pixs2, QGraphicsScene *scene,
                       QGraphicsItem *parent)
    : AbstractFish(w, h, pos, pixs2, scene, parent),
      m_name("ulturavore")
{
    m_hungry = Config::FISH_INIT_HUNGRY[m_name];
}

void Ulturavore::advance(int)
{
    if (!isVisible()){
        return;
    }
    AbstractFish::advance(0);
}

void Ulturavore::doCollide()
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

void Ulturavore::findFood()
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

const QString &Ulturavore::name() const
{
    return m_name;
}

void Ulturavore::upgrade()
{
    // do nothing
}

void Ulturavore::yield()
{
    emit sgn_yieldMoney("treasure", scenePos());
}
