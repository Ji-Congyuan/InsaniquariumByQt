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
    virtual void findTarget() = 0;
    void advance(int);
    virtual void yield() = 0;

signals:
    void sgn_specialSkill(const QString &, const QPointF &);

public slots:
    virtual void slt_alienComes(const QString &);
    virtual void slt_alienDies();
    virtual void slt_specialSkill();
};

#endif // ABSTRACTPET_H
