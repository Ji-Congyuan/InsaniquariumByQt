#include "vert.h"

Vert::Vert(qreal w, qreal h, const QPointF &pos,
           const QPixmaps2 &pixs2, QGraphicsScene *scene,
           QGraphicsItem *parent)
    : AbstractPet(w, h, pos, pixs2, scene, parent),
      m_name("vert")
{
}

const QString &Vert::name() const
{
    return m_name;
}

void Vert::move()
{
    if (!turning()){
        if (m_step % Config::CHANGE_DIRECTION_STEP == 0){
            setDirection(direction() + RandomMaker::creatRandom(-5, 6) / 40.0);
        }
    }

    AbstractMovableItem::move();
    keepInScene();
}

void Vert::doCollide()
{
    // do nothing
}

void Vert::advance(int)
{
    AbstractMovableItem::advance(0);
    if (m_step % Config::UPDATE_PAINT_STEP == 0){
        updateDirection();
        m_pixIndex++;

        if (m_pixIndex == Config::PETS_INDEX_COUNT){
            m_pixIndex = 0;
            if (turning()){
                turning(false);
            }
        }

        if (turning()){
            if (right()){
                m_pixStateIndex = Config::PETS_TURN_RIGHT_STATE_INDEX;
            }
            else if (left()){
                m_pixStateIndex = Config::PETS_TURN_LEFT_STATE_INDEX;
            }
        } else {
            if (left()){
                m_pixStateIndex = Config::PETS_SWIM_LEFT_STATE_INDEX;
            }
            else if (right()){
                m_pixStateIndex = Config::PETS_SWIM_RIGHT_STATE_INDEX;
            }
        }

        move();
    }
    if (m_step % Config::PETS_YIELD_STEP["vert"] == 0){
        yield();
    }
}

void Vert::findTarget()
{
    // do nothing
}

void Vert::yield()
{
    emit sgn_specialSkill(m_name, scenePos());
}
