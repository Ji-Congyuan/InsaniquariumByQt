#ifndef ALIENFACTORY_H
#define ALIENFACTORY_H

#include "deepblue.h"
#include <QImage>

class AlienFactory
{
public:
    // pos is the point where the left top of image is
    static AbstractAlien * createAlien(const QString & name,
                                       const QPointF & pos,
                                       QGraphicsScene *scene);

private:
    explicit AlienFactory(){}
};

#endif // ALIENFACTORY_H
