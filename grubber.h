#ifndef GRUBBER_H
#define GRUBBER_H

#include "abstractfish.h"

class Grubber : public AbstractFish
{
    Q_OBJECT
public:
    Grubber(qreal w, qreal h, const QPointF &pos,
            const QPixmaps2 &pixs2, QGraphicsScene *scene,
            QGraphicsItem *parent = nullptr);
    ~Grubber(){}
    void advance(int);
    void doCollide();
    void findFood();
    const QString & name() const;
    void upgrade();
    void yield();
    void move();

protected:
    const QString m_name;
    bool m_upping;
    bool m_downing;
};

#endif // GRUBBER_H
