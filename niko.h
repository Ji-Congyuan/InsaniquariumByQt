#ifndef NIKO_H
#define NIKO_H

#include "abstractpet.h"

class Niko : public AbstractPet
{
    Q_OBJECT
public:
    Niko(qreal w, qreal h, const QPointF &pos,
         const QPixmaps2 &pixs2, QGraphicsScene *scene,
         QGraphicsItem *parent = nullptr);
    ~Niko(){}
    const QString & name() const;
    void move();
    void doCollide();
    void advance(int);
    void findTarget();
    void yield();
    void mousePressEvent(QGraphicsSceneMouseEvent *);

protected:
    const QString m_name;
    bool m_mature;
    bool m_harvested;
    bool m_gainable;
};

#endif // NIKO_H
