#include "abstractfish.h"
#include <QDebug>

AbstractFish::AbstractFish(qreal w, qreal h, const QPointF &pos,
                           const QPixmaps2 &pixs2,
                           QGraphicsScene *scene, QGraphicsItem *parent)
    : AbstractCreature(w, h, pos, pixs2, scene, parent),
      m_hungry(Config::INIT_HUNGRY), m_exp(0)
{
}

void AbstractFish::advance(int)
{
    AbstractCreature::advance(0);

    if (isHungry()){ // faster when hungry
        qreal speed = Config::FISH_SPEED[name()] * Config::HUNGRY_INCREASE;
        setSpeed(speed);
    } else {
        qreal speed = Config::FISH_SPEED[name()];
        setSpeed(speed);
    }

    if (m_step % Config::UPDATE_PAINT_STEP == 0){ // update action, direction and pos
        updateDirection();

        m_pixIndex++;

        if (m_pixIndex == Config::FISH_INDEX_COUNT){
            m_pixIndex = 0;            
            // vanish after sink
            if (!isAlive()){
                vanish();
                return;
            }
            // finish turning
            else if (turning()){
                turning(false);
            }
        }      
        if (willDie()){
            if (right()){
                m_pixStateIndex = Config::DIE_RIGHT_STATE_INDEX;
            }
            else if (left()){
                m_pixStateIndex = Config::DIE_LEFT_STATE_INDEX;
            }
            m_pixIndex = 0;
            m_willDie = false;
        }
        else if (turning() && isAlive()){
            if (right()){
                m_pixStateIndex = Config::NORMAL_TURN_RIGHT_STATE_INDEX;
            }
            else if (left()){
                m_pixStateIndex = Config::NORMAL_TURN_LEFT_STATE_INDEX;
            }
        }
        else if (isAlive()){
            if (left()){
                m_pixStateIndex = Config::NORMAL_SWIM_LEFT_STATE_INDEX;
            }
            else if (right()){
                m_pixStateIndex = Config::NORMAL_SWIM_RIGHT_STATE_INDEX;
            }
        }
        if (isAlive() && isHungry()){
            m_pixStateIndex += 4;
        }

        move();
    }

    if (m_step % Config::FIND_FOOD_STEP == 0
            && !m_hasTarget
            && !isFull()
            && isAlive()){
        findFood();
    }

    if (m_step % Config::HUNGRY_STEP == 0
            && isAlive()){
        gettingHungry();
    }

    // FIXME with other action

}

void AbstractFish::move()
{
    if (isAlive()){
        AbstractCreature::move();
    } else {
        QPointF pos = scenePos();
        pos.ry() += Config::BODY_SINK_SPEED;
        setPos(pos);
    }
}

void AbstractFish::eat(const int exp)
{
    m_exp += exp;

    if (m_exp >= Config::FISH_UPGRADE_EXP[name()]){
        upgrade();
    }

    m_hungry = 100;
}

void AbstractFish::gettingHungry()
{
    m_hungry--;
    if (m_hungry == 0){
        die();
    }
}

bool AbstractFish::isHungry()
{
    return m_hungry <= Config::HUNGRY_THRESHOLD;
}

bool AbstractFish::isFull()
{
    return m_hungry >= Config::FULL_THRESHOLD;
}
