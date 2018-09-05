#ifndef ULTURAVORE_H
#define ULTURAVORE_H

#include "abstractfish.h"

class Ulturavore : public AbstractFish
{
    Q_OBJECT
public:
    Ulturavore(qreal w, qreal h, const QPointF &pos,
               const QPixmaps2 &pixs2, QGraphicsScene *scene,
               QGraphicsItem *parent = nullptr);
    ~Ulturavore(){}
    void advance(int);
    void doCollide();
    void findFood();
    const QString & name() const;
    void upgrade();
    void yield();

protected:
    const QString m_name;
};

#endif // ULTURAVORE_H
