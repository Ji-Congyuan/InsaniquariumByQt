#include "abstractgameitem.h"

AbstractGameItem::AbstractGameItem(qreal w, qreal h,
                                   QGraphicsScene *scene,
                                   QGraphicsItem *parent)
    : QGraphicsObject(parent),
      m_step(0), m_w(w), m_h(h), m_pixIndex(0)
{
    scene->addItem(this);

    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::LeftButton);
}

qreal AbstractGameItem::width() const
{
    return m_w;
}

qreal AbstractGameItem::height() const
{
    return m_h;
}
