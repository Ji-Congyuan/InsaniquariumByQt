#ifndef ABSTRACTBTN_H
#define ABSTRACTBTN_H

#include "abstractgameitem.h"

class AbstractBtn : public AbstractGameItem
{
    Q_OBJECT
public:
    AbstractBtn(qreal w, qreal h,
                const QPixmaps &pixs,
                QGraphicsScene *scene,
                QGraphicsObject *parent = nullptr);
    ~AbstractBtn() {}

protected:
    // pixs list of the item
    QPixmaps m_pixs;
};

#endif // ABSTRACTBTN_H
