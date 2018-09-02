#ifndef SMALLGUPPY_H
#define SMALLGUPPY_H

#include "guppy.h"

class SmallGuppy : public Guppy
{
public:
    SmallGuppy(qreal w, qreal h, const QPointF &pos,
               const QPixmaps2 &pixs2, QGraphicsScene *scene,
               QGraphicsItem *parent = nullptr);
    ~SmallGuppy() {}
    const QString & name() const;
    void doCollide();
    void upgrade();
    void yield();
    void advance(int);

protected:
    const QString m_name;
};

#endif // SMALLGUPPY_H
