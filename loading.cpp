#include "loading.h"
#include "config.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QMovie>
#include <QLabel>
#include <QTime>

void Loading::loading()
{
    QDesktopWidget w;
    QMovie *movie;
    movie = new QMovie(Config::LOADING_PATH);
    QLabel *label = new QLabel;
    label->setWindowFlags(Qt::FramelessWindowHint);
    label->setStyleSheet("background:transparent");
    label->setMovie(movie);
    label->setScaledContents(true);
    label->setGeometry((w.width() - Config::LOADING_WIDth) / 2 ,
                       (w.height() - Config::LOADING_HEIGHT) / 2 ,
                       Config::LOADING_WIDth, Config::LOADING_HEIGHT);
    movie->start();
    label->show();
    QTime t;
    t.start();
    while (t.elapsed() < 2000){
        QApplication::processEvents();
    }
    label->close();
    delete movie;
    delete label;
}
