#ifndef MONEYFACTORY_H
#define MONEYFACTORY_H

#include "silver.h"

class MoneyFactory
{
public:
    // pos is the point where the left top of image is
    static AbstractMoney * createMoney(const QString & name,
                               const QPointF & pos,
                               QGraphicsScene *scene);

private:
    explicit MoneyFactory(){}
};

#endif // MONEYFACTORY_H
