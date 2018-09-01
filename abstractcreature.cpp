#include "abstractcreature.h"

AbstractCreature::AbstractCreature(qreal blood, qreal w, qreal h, const QPointF &pos,
                                   qreal speed, const QPixmaps2 &pixs2,
                                   QGraphicsScene *scene, QGraphicsItem *parent)
    : AbstractMovableItem(w, h, pos, speed, pixs2, scene, parent), m_blood(blood)
{    
}

void AbstractCreature::die()
{
    setFlag(QGraphicsItem::ItemIsMovable, false);
    setVisible(false);
    deleteLater();
    // emit something
}
