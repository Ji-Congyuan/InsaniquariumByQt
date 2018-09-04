#include "abstractdropdownitem.h"
#include <QDebug>

AbstractDropdownItem::AbstractDropdownItem(qreal w, qreal h, const QPointF &pos,
                                           const QPixmaps2 &pixs2, QGraphicsScene *scene,
                                           QGraphicsItem *parent)
    : AbstractMovableItem(w, h, pos, pixs2, scene, parent)
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
        // qDebug() << scenePos();
    }
}

void AbstractDropdownItem::move()
{
    AbstractMovableItem::move();
    if (checkPos() == DOWNEDGE){
        vanish();
    }
}
