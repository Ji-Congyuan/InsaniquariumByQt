#ifndef CLYDE_H
#define CLYDE_H

#include "abstractpet.h"

class Clyde : public AbstractPet
{
    Q_OBJECT
public:
    Clyde(qreal w, qreal h, const QPointF &pos,
          const QPixmaps2 &pixs2, QGraphicsScene *scene,
          QGraphicsItem *parent = nullptr);
    ~Clyde(){}
    const QString & name() const;
    void move();
    void doCollide();
    void advance(int);
    void findTarget();
    void yield();

public slots:
    void slt_specialSkill();
    void slt_alienComes(const QString &);
    void slt_alienDies();

signals:
    void sgn_pickMoney(int);

protected:
    const QString m_name;
};

#endif // CLYDE_H
