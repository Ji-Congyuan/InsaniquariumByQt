#ifndef GUS_H
#define GUS_H

#include "abstractalien.h"

class Gus : public AbstractAlien
{
    Q_OBJECT
public:
    Gus(qreal w, qreal h, const QPointF &pos,
        const QPixmaps2 &pixs2, QGraphicsScene *scene,
        QGraphicsItem *parent = nullptr);
    ~Gus(){}
    const QString & name() const;
    void doCollide();
    void eat(const int);

protected:
    const QString m_name;
};

#endif // GUS_H
