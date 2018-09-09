#ifndef DEEPBLUE_H
#define DEEPBLUE_H

#include "abstractalien.h"

class DeepBlue : public AbstractAlien
{
    Q_OBJECT
public:
    DeepBlue(qreal w, qreal h, const QPointF &pos,
             const QPixmaps2 &pixs2, QGraphicsScene *scene,
             QGraphicsItem *parent = nullptr);
    ~DeepBlue(){}
    const QString & name() const;
    // void doCollide();
    void eat(const int);

protected:
    const QString m_name;
};

#endif // DEEPBLUE_H
