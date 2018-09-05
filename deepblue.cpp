#include "deepblue.h"
#include <QDebug>

DeepBlue::DeepBlue(qreal w, qreal h, const QPointF &pos,
                   const QPixmaps2 &pixs2, QGraphicsScene *scene,
                   QGraphicsItem *parent)
    : AbstractAlien(w, h, pos, pixs2, scene, parent),
      m_name("deepBlue")
{
    m_health = Config::ALIENS_MAX_HEALTH["deepBlue"];
}

const QString &DeepBlue::name() const
{
    return m_name;
}

void DeepBlue::doCollide()
{
    foreach (QGraphicsItem * t, collidingItems()){
        AbstractMovableItem * movableItem
                = dynamic_cast<AbstractMovableItem *> (t);
        if (Config::COLLIDABLE_ITEMS[name()]
                .contains(movableItem->name())){
            AbstractFish * fish = dynamic_cast<AbstractFish *> (movableItem);
            eat(0);
            fish->vanish();
        }
    }
}

void DeepBlue::eat(const int)
{
    // do nothing
}

void DeepBlue::slt_attacked(const QPointF & pos)
{
    AbstractAlien::slt_attacked(pos);
    if (m_health <= 0){
        die();
    }
}
