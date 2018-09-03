#include "config.h"

// math const
const qreal Config::PI = 3.1415926;

// screen size config
const qreal Config::SCALE_RATIO = 1.5;
const int Config::SCREEN_WIDTH  = 960;
const int Config::SCREEN_HEIGHT = 720;

// icons size config
const int Config::MENU_BTN_WIDTH  = 288;
const int Config::MENU_BTN_HEIGHT = 33;

// background path
const QString Config::BG_MENU_PATH   = ":/backgrounds/images/backgrounds/aquarium3.png";
const QString Config::BG_GAME_PATH_1 = ":/backgrounds/images/backgrounds/aquarium1.png";

// buttons path
const QString Config::BTN_STARTGAME_PATH = ":/buttons/images/buttons/startGameBtn.png";

// foods path
const QString Config::FOODS_PATH = ":/foods/images/foods/food.png";

// fish path
const QString Config::SMALL_GUPPY_PATH = ":/fish/images/fish/smallGuppy.png";

// pool size
const int Config::POOL_UPPER_BOUND = 120;
const int Config::POOL_LOWER_BOUND = 660;

// fish size
const int Config::FISH_WIDTH  = 80;
const int Config::FISH_HEIGHT = 80;

// fish paint size
const int Config::SMALL_GUPPY_PAINT_WIDTH  = 40;
const int Config::SMALL_GUPPY_PAINT_HEIGHT = 40;

// foods size
const int Config::FOODS_WIDTH  = 40;
const int Config::FOODS_HEIGHT = 40;

// foods paint size
const int Config::SMALL_FOOD_PAINT_WIDTH  = 16;
const int Config::SMALL_FOOD_PAINT_HEIGHT = 11;

// pixs index
const int Config::DEFAULT_MENU_BTN_INDEX = 0;
const int Config::HOVER_MENU_BTN_INDEX   = 1;
const int Config::PRESSED_MENU_BTN_INDEX = 2;
const int Config::MENU_BTN_COUNT         = 3;

const int Config::NORMAL_SWIM_LEFT_STATE_INDEX  = 0;
const int Config::NORMAL_SWIM_RIGHT_STATE_INDEX = 1;
const int Config::NORMAL_TURN_LEFT_STATE_INDEX  = 2;
const int Config::NORMAL_TURN_RIGHT_STATE_INDEX = 3;
const int Config::HUNGRY_SWIM_LEFT_STATE_INDEX  = 4;
const int Config::HUNGRY_SWIM_RIGHT_STATE_INDEX = 5;
const int Config::HUNGRY_TURN_LEFT_STATE_INDEX  = 6;
const int Config::HUNGRY_TURN_RIGHT_STATE_INDEX = 7;
const int Config::DIE_LEFT_STATE_INDEX          = 8;
const int Config::DIE_RIGHT_STATE_INDEX         = 9;

const int Config::FISH_STATE_COUNT              = 10;
const int Config::FISH_INDEX_COUNT              = 10;

const int Config::SMALL_FOOD_INDEX              = 0;
const int Config::MIDDLE_FOOD_INDEX             = 1;
const int Config::BIG_FOOD_INDEX                = 2;
const int Config::BUTTLE_FOOD_INDEX             = 3;
const int Config::SUPER_FOOD_INDEX              = 4;

const int Config::FOOD_STATE_COUNT              = 5;
const int Config::FOOD_INDEX_COUNT              = 10;


// fish speed
const qreal Config::HUNGRY_INCREASE = 1.5;

const int Config::SINK_SPEED        = 2;

const int Config::GUPPY_SPEED       = 5;

// hungry threshold
const int Config::HUNGRY_THRESHOLD = 25;

// foods exp
const int Config::SMALL_FOOD_EXP  = 10;
const int Config::MIDDLE_FOOD_EXP = 15;
const int Config::BIG_FOOD_EXP    = 20;
const int Config::BUTTLE_FOOD_EXP = 25;
const int Config::SUPER_FOOD_EXP  = 30;

// steps
const int Config::HUNGRY_STEP           = 10;
const int Config::YIELD_STEP            = 20;
const int Config::UPDATE_PAINT_STEP     = 5;
const int Config::CHANGE_DIRECTION_STEP = 5;

// hash
const QHash<QString, int> Config::FISH_SPEED = {
    { "smallGuppy", Config::GUPPY_SPEED }
};

const QHash<QString, int> Config::FISH_PAINT_WIDTH = {
    { "smallGuppy", Config::SMALL_GUPPY_PAINT_WIDTH }
};

const QHash<QString, int> Config::FISH_PAINT_HEIGHT = {
    { "smallGuppy", Config::SMALL_GUPPY_PAINT_HEIGHT }
};

const QHash<QString, QString> Config::FISH_PATH = {
    { "smallGuppy", Config::SMALL_GUPPY_PATH }
};

const QHash<QString, int> Config::FOODS_INDEX = {
    { "smallFood", Config::SMALL_FOOD_INDEX },
    { "middleFood", Config::MIDDLE_FOOD_INDEX },
    { "bigFood", Config::BIG_FOOD_INDEX },
    { "buttleFood", Config::BUTTLE_FOOD_INDEX },
    { "superFood", Config::SUPER_FOOD_INDEX }
};

const QHash<QString, int> Config::FOODS_EXP = {
    { "smallFood", Config::SMALL_FOOD_EXP },
    { "middleFood", Config::MIDDLE_FOOD_EXP },
    { "bigFood", Config::BIG_FOOD_EXP },
    { "buttleFood", Config::BUTTLE_FOOD_EXP },
    { "superFood", Config::SUPER_FOOD_EXP }
};

const QHash<QString, int> Config::FOODS_PAINT_WIDTH = {
    { "smallFood", Config::SMALL_FOOD_PAINT_WIDTH }
};

const QHash<QString, int> Config::FOODS_PAINT_HEIGHT = {
    { "smallFood", Config::SMALL_FOOD_PAINT_HEIGHT }
};
