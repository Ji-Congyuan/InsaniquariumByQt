#include "balrog.h"

Balrog::Balrog(qreal w, qreal h, const QPointF &pos,
               const QPixmaps2 &pixs2, QGraphicsScene *scene,
               QGraphicsItem *parent)
    : AbstractAlien(w, h, pos, pixs2, scene, parent),
      m_name("balrog")
{
    m_health = Config::ALIENS_MAX_HEALTH["balrog"];
}

const QString &Balrog::name() const
{
    return m_name;
}

/*
void Balrog::doCollide()
{
    foreach (QGraphicsItem * t, collidingItems()){
        AbstractGameItem * gameItem
                = dynamic_cast<AbstractMovableItem *> (t);
        if (Config::COLLIDABLE_ITEMS[name()]
                .contains(gameItem->name())){
            if (!gameItem->isVisible()){
                continue;
            }
            AbstractFish * fish = dynamic_cast<AbstractFish *> (gameItem);
            eat(0);
            fish->vanish();
        }
    }
}
*/

void Balrog::eat(const int)
{
    // do nothing
}
