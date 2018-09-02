#include "randommaker.h"

RandomMaker::RandomMaker(QObject *parent)
    :QObject(parent)
{
}

int RandomMaker::creatRandom(const int x)
{
    return qrand() % x;
}

int RandomMaker::creatRandom(const int x, const int y)
{
    return qrand() % (y - x) + x;
}

QPointF RandomMaker::createRandomPoint(const int x_min, const int x_max, const int y_min, const int y_max)
{
    int pos_x = creatRandom(x_min, x_max);
    int pos_y = creatRandom(y_min, y_max);
    return QPointF(pos_x, pos_y);
}


