#ifndef DIAMOND_H
#define DIAMOND_H

#include "abstractmoney.h"

class Diamond : public AbstractMoney
{
public:
    Diamond(qreal w, qreal h, const QPointF &pos,
            const QPixmaps2 &pixs2, QGraphicsScene *scene,
            QGraphicsItem *parent = nullptr);
    ~Diamond(){}
    const QString & name() const;
    const int value() const;

protected:
    int m_value;
    const QString m_name;
};

#endif // DIAMOND_H
