#include "abstractpet.h"

AbstractPet::AbstractPet(qreal w, qreal h, const QPointF &pos,
                         const QPixmaps2 &pixs2, QGraphicsScene *scene,
                         QGraphicsItem *parent)
    : AbstractMovableItem(w, h, pos, pixs2, scene, parent)
{
}

void AbstractPet::advance(int)
{
    AbstractMovableItem::advance(0);

    if (m_step % Config::UPDATE_PAINT_STEP == 0){ // update action, direction and pos
        updateDirection();

        m_pixIndex++;

        if (m_pixIndex == Config::PETS_INDEX_COUNT){
            m_pixIndex = 0;
            if (turning()){ // finish turning
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
}

void AbstractPet::slt_alienComes(const QString &)
{
    // do nothing
}

void AbstractPet::slt_alienDies()
{
    // do nothing
}

void AbstractPet::slt_specialSkill()
{
    // do nothing
}
