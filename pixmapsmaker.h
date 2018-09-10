#ifndef PIXMAPSMAKER_H
#define PIXMAPSMAKER_H

#include "config.h"
#include <QPixmap>

class PixmapsMaker
{
public:
    // return QList<QPixmap>, contains series of pixmaps
    static QPixmaps createQPixmaps(const QPixmap & pix,
                                   int count);

    // return QList<QList<QPixmap>>, contains series of series of pixmaps
    static QPixmaps2 createQPixmaps(const QPixmap &pix,
                                   int count_x, int count_y);

    // return QList<QPixmap>, contains numbers used to display the count of money
    static QPixmaps createNumberPixs();

private:
    explicit PixmapsMaker() {}
};

#endif // PIXMAPSMAKER_H
