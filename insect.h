#ifndef INSECT_H
#define INSECT_H

#include "abstractmoney.h"

class Insect : public AbstractMoney
{
public:
    Insect(qreal w, qreal h, const QPointF &pos,
           const QPixmaps2 &pixs2, QGraphicsScene *scene,
           QGraphicsItem *parent = nullptr);
    ~Insect(){}
    const QString & name() const;
    const int value() const;

protected:
    const int m_value;
    const QString m_name;
};

#endif // INSECT_H
