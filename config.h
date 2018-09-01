#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
#include <QList>

typedef QList<QPixmap> QPixmaps;
typedef QList<QPixmaps> QPixmaps2;
typedef enum { INSIDE, UP, DOWN, LEFT, RIGHT } EDGE;

class Config
{
public:
    // screen size config
    static const qreal SCALE_RATIO;
    static const int SCREEN_WIDTH;
    static const int SCREEN_HEIGHT;

    // icons size config
    static const int MENU_BTN_WIDTH;
    static const int MENU_BTN_HEIGHT;
    static const int MENU_BTN_COUNT;

    // backgrounds path
    static const QString BG_MENU_PATH;
    static const QString BG_GAME_PATH_1;

    // buttons path
    static const QString BTN_STARTGAME;

    // ground height
    static const int GROUND_HEIGHT;

private:
    explicit Config() {}
};

#endif // CONFIG_H
