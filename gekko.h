#ifndef GEKKO_H
#define GEKKO_H

#include "abstractfish.h"

class Gekko : public AbstractFish
{
    Q_OBJECT
public:
    Gekko(qreal w, qreal h, const QPointF &pos,
          const QPixmaps2 &pixs2, QGraphicsScene *scene,
          QGraphicsItem *parent = nullptr);
    ~Gekko(){}
    void advance(int);
    void doCollide();
    void findFood();
    const QString & name() const;
    void upgrade();
    void yield();

protected:
    const QString m_name;
};

#endif // GEKKO_H
