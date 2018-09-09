#include "gus.h"
#include <QDebug>

Gus::Gus(qreal w, qreal h, const QPointF &pos,
         const QPixmaps2 &pixs2, QGraphicsScene *scene,
         QGraphicsItem *parent)
    : AbstractAlien(w, h, pos, pixs2, scene, parent),
      m_name("gus")
{
    m_health = Config::ALIENS_MAX_HEALTH["deepBlue"];
}

const QString &Gus::name() const
{
    return m_name;
}

void Gus::doCollide()
{
    foreach (QGraphicsItem * t, collidingItems()){
        AbstractGameItem * gameItem
                = dynamic_cast<AbstractGameItem *> (t);
        if (Config::COLLIDABLE_ITEMS[name()]
                .contains(gameItem->name())){
            if (!gameItem->isVisible()){
                continue;
            }
            AbstractMovableItem * movableItem
                    = dynamic_cast<AbstractMovableItem *> (gameItem);
            eat(movableItem->eatenExp());
            movableItem->vanish();
        }
    }
}

void Gus::eat(const int deltaHealth)
{
    injured(deltaHealth);
}
