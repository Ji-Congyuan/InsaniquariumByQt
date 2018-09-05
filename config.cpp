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

// money path
const QString Config::MONEY_PATH = ":/money/images/money/money.png";

// pool size
const int Config::POOL_UPPER_BOUND = 120;
const int Config::POOL_LOWER_BOUND = 660;

// fish size
const int Config::FISH_WIDTH  = 80;
const int Config::FISH_HEIGHT = 80;

// aliens size
const int Config::ALIENS_WIDTH  = 160;
const int Config::ALIENS_HEIGHT = 160;

// money size
const int Config::MONEY_WIDTH  = 72;
const int Config::MONEY_HEIGHT = 72;

// init const
const int Config::INIT_FOODS_RESTRICT = 2;   // defualt 1
const int Config::INIT_FISH_COUNT     = 1;   // default 2
const int Config::INIT_HUNGRY         = 75;
const int Config::INIT_MONEY          = 0;   // default 0

// foods size
const int Config::FOODS_WIDTH  = 40;
const int Config::FOODS_HEIGHT = 40;

// pets size
const int Config::PETS_WIDTH   = 80;
const int Config::PETS_HEIGHT  = 80;

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

const int Config::ALIEN_SWIM_LEFT_STATE_INDEX   = 0;
const int Config::ALIEN_SWIM_RIGHT_STATE_INDEX  = 1;
const int Config::ALIEN_TURN_LEFT_STATE_INDEX   = 2;
const int Config::ALIEN_TURN_RIGHT_STATE_INDEX  = 3;

const int Config::PETS_SWIM_LEFT_STATE_INDEX    = 0;
const int Config::PETS_SWIM_RIGHT_STATE_INDEX   = 1;
const int Config::PETS_TURN_LEFT_STATE_INDEX    = 2;
const int Config::PETS_TURN_RIGHT_STATE_INDEX   = 3;

const int Config::FISH_STATE_COUNT              = 10;
const int Config::FISH_INDEX_COUNT              = 10;

const int Config::ALIEN_STATE_COUNT             = 4;
const int Config::ALIEN_INDEX_COUNT             = 10;

const int Config::FOOD_STATE_COUNT              = 5;
const int Config::FOOD_INDEX_COUNT              = 10;

const int Config::MONEY_STATE_COUNT             = 6;
const int Config::MONEY_INDEX_COUNT             = 10;

const int Config::PETS_STATE_COUNT              = 4;
const int Config::PETS_INDEX_COUNT              = 10;

// speed up
const qreal Config::HUNGRY_INCREASE = 1.5;

// sink speed
const int Config::BODY_SINK_SPEED   = 10;
const int Config::FOOD_SINK_SPEED   = 2;
const int Config::MONEY_SINK_SPEED  = 5;

// hungry threshold
const int Config::HUNGRY_THRESHOLD = 25;
const int Config::FULL_THRESHOLD   = 85;

// damage
const int Config::ATTACK_ALIEN_DAMAGE = 10;

// steps
const int Config::HUNGRY_STEP             = 15;
const int Config::UPDATE_PAINT_STEP       = 5;
const int Config::CHANGE_DIRECTION_STEP   = 5;
const int Config::CHASE_STEP              = 2;
const int Config::FIND_FOOD_STEP          = 5;
const int Config::ALIENS_ATTACK_BASE_STEP = 2000; // default maybe 2000
const int Config::FIND_TARGET_STEP        = 3;

// hash
const QHash<QString, int> Config::FISH_YIELD_STEP = {
    { "smallGuppy",  9999 },
    { "middleGuppy", 1000 }
};

const QHash<QString, int> Config::FISH_SPEED = {
    { "smallGuppy",  5 },
    { "middleGuppy", 5 }
};

const QHash<QString, int> Config::FISH_PAINT_WIDTH = {
    { "smallGuppy",  40 },
    { "middleGuppy", 50 }
};

