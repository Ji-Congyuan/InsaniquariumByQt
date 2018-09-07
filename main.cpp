#include "insaniquarium.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char * argv[]){
    QApplication app(argc, argv);

    Insaniquarium insaniquarium;
    insaniquarium.showStartGameMenu();
    insaniquarium.show();

    return app.exec();
}
