#ifndef MONEYDISPLAY_H
#define MONEYDISPLAY_H

#include "abstractgameitem.h"

class MoneyDisplayer : public AbstractGameItem
{
    Q_OBJECT
public:
    MoneyDisplayer(QGraphicsScene *scene,
                   QGraphicsItem *parent = 0);
    ~MoneyDisplayer(){}
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = Q_NULLPTR);
    void setIndex(const int index);
    void setDigital(const int digital);
    const int digital() const;

    const QString & name() const;

public slots:
    void slt_moneyChanged(int);

protected:
    const QString m_name;
    int m_digital;
    QPixmaps m_pixs;
};

#endif // MONEYDISPLAY_H
