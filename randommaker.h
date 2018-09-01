#ifndef RANDOMMAKER_H
#define RANDOMMAKER_H

#include <QObject>

class RandomMaker : public QObject
{
    Q_OBJECT
public:
    static int creatRandom(int x);
    static int creatRandom(int x, int y);
private:
    explicit RandomMaker(QObject *parent = nullptr);
};

#endif // RANDOMMAKER_H
