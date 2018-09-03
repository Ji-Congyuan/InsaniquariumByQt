#ifndef FOODFACTORY_H
#define FOODFACTORY_H

#include "food.h"

class FoodFactory
{
public:
    // pos is the point where the left top of image is
    static Food * createFood(const QString & name,
                             const QPointF & pos,
                             QGraphicsScene * scene);

private:
    explicit FoodFactory(){}
};

#endif // FOODFACTORY_H
