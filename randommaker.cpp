#include "randommaker.h"

RandomMaker::RandomMaker(QObject *parent)
    :QObject(parent)
{
}

int RandomMaker::creatRandom(int x)
{
    return qrand() % x;
}

int RandomMaker::creatRandom(int x, int y)
{
    return qrand() % (y - x) + x;
}


