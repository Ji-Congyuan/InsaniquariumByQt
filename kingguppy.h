#ifndef KINGGUPPY_H
#define KINGGUPPY_H

#include "guppy.h"
#include <QSoundEffect>

class KingGuppy : public Guppy
{
    Q_OBJECT
public:
    KingGuppy(qreal w, qreal h, const QPointF &pos,
              const QPixmaps2 &pixs2, QGraphicsScene *scene,
              QGraphicsItem *parent = nullptr);
    ~KingGuppy();
    const QString & name() const;
    void doCollide();
    void upgrade();
    void yield();
    void advance(int);

protected:
    const QString m_name; 
    QSoundEffect * m_bornSound;
};

#endif // KINGGUPPY_H
