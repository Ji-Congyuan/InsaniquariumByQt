#ifndef PIXMAPSMAKER_H
#define PIXMAPSMAKER_H

#include "config.h"
#include <QPixmap>

class PixmapsMaker
{
public:
    static QPixmaps createQPixmaps(const QPixmap & pix,
                                   int count);
    static QPixmaps2 createQPixmaps(const QPixmap &pix,
                                   int count_x, int count_y);
private:
    explicit PixmapsMaker() {}
};

#endif // PIXMAPSMAKER_H
