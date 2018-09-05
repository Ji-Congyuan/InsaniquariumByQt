#ifndef CARNIVORE_H
#define CARNIVORE_H

#include "abstractfish.h"

class Carnivore : public AbstractFish
{
    Q_OBJECT
public:
    Carnivore(qreal w, qreal h, const QPointF &pos,
              const QPixmaps2 &pixs2, QGraphicsScene *scene,
              QGraphicsItem *parent = nullptr);
    ~Carnivore(){}
    void advance(int);
    void doCollide();
    void findFood();
    const QString & name() const;
    void upgrade();
    void yield();

protected:
    const QString m_name;
};

#endif // CARNIVORE_H
