#ifndef MIDDLEGUPPY_H
#define MIDDLEGUPPY_H

#include "guppy.h"

class MiddleGuppy : public Guppy
{
public:
    MiddleGuppy(qreal w, qreal h, const QPointF &pos,
                const QPixmaps2 &pixs2, QGraphicsScene *scene,
                QGraphicsItem *parent = nullptr);
    ~MiddleGuppy(){}
    const QString & name() const;
    void doCollide();
    void upgrade();
    void yield();
    void advance(int);

protected:
    const QString m_name;
};

#endif // MIDDLEGUPPY_H
