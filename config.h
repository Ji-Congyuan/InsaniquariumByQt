#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
#include <QList>
#include <QHash>

typedef QList<QPixmap> QPixmaps;
typedef QList<QPixmaps> QPixmaps2;
typedef enum { INSIDE, UPEDGE, DOWNEDGE, LEFTEDGE, RIGHTEDGE } EDGE;

class Config
{
public:
    // math const
    static const qreal PI;

    // screen size config
    static const qreal SCALE_RATIO;
    static const int SCREEN_WIDTH;
    static const int SCREEN_HEIGHT;

    // icons size config
    static const int MENU_BTN_WIDTH;
    static const int MENU_BTN_HEIGHT;

    // backgrounds path
    static const QString BG_MENU_PATH;
    static const QString BG_GAME_PATH_1;

    // buttons path
    static const QString BTN_STARTGAME;

    // fish path
    static const QString SMALL_GUPPY_PATH;

    // pool size
    static const int POOL_UPPER_BOUND;
    static const int POOL_LOWER_BOUND;

    // fish size
    static const int SMALL_GUPPY_WIDTH;
    static const int SMALL_GUPPY_HEIGHT;

    // pixs index
    static const int DEFAULT_MENU_BTN_INDEX;
    static const int HOVER_MENU_BTN_INDEX;
    static const int PRESSED_MENU_BTN_INDEX;
    static const int MENU_BTN_COUNT;

    static const int NORMAL_SWIM_LEFT_STATE_INDEX;
    static const int NORMAL_SWIM_RIGHT_STATE_INDEX;
    static const int NORMAL_TURN_LEFT_STATE_INDEX;
    static const int NORMAL_TURN_RIGHT_STATE_INDEX;
    static const int HUNGRY_SWIM_LEFT_STATE_INDEX;
    static const int HUNGRY_SWIM_RIGHT_STATE_INDEX;
    static const int HUNGRY_TURN_LEFT_STATE_INDEX;
    static const int HUNGRY_TURN_RIGHT_STATE_INDEX;
    static const int DIE_LEFT_STATE_INDEX;
    static const int DIE_RIGHT_STATE_INDEX;

    static const int STATE_COUNT;
    static const int FISH_INDEX_COUNT;

    // fish speed
    static const qreal HUNGRY_INCREASE;
    static const int SINK_SPEED;

    static const int GUPPY_SPEED;

    // hungry threshold
    static const int HUNGRY_THRESHOLD;

    // steps
    static const int HUNGRY_STEP;
    static const int YIELD_STEP;
    static const int MOVE_STEP;
    static const int CHANGE_DIRECTION_STEP;


    // hash
    static const QHash<QString, QString> FISH_PATH;
    static const QHash<QString, int> FISH_WIDTH;
    static const QHash<QString, int> FISH_HEIGHT;
    static const QHash<QString, int> FISH_SPEED;


private:
    explicit Config() {}
};

#endif // CONFIG_H
