#include "abstractcreature.h"
#include <QDebug>

AbstractCreature::AbstractCreature(qreal w, qreal h, const QPointF &pos,
                                   const QPixmaps2 &pixs2, QGraphicsScene *scene,
                                   QGraphicsItem *parent)
    : AbstractMovableItem(w, h, pos, pixs2, scene, parent),
      m_alive(true), m_willDie(false)
{
}

void AbstractCreature::advance(int)
{
    AbstractMovableItem::advance(0);
}

void AbstractCreature::die()
{
    m_alive = false;
    m_willDie = true;
}

void AbstractCreature::move()
{
    if (!m_hasTarget && !turning()){
        if (m_step % Config::CHANGE_DIRECTION_STEP == 0){
            setDirection(direction() + RandomMaker::creatRandom(-5, 6) / 40.0);
        }
    }
    else if (m_hasTarget){
        if (m_step % Config::CHASE_STEP == 0){
            aimAt(m_target);
        }
    }

    AbstractMovableItem::move();    
    keepInScene();
}

void AbstractCreature::keepInScene()
{
    AbstractMovableItem::keepInScene();
}

void AbstractCreature::aimAt(AbstractMovableItem *target)
{
    AbstractMovableItem::aimAt(target);
}

bool AbstractCreature::isAlive()
{
    return m_alive;
}

bool AbstractCreature::willDie()
{
    return m_willDie;
}

