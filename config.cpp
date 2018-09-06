#include "config.h"

// math const
const qreal Config::PI = 3.1415926;

// screen size config
const qreal Config::SCALE_RATIO = 1.5;
const int Config::SCREEN_WIDTH  = 960;
const int Config::SCREEN_HEIGHT = 720;

// background path
const QString Config::BG_MENU_PATH   = ":/backgrounds/images/backgrounds/aquarium3.png";
const QString Config::BG_GAME_PATH_1 = ":/backgrounds/images/backgrounds/aquarium1.png";

// labels path
const QString Config::NEXT_LEVEL_LABEL = ":/labels/images/labels/92184686600866551.png";

// foods path
const QString Config::FOODS_PATH = ":/foods/images/foods/food.png";

// money path
const QString Config::MONEY_PATH = ":/money/images/money/money.png";

// pool size
const int Config::POOL_UPPER_BOUND = 120;
const int Config::POOL_LOWER_BOUND = 660;

// fish size
const int Config::FISH_WIDTH        = 80;
const int Config::FISH_HEIGHT       = 80;
const int Config::ULTURAVORE_WIDTH  = 160;
const int Config::ULTURAVORE_HEIGHT = 160;

// aliens size
const int Config::ALIENS_WIDTH  = 160;
const int Config::ALIENS_HEIGHT = 160;

// money size
const int Config::MONEY_WIDTH  = 72;
const int Config::MONEY_HEIGHT = 72;

// init const
const int Config::INIT_FOODS_RESTRICT = 1;   // defualt 1
const int Config::INIT_FISH_COUNT     = 1;   // default 2
const int Config::INIT_MONEY          = 9999999;   // default 0

// foods size
const int Config::FOODS_WIDTH  = 40;
const int Config::FOODS_HEIGHT = 40;

// pets size
const int Config::PETS_WIDTH   = 80;
const int Config::PETS_HEIGHT  = 80;

// pixs index
const int Config::DEFAULT_BTN_INDEX = 0;
const int Config::HOVER_BTN_INDEX   = 1;
const int Config::PRESSED_BTN_INDEX = 2;
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

const int Config::MONEY_STATE_COUNT             = 7;
const int Config::MONEY_INDEX_COUNT             = 10;

const int Config::PETS_STATE_COUNT              = 4;
const int Config::PETS_INDEX_COUNT              = 10;

const int Config::MORE_FOOD_STATE_COUNT         = 6;
const int Config::EGG_STATE_COUNT               = 3;

// speed up
const qreal Config::HUNGRY_INCREASE = 1.5;

// sink speed
const int Config::BODY_SINK_SPEED   = 8;
const int Config::FOOD_SINK_SPEED   = 2;
const int Config::MONEY_SINK_SPEED  = 5;

// damage
const int Config::ATTACK_ALIEN_DAMAGE = 10;

// steps
const int Config::HUNGRY_STEP             = 15;
const int Config::UPDATE_PAINT_STEP       = 5;
const int Config::CHANGE_DIRECTION_STEP   = 5;
const int Config::CHASE_STEP              = 2;
const int Config::FIND_FOOD_STEP          = 5;
const int Config::ALIENS_ATTACK_BASE_STEP = 999999999; // default maybe 2000
const int Config::FIND_TARGET_STEP        = 3;

// hash
const QHash<QString, int> Config::FISH_YIELD_STEP = {
    { "smallGuppy",    9999 },
    { "middleGuppy",   1000 },
    { "bigGuppy",      1000 },
    { "kingGuppy",     1000 },
    { "carnivore",     1000 },
    { "ulturavore",    1000 },
    { "middleBreeder", 1000 },
    { "bigBreeder",    500 }
};

const QHash<QString, int> Config::FISH_SPEED = {
    { "smallGuppy",    5 },
    { "middleGuppy",   5 },
    { "bigGuppy",      5 },
    { "kingGuppy",     5 },
    { "carnivore",     6 },
    { "ulturavore",    8 },
    { "middleBreeder", 5 },
    { "bigBreeder",    5 }
};

const QHash<QString, int> Config::FISH_PAINT_WIDTH = {
    { "smallGuppy",    40 },
    { "middleGuppy",   50 },
    { "bigGuppy",      70 },
    { "kingGuppy",     75 },
    { "carnivore",     75 },
    { "ulturavore",    150 },
    { "middleBreeder", 55 },
    { "bigBreeder",    70 }
};

const QHash<QString, int> Config::FISH_PAINT_HEIGHT = {
    { "smallGuppy",    40 },
    { "middleGuppy",   45 },
    { "bigGuppy",      65 },
    { "kingGuppy",     70 },
    { "carnivore",     70 },
    { "ulturavore",    135 },
    { "middleBreeder", 50 },
    { "bigBreeder",    60 }
};

