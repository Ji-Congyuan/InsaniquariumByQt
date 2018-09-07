#include "pixmapsmaker.h"


QPixmaps PixmapsMaker::createQPixmaps(const QPixmap & pix,
                                      int count)
{
    qreal width = pix.width() / count;
    qreal height = pix.height();
    QPixmaps pixs;
    for (int i = 0; i < count; ++i){
        QPixmap temp = pix.copy(i * width, 0,
                                width, height);
        pixs.append(temp);
    }
    return pixs;
}

QPixmaps2 PixmapsMaker::createQPixmaps(const QPixmap & pix,
                                      int count_x, int count_y)
{
    qreal width = pix.width() / count_x;
    qreal height = pix.height() / count_y;
    QPixmaps2 pixs2;
    for (int j = 0; j < count_y; ++j) {
        QPixmaps pixs;
        for (int i = 0; i < count_x; ++i) {
            QPixmap temp = pix.copy(i * width, j * height,
                                    width, height);
            pixs.append(temp);
        }
        pixs2.append(pixs);
    }
    return pixs2;
}

QPixmaps PixmapsMaker::createNumberPixs()
{
    QPixmaps pixs;
    for (int i = 0; i <=10; i++){
        QPixmap temp(Config::NUMBERS_PATH[i]);
        pixs.append(temp);
    }
    return pixs;
}
