#include "abstractfish.h"
#include <QDebug>

AbstractFish::AbstractFish(qreal w, qreal h, const QPointF &pos,
                           const QPixmaps2 &pixs2,
                           QGraphicsScene *scene, QGraphicsItem *parent)
    : AbstractCreature(w, h, pos, pixs2, scene, parent),
      m_hungry(100), m_exp(0)
{
}

void AbstractFish::advance(int)
{
    AbstractMovableItem::advance(0);

    if (m_step % Config::MOVE_STEP == 0){
        updateDirection();

        if (turning()){
            if (right()){
                m_pixStateIndex = Config::NORMAL_TURN_RIGHT_STATE_INDEX;
            }
            else if (left()){
                m_pixStateIndex = Config::NORMAL_TURN_LEFT_STATE_INDEX;
            }
        }
        else if (!isAlive()){
            if (right()){
                m_pixStateIndex = Config::DIE_RIGHT_STATE_INDEX;
            }
            else if (left()){
                m_pixStateIndex = Config::DIE_LEFT_STATE_INDEX;
            }
        }
        else {
            if (left()){
                m_pixStateIndex = Config::NORMAL_SWIM_LEFT_STATE_INDEX;
            }
            else if (right()){
                m_pixStateIndex = Config::NORMAL_SWIM_RIGHT_STATE_INDEX;
            }
        }
        if ( isAlive() && isHungry()){
            m_pixStateIndex += 4;
        }

        m_pixIndex++;
        if (m_pixIndex == Config::FISH_INDEX_COUNT){
            m_pixIndex = 0;
            // finish turning
            if (turning()){
                turning(false);
                if (left()){
                    toRight();
                }
                else if (right()){
                    toLeft();
                }
            }
            // vanish after sink
            else if (!isAlive()){
                vanish();
            }
        }

        move();
    }

}

void AbstractFish::move()
{
    if (isAlive()){
        AbstractCreature::move();
    } else {
        QPointF pos = scenePos();
        pos.ry() += Config::SINK_SPEED;
    }
}

void AbstractFish::gettingHungry()
{
    m_hungry--;
    if (m_hungry == 0){
        // FIXME die();
    }
}

bool AbstractFish::isHungry()
{
    return (m_hungry > Config::HUNGRY_THRESHOLD) ? false : true;
}

/*
int AbstractFish::blood() const
{
    return m_blood;
}

void AbstractFish::setMaxBlood(const int blood)
{
    m_blood = blood;
}
*/