const QHash<QString, QString> Config::FISH_PATH = {
    { "smallGuppy",    ":/fish/images/fish/smallGuppy.png" },
    { "middleGuppy",   ":/fish/images/fish/mediumGuppy.png" },
    { "bigGuppy",      ":/fish/images/fish/bigGuppy.png" },
    { "kingGuppy",     ":/fish/images/fish/kingGuppy.png" },
    { "carnivore",     ":/fish/images/fish/carnivore.png" },
    { "ulturavore",    ":/fish/images/fish/ulturavore_converted.png" },
    { "middleBreeder", ":/fish/images/fish/mediumBreeder.png" },
    { "bigBreeder",    ":/fish/images/fish/bigBreeder.png" }
};

const QHash<QString, int> Config::FISH_EATEN_EXP = {
    { "smallGuppy",    10 },
    { "middleGuppy",   15 },
    { "bigGuppy",      20 },
    { "kingGuppy",     25 },
    { "carnivore",     30 },
    { "ulturavore",    45 },
    { "middleBreeder", 15 },
    { "bigBreeder",    20 }
};

const QHash<QString, int> Config::FISH_UPGRADE_EXP = {
    { "smallGuppy",    30 },
    { "middleGuppy",   45 },
    { "bigGuppy",      60 },
    { "kingGuppy",     9999 },
    { "carnivore",     9999 },
    { "ulturavore",    9999 },
    { "middleBreeder", 45 },
    { "bigBreeder",    60 }
};

const QHash<QString, int> Config::FISH_INIT_HUNGRY = {
    { "smallGuppy",    85 },
    { "middleGuppy",   125 },
    { "bigGuppy",      170 },
    { "kingGuppy",     210 },
    { "carnivore",     170 },
    { "ulturavore",    340 },
    { "middleBreeder", 125 },
    { "bigBreeder",    170 }
};

const QHash<QString, int> Config::FISH_MAX_HUNGRY = {
    { "smallGuppy",    100 },
    { "middleGuppy",   150 },
    { "bigGuppy",      200 },
    { "kingGuppy",     250 },
    { "carnivore",     200 },
    { "ulturavore",    400 },
    { "middleBreeder", 150 },
    { "bigBreeder",    200 }
};

const QHash<QString, int> Config::FISH_HUNGRY_THRESHOLD = {
    { "smallGuppy",    50 },
    { "middleGuppy",   75 },
    { "bigGuppy",      100 },
    { "kingGuppy",     125 },
    { "carnivore",     100 },
    { "ulturavore",    200 },
    { "middleBreeder", 75 },
    { "bigBreeder",    100 }
};

const QHash<QString, int> Config::FISH_FULL_THRESHOLD = {
    { "smallGuppy",    85 },
    { "middleGuppy",   125 },
    { "bigGuppy",      170 },
    { "kingGuppy",     210 },
    { "carnivore",     125 },
    { "ulturavore",    250 },
    { "middleBreeder", 125 },
    { "bigBreeder",    170 }
};

const QHash<QString, int> Config::FOODS_INDEX = {
    { "smallFood",  0 },
    { "middleFood", 1 },
    { "bigFood",    2 },
    { "buttleFood", 3 },
    { "superFood",  4 }
};

const QHash<int, QString> Config::FOODS_NAME = {
    { 0, "smallFood" },
    { 1, "middleFood" },
    { 2, "bigFood" },
    { 3, "buttleFood" },
    { 4, "superFood" }
};

const QHash<QString, int> Config::FOODS_PAINT_WIDTH = {
    { "smallFood",  16 },
    { "middleFood", 16 },
    { "bigFood",    16 },
    { "buttleFood", 16 },
    { "superFood",  16 }
};

const QHash<QString, int> Config::FOODS_PAINT_HEIGHT = {
    { "smallFood",  11 },
    { "middleFood", 20 },
    { "bigFood",    12 },
    { "buttleFood", 16 },
    { "superFood",  16 }
};

const QHash<QString, int> Config::FOODS_EXP = {
    { "smallFood",  10 },
    { "middleFood", 15 },
    { "bigFood",    20 },
    { "buttleFood", 25 },
    { "superFood",  30 }
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
    { "deepBlue",  5 }
};

const QHash<int, QString> Config::ALIENS_NAME = {
    { 0, "deepBlue" }
};

const QHash<QString, int> Config::MONEY_VALUE = {
    { "silver",   15 },
    { "gold",     35 },
    { "star",     100 },
    { "diamond",  200 },
    { "treasure", 1000 },
    { "insect",   200 },
    { "pearl",    300 }
};

const QHash<QString, int> Config::MONEY_INDEX = {
    { "silver",   0 },
    { "gold",     1 },
    { "star",     2 },
    { "diamond",  3 },
    { "treasure", 4 },
    { "insect",   5 },
    { "pearl",    6 }
};

const QHash<QString, int> Config::MONEY_PAINT_WIDTH = {
    { "silver",   48 },
    { "gold",     48 },
    { "star",     48 },
    { "diamond",  48 },
    { "treasure", 48 },
    { "insect",   48 },
    { "pearl",    48 }
};

const QHash<QString, int> Config::MONEY_PAINT_HEIGHT = {
    { "silver",   48 },
    { "gold",     48 },
    { "star",     48 },
    { "diamond",  48 },
    { "treasure", 48 },
    { "insect",   48 },
    { "pearl",    48 }
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
    { "stinky", 60 }
};

