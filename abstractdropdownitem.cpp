#include "abstractdropdownitem.h"
#include <QDebug>

AbstractDropdownItem::AbstractDropdownItem(qreal w, qreal h, const QPointF &pos,
                                           const QPixmaps2 &pixs2, QGraphicsScene *scene,
                                           QGraphicsItem *parent)
    : AbstractMovableItem(w, h, pos, pixs2, scene, parent), m_isDown(false)
{
    setDirection(Config::PI / 2);
}

void AbstractDropdownItem::advance(int)
{
    AbstractMovableItem::advance(0);
    if (m_step % Config::UPDATE_PAINT_STEP == 0){
        m_pixIndex++;

        if (m_pixIndex == Config::FOOD_INDEX_COUNT){
            m_pixIndex = 0;
        }

        move();
    }
}

void AbstractDropdownItem::move()
{
    AbstractMovableItem::move();
    if (checkPos() == DOWNEDGE && !m_isDown){
        m_isDown = true;
        m_timer = new QTimer;
        connect(m_timer, SIGNAL(timeout()),
                this, SLOT(slt_vanish()));
        m_timer->start(500);
        setSpeed(0);
    }
    else if (checkPos() == UPEDGE){
        vanish();
    }
}

void AbstractDropdownItem::doCollide()
{
    // do nothing
}

void AbstractDropdownItem::keepInScene()
{
    // do nothing
}

void AbstractDropdownItem::slt_vanish()
{
    vanish();
}
