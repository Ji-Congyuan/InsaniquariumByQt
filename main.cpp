#include "insaniquarium.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char * argv[]){
    QApplication app(argc, argv);

    Insaniquarium insaniquarium;
    insaniquarium.showMenu();
    insaniquarium.show();
/*
    qDebug() << RandomMaker::creatRandom(15);
    qDebug() << RandomMaker::creatRandom(15);
    qDebug() << RandomMaker::creatRandom(15);
    qDebug() << RandomMaker::creatRandom(15, 20);
    qDebug() << RandomMaker::creatRandom(15, 20);
    qDebug() << RandomMaker::creatRandom(15, 20);
*/
    return app.exec();
}
