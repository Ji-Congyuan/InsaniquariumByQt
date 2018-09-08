#ifndef VERT_H
#define VERT_H

#include "abstractpet.h"

class Vert : public AbstractPet
{
    Q_OBJECT
public:
    Vert(qreal w, qreal h, const QPointF &pos,
         const QPixmaps2 &pixs2, QGraphicsScene *scene,
         QGraphicsItem *parent = nullptr);
    ~Vert(){}
    const QString & name() const;
    void move();
    void doCollide();
    void advance(int);
    void findTarget();
    void yield();

public slots:
    void slt_specialSkill();
    void slt_alienComes(const QString &);
    void slt_alienDies();

signals:

protected:
    const QString m_name;
};

#endif // VERT_H
