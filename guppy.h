#ifndef GUPPY_H
#define GUPPY_H

#include "abstractfish.h"
#include "food.h"

class Guppy : public AbstractFish
{
    Q_OBJECT
public:
    Guppy(qreal w, qreal h, const QPointF &pos,
          const QPixmaps2 &pixs2, QGraphicsScene *scene,
          QGraphicsItem *parent = nullptr);
    ~Guppy() {}
    void advance(int);
    void doCollide();
    void findFood();

};

#endif // GUPPY_H
