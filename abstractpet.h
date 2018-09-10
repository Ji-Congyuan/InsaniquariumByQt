#ifndef ABSTRACTPET_H
#define ABSTRACTPET_H

#include "abstractmovableitem.h"

class AbstractPet : public AbstractMovableItem
{
    Q_OBJECT
public:
    AbstractPet(qreal w, qreal h, const QPointF &pos,
                const QPixmaps2 &pixs2, QGraphicsScene *scene,
                QGraphicsItem *parent = nullptr);
    ~AbstractPet(){}

    // find target, such as money, food, etc
    virtual void findTarget() = 0;

    void advance(int);

    // yield money, or small Guppy, etc
    virtual void yield() = 0;

signals:
    // the special skill of the pet
    void sgn_specialSkill(const QString &, const QPointF &);

public slots:
    // special actions related to aliens
    virtual void slt_alienComes(const QString &);
    virtual void slt_alienDies();

    // the special skill of the pet
    virtual void slt_specialSkill();
};

#endif // ABSTRACTPET_H
