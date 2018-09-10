#ifndef BALROG_H
#define BALROG_H

#include "abstractalien.h"

class Balrog : public AbstractAlien
{
    Q_OBJECT
public:
    Balrog(qreal w, qreal h, const QPointF &pos,
           const QPixmaps2 &pixs2, QGraphicsScene *scene,
           QGraphicsItem *parent = nullptr);
    ~Balrog(){}
    const QString & name() const;
    void eat(const int);

protected:
    const QString m_name;
};

#endif // BALROG_H
