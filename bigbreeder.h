#ifndef BIGBREEDER_H
#define BIGBREEDER_H

#include "breeder.h"

class BigBreeder : public Breeder
{
    Q_OBJECT
public:
    BigBreeder(qreal w, qreal h, const QPointF &pos,
               const QPixmaps2 &pixs2, QGraphicsScene *scene,
               QGraphicsItem *parent = nullptr);
    ~BigBreeder(){}
    const QString & name() const;
    void doCollide();
    void upgrade();
    void yield();
    void advance(int);

protected:
    const QString m_name;
};

#endif // BIGBREEDER_H