const QHash<QString, int> Config::PETS_INIT_POS_X = {
    { "stinky", 480 }   // Config::SCREEN_WIDTH / 2
};

const QHash<QString, int> Config::PETS_INIT_POS_Y = {
    { "stinky", 579 }    // Config::POOL_LOWER_BOUND - Config::PETS_HEIGHT - 1
};

const QHash<QString, int> Config::ORIGIN_IMAGE_ROWS = {
    { "smallGuppy",     5 },
    { "middleGuppy",    5 },
    { "bigGuppy",       5 },
    { "kingGuppy",      5 },
    { "carnivore",      5 },
    { "ulturavore",     5 },
    { "middleBreeder",  5 },
    { "bigBreeder",     5 },

    { "stinky",         2 },

    { "deepBlue",       2 },

    { "startGameBtn",   1 },
    { "guppyBtn",       1 },
    { "breederBtn",     1 },
    { "carnivoreBtn",   1 },
    { "ulturavoreBtn",  1 },
    { "foodUpgradeBtn", 1 },
    { "moreFoodBtn",    6 },
    { "eggBtn",         3 }
};

const QHash<QString, QString> Config::BTNS_PATH = {
    { "startGameBtn",   ":/buttons/images/buttons/startGameBtn.png" },
    { "guppyBtn",       ":/buttons/images/buttons/button1.png" },
    { "breederBtn",     ":/buttons/images/buttons/button2.png" },
    { "carnivoreBtn",   ":/buttons/images/buttons/button3.png" },
    { "ulturavoreBtn",  ":/buttons/images/buttons/button4.png" },
    { "foodUpgradeBtn", ":/buttons/images/buttons/button8.png" },
    { "moreFoodBtn",    ":/buttons/images/buttons/button9.png" },
    { "eggBtn",         ":/buttons/images/buttons/362283261707809117.png" }
};

const QHash<QString, int> Config::BTNS_WIDTH = {
    { "startGameBtn",    288 },
    { "guppyBtn",        100 },
    { "breederBtn",      100 },
    { "carnivoreBtn",    100 },
    { "ulturavoreBtn",   100 },
    { "foodUpgradeBtn",  100 },
    { "moreFoodBtn",     100 },
    { "eggBtn",          100 }
};

const QHash<QString, int> Config::BTNS_HEIGHT = {
    { "startGameBtn",   33 },
    { "guppyBtn",       75 },
    { "breederBtn",     75 },
    { "carnivoreBtn",   75 },
    { "ulturavoreBtn",  75 },
    { "foodUpgradeBtn", 75 },
    { "moreFoodBtn",    75 },
    { "eggBtn",         75 }
};

const QHash<QString, QPointF> Config::BTNS_INIT_POS = {
    { "startGameBtn", QPointF(336, 480) },   // Config::SCREEN_WIDTH - Config::MENU_BTN_WIDTH) / 2.0,
                                             // Config::SCREEN_HEIGHT * 2.0 / 3.0
    { "guppyBtn",       QPointF(0, 0) },
    { "breederBtn",     QPointF(100, 0) },
    { "carnivoreBtn",   QPointF(200, 0) },
    { "ulturavoreBtn",  QPointF(300, 0) },
    { "foodUpgradeBtn", QPointF(400, 0) },
    { "moreFoodBtn",    QPointF(500, 0) },
    { "eggBtn",         QPointF(600, 0) }
};

const QHash<QString, int> Config::BTNS_COST = {
    { "startGameBtn",   0 },
    { "guppyBtn",       100 },
    { "breederBtn",     200 },
    { "carnivoreBtn",   1000 },
    { "ulturavoreBtn",  10000 },
    { "foodUpgradeBtn", 200 },
    { "moreFoodBtn",    300 },
    { "eggBtn",         1000 }
};

// list
const QStringList Config::FISH_TYPE = {
    "smallGuppy",
    "middleGuppy",
    "bigGuppy",
    "kingGuppy",
    "carnivore",
    "ulturavore",
    "middleBreeder",
    "bigBreeder"
};

const QStringList Config::MONEY_TYPE = {
    "silver",
    "gold",
    "star",
    "diamond",
    "treasure",
    "insect"
};

const QStringList Config::GUPPY_TYPE = {
    "smallGuppy",
    "middleGuppy",
    "bigGuppy",
    "kingGuppy"
};

const QHash<QString, QStringList> Config::COLLIDABLE_ITEMS = {
    { "smallGuppy",    QStringList("food") },
    { "middleGuppy",   QStringList("food") },
    { "bigGuppy",      QStringList("food") },
    { "kingGuppy",     QStringList("food") },
    { "carnivore",     Config::GUPPY_TYPE },
    { "ulturavore",    QStringList("carnivore") },
    { "middleBreeder", QStringList("food") },
    { "bigBreeder",    QStringList("food") },

    { "deepBlue",      Config::FISH_TYPE },

    { "stinky",        Config::MONEY_TYPE }
};
