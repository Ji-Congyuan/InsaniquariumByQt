#ifndef PSYCHOSQUID_H
#define PSYCHOSQUID_H

#include "abstractalien.h"
#include <QTimer>

class Psychosquid : public AbstractAlien
{
    Q_OBJECT
public:
    Psychosquid(qreal w, qreal h, const QPointF &pos,
                const QPixmaps2 &pixs2, QGraphicsScene *scene,
                QGraphicsItem *parent = nullptr);
    ~Psychosquid(){}
    const QString & name() const;
    void doCollide();
    void eat(const int);
    void findFood();
    void advance(int);

public slots:
    void slt_finishRecovering();
    void slt_attacked(const QPointF &);

protected:
    const QString m_name;
    bool m_recovering;
    bool m_firstRec;
    bool m_secRec;
    QTimer * m_timer;
};

#endif // PSYCHOSQUID_H
