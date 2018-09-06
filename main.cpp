#include "insaniquarium.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char * argv[]){
    QApplication app(argc, argv);

    Insaniquarium insaniquarium;
    insaniquarium.showStartGameMenu();
    insaniquarium.show();

    /*
    qDebug() << atan2(1, 1) / Config::PI << "pi";
    qDebug() << atan2(-1, 1) / Config::PI << "pi";
    qDebug() << atan2(1, -1) / Config::PI << "pi";
    qDebug() << atan2(-1, -1) / Config::PI << "pi";
    */

    return app.exec();
}
