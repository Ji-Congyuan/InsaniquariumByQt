#ifndef ABSTRACTDROPDOWNITEM_H
#define ABSTRACTDROPDOWNITEM_H

#include "abstractmovableitem.h"
#include <QTimer>

class AbstractDropdownItem : public AbstractMovableItem
{
    Q_OBJECT
public:
    AbstractDropdownItem(qreal w, qreal h, const QPointF &pos,
                         const QPixmaps2 &pixs2, QGraphicsScene *scene,
                         QGraphicsItem *parent = nullptr);
    ~AbstractDropdownItem();

    void advance(int);
    void move();
    void doCollide();
    void keepInScene();

public slots:
    void slt_vanish();

protected:
    QTimer * m_timer;
    bool m_isDown;

};

#endif // ABSTRACTDROPDOWNITEM_H
