#ifndef RANDOMMAKER_H
#define RANDOMMAKER_H

#include <QObject>
#include <QPointF>

class RandomMaker : public QObject
{
    Q_OBJECT
public:
    // return an integer in range of [0, x)
    static int creatRandom(const int x);

    // return an integer in range of [x, y)
    static int creatRandom(const int x, const int y);

    // return a point in range of [x_min, x_max) * [y_min, y_max)
    static QPointF createRandomPoint(const int x_min, const int x_max,
                                     const int y_min, const int y_max);

private:
    explicit RandomMaker(QObject *parent = nullptr);
};

#endif // RANDOMMAKER_H
