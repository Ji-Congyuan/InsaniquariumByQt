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

    // backgrounds path
    static const QString BG_MENU_PATH;
    static const QString BG_GAME_PATH_1;

    // foods path
    static const QString FOODS_PATH;

    // money path
    static const QString MONEY_PATH;

    // pool size
    static const int POOL_UPPER_BOUND;
    static const int POOL_LOWER_BOUND;

    // fish size
    static const int FISH_WIDTH;
    static const int FISH_HEIGHT;
    static const int ULTURAVORE_WIDTH;
    static const int ULTURAVORE_HEIGHT;

    // aliens size
    static const int ALIENS_WIDTH;
    static const int ALIENS_HEIGHT;

    // foods size
    static const int FOODS_WIDTH;
    static const int FOODS_HEIGHT;

    // money size
    static const int MONEY_WIDTH;
    static const int MONEY_HEIGHT;

    // pets size
    static const int PETS_WIDTH;
    static const int PETS_HEIGHT;

    // tick size
    static const int TICK_WIDTH;
    static const int TICK_HEIGHT;

    // numbers size
    static const int NUMBERS_WIDTH;
    static const int NUMBERS_HEIGHT;

    // money display size
    static const int MONEY_DISPLAY_WIDTH;
    static const int MONEY_DISPLAY_HEIGHT;

    // init const
    static const int INIT_FOODS_RESTRICT;
    static const int INIT_FISH_COUNT;
    static const int INIT_HUNGRY;
    static const int INIT_MONEY;

    // pixs index
    static const int DEFAULT_BTN_INDEX;
    static const int HOVER_BTN_INDEX;
    static const int PRESSED_BTN_INDEX;
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

    static const int ALIEN_SWIM_LEFT_STATE_INDEX;
    static const int ALIEN_SWIM_RIGHT_STATE_INDEX;
    static const int ALIEN_TURN_LEFT_STATE_INDEX;
    static const int ALIEN_TURN_RIGHT_STATE_INDEX;

    static const int PETS_SWIM_LEFT_STATE_INDEX;
    static const int PETS_SWIM_RIGHT_STATE_INDEX;
    static const int PETS_TURN_LEFT_STATE_INDEX;
    static const int PETS_TURN_RIGHT_STATE_INDEX;
    static const int PETS_SPECIAL_LEFT_STATE_INDEX;
    static const int PETS_SPECIAL_RIGHT_STATE_INDEX;

    static const int FISH_STATE_COUNT;
    static const int FISH_INDEX_COUNT;

    static const int ALIEN_STATE_COUNT;
    static const int ALIEN_INDEX_COUNT;

    static const int FOOD_STATE_COUNT;
    static const int FOOD_INDEX_COUNT;

    static const int MONEY_STATE_COUNT;
    static const int MONEY_INDEX_COUNT;

    static const int PETS_STATE_COUNT;
    static const int PETS_INDEX_COUNT;

    static const int MORE_FOOD_STATE_COUNT;
    static const int EGG_STATE_COUNT;

    // speed up
    static const qreal HUNGRY_INCREASE;

    // sink speed
    static const int BODY_SINK_SPEED;
    static const int FOOD_SINK_SPEED;
    static const int MONEY_SINK_SPEED;

    // damage
    static const int ATTACK_ALIEN_DAMAGE;

    // steps
    static const int HUNGRY_STEP;
    static const int UPDATE_PAINT_STEP;
    static const int CHANGE_DIRECTION_STEP;
    static const int CHASE_STEP;
    static const int FIND_FOOD_STEP;
    static const int ALIENS_ATTACK_BASE_STEP;
    static const int FIND_TARGET_STEP;

    // hash
    static const QHash<QString, int> FISH_YIELD_STEP;
    static const QHash<QString, QString> FISH_PATH;
    static const QHash<QString, int> FISH_PAINT_WIDTH;
    static const QHash<QString, int> FISH_PAINT_HEIGHT;
    static const QHash<QString, int> FISH_SPEED;
    static const QHash<QString, int> FISH_EATEN_EXP;
    static const QHash<QString, int> FISH_UPGRADE_EXP;
    static const QHash<QString, int> FISH_INIT_HUNGRY;
    static const QHash<QString, int> FISH_MAX_HUNGRY;
    static const QHash<QString, int> FISH_HUNGRY_THRESHOLD;
    static const QHash<QString, int> FISH_FULL_THRESHOLD;

    static const QHash<QString, int> FOODS_INDEX;
    static const QHash<int, QString> FOODS_NAME;
    static const QHash<QString, int> FOODS_EXP;
    static const QHash<QString, int> FOODS_PAINT_WIDTH;
    static const QHash<QString, int> FOODS_PAINT_HEIGHT;

    static const QHash<QString, int> ALIENS_MAX_HEALTH;
    static const QHash<QString, QString> ALIENS_PATH;
    static const QHash<QString, int> ALIENS_PAINT_WIDTH;
    static const QHash<QString, int> ALIENS_PAINT_HEIGHT;
    static const QHash<QString, int> ALIENS_SPEED;
    static const QHash<int, QString> ALIENS_NAME;

    static const QHash<QString, int> MONEY_VALUE;
    static const QHash<QString, int> MONEY_INDEX;
    static const QHash<QString, int> MONEY_PAINT_WIDTH;
    static const QHash<QString, int> MONEY_PAINT_HEIGHT;

    static const QHash<QString, QString> PETS_PATH;
    static const QHash<QString, int> PETS_SPEED;
    static const QHash<QString, int> PETS_PAINT_WIDTH;
    static const QHash<QString, int> PETS_PAINT_HEIGHT;
    static const QHash<QString, int> PETS_INIT_POS_X;
    static const QHash<QString, int> PETS_INIT_POS_Y;

    static const QHash<QString, int> ORIGIN_IMAGE_ROWS;

    static const QHash<QString, QStringList> COLLIDABLE_ITEMS;

    static const QHash<QString, QString> BTNS_PATH;
    static const QHash<QString, int> BTNS_WIDTH;
    static const QHash<QString, int> BTNS_HEIGHT;
    static const QHash<QString, QPointF> BTNS_INIT_POS;

    static const QHash<QString, int> BTNS_COST;

    static const QHash<QString, QPointF> TICK_POS;

    static const QHash<QString, QString> LABELS_PATH;

    static const QHash<int, QString> NUMBERS_PATH;
    static const QHash<int, QPointF> NUMBERS_INIT_POS;

    // list
    static const QStringList FISH_TYPE;
    static const QStringList PETS_TYPE;
    static const QStringList MONEY_TYPE;
    static const QStringList GUPPY_TYPE;
    static const QStringList EDIBLE_TYPE;

private:
    explicit Config() {}
};

#endif // CONFIG_H
