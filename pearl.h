#ifndef PEARL_H
#define PEARL_H

#include "abstractmoney.h"

class Pearl : public AbstractMoney
{
public:
    Pearl(qreal w, qreal h, const QPointF &pos,
          const QPixmaps2 &pixs2, QGraphicsScene *scene,
          QGraphicsItem *parent = nullptr);
    ~Pearl(){}
    const QString & name() const;
    const int value() const;

protected:
    const int m_value;
    const QString m_name;
};

#endif // PEARL_H
