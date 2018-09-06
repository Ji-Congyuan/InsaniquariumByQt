#ifndef GOLD_H
#define GOLD_H

#include "abstractmoney.h"

class Gold : public AbstractMoney
{
public:
    Gold(qreal w, qreal h, const QPointF &pos,
         const QPixmaps2 &pixs2, QGraphicsScene *scene,
         QGraphicsItem *parent = nullptr);
    ~Gold(){}
    const QString & name() const;
    const int value() const;

protected:
    const int m_value;
    const QString m_name;
};

#endif // GOLD_H
