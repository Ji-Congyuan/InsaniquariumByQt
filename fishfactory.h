#ifndef FISHFACTORY_H
#define FISHFACTORY_H

#include "smallguppy.h"
#include <QImage>

class FishFactory
{
public:  
    // pos is the point where the left top of image is
    static AbstractFish * creatFish(const QString & name,
                                    const QPointF & pos,
                                    QGraphicsScene *scene);
private:
    explicit FishFactory(){}
};

#endif // FISHFACTORY_H
