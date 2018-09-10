#ifndef FOOD_H
#define FOOD_H

#include "abstractdropdownitem.h"

class Food : public AbstractDropdownItem
{
    Q_OBJECT
public:
    Food(qreal w, qreal h, const QPointF &pos,
         const QPixmaps2 &pixs2, QGraphicsScene *scene,
         QGraphicsItem *parent = nullptr);
    ~Food(){}

    const QString & name() const;
    void advance(int);
    void vanish();
    void aimAt(QGraphicsObject *target);

signals:
    // emit when food is eaten or drop out of screen
    void sgn_foodWasted();

protected:
    const QString m_name;
};

#endif // FOOD_H
