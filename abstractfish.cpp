#include "abstractfish.h"
#include <QDebug>

AbstractFish::AbstractFish(qreal w, qreal h, const QPointF &pos,
                           const QPixmaps2 &pixs2,
                           QGraphicsScene *scene, QGraphicsItem *parent)
    : AbstractCreature(w, h, pos, pixs2, scene, parent),
      m_exp(0)
{
    m_timer = new QTimer;
    m_timer->setSingleShot(true);
    connect(m_timer, SIGNAL(timeout()),
            this, SIGNAL(sgn_die()));
}

AbstractFish::~AbstractFish()
{
    delete m_timer;
    m_timer = nullptr;
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
                if(isVisible()){
                    vanish();
                    return;
                }
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

    if (m_step % Config::FISH_YIELD_STEP[name()] == 0
            && isAlive()){
        yield();
    }
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
    m_hungry = Config::FISH_MAX_HUNGRY[name()];
    m_hasTarget = false;
    m_target = nullptr;
}

void AbstractFish::gettingHungry()
{
    m_hungry--;
    if (m_hungry == 0){
        die();
    }
}

void AbstractFish::vanish()
{
    AbstractMovableItem::vanish();
    m_timer->start(20);
}

bool AbstractFish::isHungry()
{
    return m_hungry <= Config::FISH_HUNGRY_THRESHOLD[name()];
}

bool AbstractFish::isFull()
{
    return m_hungry >= Config::FISH_FULL_THRESHOLD[name()];
}

void AbstractFish::slt_yieldMoney()
{
}
