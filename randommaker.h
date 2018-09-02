#ifndef RANDOMMAKER_H
#define RANDOMMAKER_H

#include <QObject>
#include <QPointF>

class RandomMaker : public QObject
{
    Q_OBJECT
public:
    static int creatRandom(const int x);
    static int creatRandom(const int x, const int y);
    static QPointF createRandomPoint(const int x_min, const int x_max,
                                     const int y_min, const int y_max);
private:
    explicit RandomMaker(QObject *parent = nullptr);
};

#endif // RANDOMMAKER_H
