#ifndef PREGO_H
#define PREGO_H

#include "abstractpet.h"

class Prego : public AbstractPet
{
    Q_OBJECT
public:
    Prego(qreal w, qreal h, const QPointF &pos,
          const QPixmaps2 &pixs2, QGraphicsScene *scene,
          QGraphicsItem *parent = nullptr);
    ~Prego(){}
    const QString & name() const;
    void move();
    void doCollide();
    void advance(int);
    void findTarget();
    void yield();

protected:
    const QString m_name;
};

#endif // PREGO_H
