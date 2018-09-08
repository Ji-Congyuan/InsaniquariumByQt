#ifndef MERYL_H
#define MERYL_H

#include "abstractpet.h"

class Meryl : public AbstractPet
{
    Q_OBJECT
public:
    Meryl(qreal w, qreal h, const QPointF &pos,
          const QPixmaps2 &pixs2, QGraphicsScene *scene,
          QGraphicsItem *parent = nullptr);
    ~Meryl(){}
    const QString & name() const;
    void move();
    void doCollide();
    void advance(int);
    void findTarget();
    void yield();

protected:
    const QString m_name;
};

#endif // MERYL_H
