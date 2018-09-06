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

signals:
    void sgn_specialSkill(const QString &);

public slots:
    virtual void slt_alienComes(const QString &) = 0;
    virtual void slt_alienDies() = 0;
    virtual void slt_specialSkill() = 0;
};

#endif // ABSTRACTPET_H
