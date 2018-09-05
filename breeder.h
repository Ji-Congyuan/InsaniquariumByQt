#ifndef BREEDER_H
#define BREEDER_H

#include "abstractfish.h"
#include "food.h"

class Breeder : public AbstractFish
{
    Q_OBJECT
public:
    Breeder(qreal w, qreal h, const QPointF &pos,
            const QPixmaps2 &pixs2, QGraphicsScene *scene,
            QGraphicsItem *parent = nullptr);
    ~Breeder(){}
    void advance(int);
    void doCollide();
    void findFood();
};

#endif // BREEDER_H
