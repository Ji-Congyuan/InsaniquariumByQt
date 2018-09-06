#ifndef STINKY_H
#define STINKY_H

#include "abstractpet.h"
#include "abstractmoney.h"

class Stinky : public AbstractPet
{
    Q_OBJECT
public:
    Stinky(qreal w, qreal h, const QPointF &pos,
           const QPixmaps2 &pixs2, QGraphicsScene *scene,
           QGraphicsItem *parent = nullptr);
    ~Stinky(){}
    const QString & name() const;
    void move();
    void doCollide();
    void advance(int);
    void findTarget();

public slots:
    void slt_specialSkill();
    void slt_alienComes(const QString &);
    void slt_alienDies();

signals:
    void sgn_pickMoney(int);

protected:
    const QString m_name;
    bool m_hiding;

};

#endif // STINKY_H
