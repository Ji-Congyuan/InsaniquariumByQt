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

// pool size
const int Config::POOL_UPPER_BOUND = 120;
const int Config::POOL_LOWER_BOUND = 660;

// fish size
const int Config::FISH_WIDTH  = 80;
const int Config::FISH_HEIGHT = 80;

// init counts
const int Config::INIT_FOODS_RESTRICT = 2;   // defualt 1
const int Config::INIT_FISH_COUNT     = 2;   // default 2
const int Config::INIT_HUNGRY         = 75;

// foods size
const int Config::FOODS_WIDTH  = 40;
const int Config::FOODS_HEIGHT = 40;

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

const int Config::FOOD_STATE_COUNT              = 5;
const int Config::FOOD_INDEX_COUNT              = 10;


// speed up
const qreal Config::HUNGRY_INCREASE = 1.5;

// sink speed
const int Config::BODY_SINK_SPEED   = 10;
const int Config::FOOD_SINK_SPEED   = 2;

// hungry threshold
const int Config::HUNGRY_THRESHOLD = 25;
const int Config::FULL_THRESHOLD   = 75;

// steps
const int Config::HUNGRY_STEP           = 15;
const int Config::YIELD_STEP            = 1000;
const int Config::UPDATE_PAINT_STEP     = 5;
const int Config::CHANGE_DIRECTION_STEP = 5;
const int Config::CHASE_STEP            = 2;
const int Config::FIND_FOOD_STEP        = 5;

// hash
const QHash<QString, int> Config::FISH_SPEED = {
    { "smallGuppy", 5 }
};

const QHash<QString, int> Config::FISH_PAINT_WIDTH = {
    { "smallGuppy", 40 }
};

const QHash<QString, int> Config::FISH_PAINT_HEIGHT = {
    { "smallGuppy", 40 }
};

const QHash<QString, QString> Config::FISH_PATH = {
    { "smallGuppy", ":/fish/images/fish/smallGuppy.png" }
};

const QHash<QString, int> Config::FOODS_INDEX = {
    { "smallFood", 0 },
    { "middleFood", 1 },
    { "bigFood", 2 },
    { "buttleFood", 3 },
    { "superFood", 4 }
};

const QHash<QString, int> Config::FOODS_PAINT_WIDTH = {
    { "smallFood", 16 }
};

const QHash<QString, int> Config::FOODS_PAINT_HEIGHT = {
    { "smallFood", 11 }
};

const QHash<QString, int> Config::FOODS_EXP = {
    { "smallFood", 10 },
    { "middleFood", 15 },
    { "bigFood", 20 },
    { "buttleFood", 25 },
    { "superFood", 30 }
};

const QHash<QString, int> Config::FISH_EXP = {
    { "smallGuppy", 10 }
};
