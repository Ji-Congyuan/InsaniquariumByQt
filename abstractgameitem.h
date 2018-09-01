#ifndef ABSTRACTGAMEITEM_H
#define ABSTRACTGAMEITEM_H

#include "config.h"
#include "randommaker.h"
#include <QWidget>
#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QPainterPath>
#include <QRectF>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>


class AbstractGameItem : public QGraphicsObject
{
    Q_OBJECT
public:
    AbstractGameItem(qreal w, qreal h,
                     QGraphicsScene *scene,
                     QGraphicsItem *parent = nullptr);
    virtual ~AbstractGameItem(){}
    virtual QString name() const = 0;

protected:
    uint m_step;
    // size of the item
    qreal m_w;
    qreal m_h;
    // index of the pixs
    int m_pixIndex;
};

#endif // ABSTRACTGAMEITEM_H
