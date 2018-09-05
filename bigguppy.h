#ifndef BIGGUPPY_H
#define BIGGUPPY_H

#include "guppy.h"

class BigGuppy : public Guppy
{
    Q_OBJECT
public:
    BigGuppy(qreal w, qreal h, const QPointF &pos,
             const QPixmaps2 &pixs2, QGraphicsScene *scene,
             QGraphicsItem *parent = nullptr);
    ~BigGuppy(){}
    const QString & name() const;
    void doCollide();
    void upgrade();
    void yield();
    void advance(int);

protected:
    const QString m_name;
};

#endif // BIGGUPPY_H
