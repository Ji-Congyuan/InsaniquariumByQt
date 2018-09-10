#include "insaniquarium.h"
#include "loading.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char * argv[]){
    QApplication app(argc, argv);

    Loading::loading();

    Insaniquarium insaniquarium;
    insaniquarium.show();

    return app.exec();
}
