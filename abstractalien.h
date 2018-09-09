#ifndef ABSTRACTALIEN_H
#define ABSTRACTALIEN_H

#include "abstractcreature.h"
#include "abstractfish.h"

class AbstractAlien : public AbstractCreature
{
    Q_OBJECT
public:
    AbstractAlien(qreal w, qreal h, const QPointF &pos,
                  const QPixmaps2 &pixs2, QGraphicsScene *scene,
                  QGraphicsItem *parent = nullptr);
    ~AbstractAlien(){}

    void advance(int);
    void doCollide();
    virtual void eat(const int exp) = 0;
    void injured(const int deltaHealth);
    void move();
    void findFood();
    void die();
    void yield();

public slots:
    virtual void slt_attacked(const QPointF &);

signals:
    void sgn_alienDie();

protected:
    int m_health;
};

#endif // ABSTRACTALIEN_H
