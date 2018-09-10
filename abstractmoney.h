#ifndef MONEY_H
#define MONEY_H

#include "abstractdropdownitem.h"

class AbstractMoney : public AbstractDropdownItem
{
    Q_OBJECT
public:
    AbstractMoney(qreal w, qreal h, const QPointF &pos,
          const QPixmaps2 &pixs2, QGraphicsScene *scene,
          QGraphicsItem *parent = nullptr);
    ~AbstractMoney(){}

    // return the value of the money
    virtual const int value() const = 0;

    // pick money
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * event);

signals:
    void sgn_moneyPicked(int);
};

#endif // MONEY_H
