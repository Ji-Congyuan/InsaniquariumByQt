#ifndef GUPPY_H
#define GUPPY_H

#include "abstractfish.h"

class Guppy : public AbstractFish
{
public:
    Guppy(qreal w, qreal h, const QPointF &pos,
          const QPixmaps2 &pixs2, QGraphicsScene *scene,
          QGraphicsItem *parent = nullptr);
    ~Guppy() {}
    // void yield();
    // void upgrade();
    void advance(int);

protected:
    bool m_upgradable;

};

#endif // GUPPY_H