const QHash<QString, int> Config::FISH_PAINT_HEIGHT = {
    { "smallGuppy",  40 },
    { "middleGuppy", 45 }
};

const QHash<QString, QString> Config::FISH_PATH = {
    { "smallGuppy",  ":/fish/images/fish/smallGuppy.png" },
    { "middleGuppy", ":/fish/images/fish/mediumGuppy.png" }
};

const QHash<QString, int> Config::FISH_EATEN_EXP = {
    { "smallGuppy",  10 },
    { "middleGuppy", 15 }
};

const QHash<QString, int> Config::FISH_UPGRADE_EXP = {
    { "smallGuppy",  30 },
    { "middleGuppy", 45 }
};

const QHash<QString, int> Config::FOODS_INDEX = {
    { "smallFood", 0 },
    { "middleFood", 1 },
    { "bigFood", 2 },
    { "buttleFood", 3 },
    { "superFood", 4 }
};

const QHash<int, QString> Config::FOODS_NAME = {
    { 0, "smallFood" },
    { 1, "middleFood" },
    { 2, "bigFood" },
    { 3, "buttleFood" },
    { 4, "superFood" }
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

const QHash<QString, int> Config::ALIENS_MAX_HEALTH = {
    { "deepBlue", 100 }
};

const QHash<QString, QString> Config::ALIENS_PATH = {
    { "deepBlue",  ":/aliens/images/aliens/sylv.png" }
};

const QHash<QString, int> Config::ALIENS_PAINT_WIDTH = {
    { "deepBlue", 120 }
};

const QHash<QString, int> Config::ALIENS_PAINT_HEIGHT = {
    { "deepBlue", 160 }
};

const QHash<QString, int> Config::ALIENS_SPEED = {
    { "deepBlue",  10 }
};

const QHash<int, QString> Config::ALIENS_NAME = {
    { 0, "deepBlue" }
};

const QHash<QString, int> Config::MONEY_VALUE = {
    { "silver",   15 },
    { "gold",     35 },
    { "star",     100 },
    { "diamond",  200 },
    { "treasure", 2000 },
    { "insect",   200 }
};

const QHash<QString, int> Config::MONEY_INDEX = {
    { "silver",   0 },
    { "gold",     1 },
    { "star",     2 },
    { "diamond",  3 },
    { "treasure", 4 },
    { "insect",   5 }
};

const QHash<QString, int> Config::MONEY_PAINT_WIDTH = {
    { "silver",   48 },
    { "gold",     48 },
    { "star",     48 },
    { "diamond",  48 },
    { "treasure", 48 },
    { "insect",   48 }
};

const QHash<QString, int> Config::MONEY_PAINT_HEIGHT = {
    { "silver",   48 },
    { "gold",     48 },
    { "star",     48 },
    { "diamond",  48 },
    { "treasure", 48 },
    { "insect",   48 }
};

const QHash<QString, QString> Config::PETS_PATH = {
    { "stinky",  ":/pets/images/pets/stinky_converted.png" }
};

const QHash<QString, int> Config::PETS_SPEED = {
    { "stinky", 2 }
};

const QHash<QString, int> Config::PETS_PAINT_WIDTH = {
    { "stinky", 80 }
};

const QHash<QString, int> Config::PETS_PAINT_HEIGHT = {
    { "stinky", 70 }
};

const QHash<QString, int> Config::PETS_INIT_POS_X = {
    { "stinky", 480 }   // Config::SCREEN_WIDTH / 2
};

const QHash<QString, int> Config::PETS_INIT_POS_Y = {
    { "stinky", 579 }    // Config::POOL_LOWER_BOUND - Config::PETS_HEIGHT - 1
};

// list
const QStringList Config::FISH_TYPE = {
    "smallGuppy",
    "middleGuppy",
    "bigGuppy",
    "kingGuppy"
};

const QStringList Config::MONEY_TYPE = {
    "silver",
    "gold",
    "star",
    "diamond",
    "treasure",
    "insect"
};
