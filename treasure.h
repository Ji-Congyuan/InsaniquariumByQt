#ifndef TREASURE_H
#define TREASURE_H

#include "abstractmoney.h"

class Treasure : public AbstractMoney
{
public:
    Treasure(qreal w, qreal h, const QPointF &pos,
             const QPixmaps2 &pixs2, QGraphicsScene *scene,
             QGraphicsItem *parent = nullptr);
    ~Treasure(){}
    const QString & name() const;
    const int value() const;

protected:
    const int m_value;
    const QString m_name;
};

#endif // TREASURE_H
