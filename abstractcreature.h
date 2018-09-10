#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include "abstractmovableitem.h"

class AbstractCreature : public AbstractMovableItem
{
    Q_OBJECT
public:
    AbstractCreature(qreal w, qreal h, const QPointF &pos,
                     const QPixmaps2 &pixs2, QGraphicsScene *scene,
                     QGraphicsItem *parent = nullptr);
    ~AbstractCreature() {}
    void advance(int);

    // get exp to upgrade, being full
    virtual void eat(const int exp) = 0;

    // hungry to die
    virtual void die();

    virtual void findFood() = 0;
    void move();
    void keepInScene();

    // yield money, small fish or other things
    virtual void yield() = 0;

    void aimAt(AbstractMovableItem *target);

    bool isAlive();
    bool willDie();

signals:
    void sgn_fishUpgrade(const QString &, const QPointF &,
                         const qreal);
    void sgn_yieldMoney(const QString &, const QPointF &);
    void sgn_yieldFish(const QString &, const QPointF &);
    void sgn_yieldFood(const QPointF &);

protected:
    bool m_alive;
    bool m_willDie;
};

#endif // ABSTRACTCREATURE_H
