#ifndef MIDDLEBREEDER_H
#define MIDDLEBREEDER_H

#include "breeder.h"

class MiddleBreeder : public Breeder
{
    Q_OBJECT
public:
    MiddleBreeder(qreal w, qreal h, const QPointF &pos,
                  const QPixmaps2 &pixs2, QGraphicsScene *scene,
                  QGraphicsItem *parent = nullptr);
    ~MiddleBreeder(){}
    const QString & name() const;
    void doCollide();
    void upgrade();
    void yield();
    void advance(int);

protected:
    const QString m_name;
};

#endif // MIDDLEBREEDER_H
