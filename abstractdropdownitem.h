#ifndef ABSTRACTDROPDOWNITEM_H
#define ABSTRACTDROPDOWNITEM_H

#include "abstractmovableitem.h"

class AbstractDropdownItem : public AbstractMovableItem
{
    Q_OBJECT
public:
    AbstractDropdownItem(qreal w, qreal h, const QPointF &pos,
                         const QPixmaps2 &pixs2, QGraphicsScene *scene,
                         QGraphicsItem *parent = nullptr);
    ~AbstractDropdownItem(){}
    void advance(int);
    void move();

};

#endif // ABSTRACTDROPDOWNITEM_H
