#include "config.h"

// math const
const qreal Config::PI = 3.1415926;

// screen size config
const qreal Config::SCALE_RATIO = 1.5;
const int Config::SCREEN_WIDTH  = 960;
const int Config::SCREEN_HEIGHT = 720;

// loading path
const QString Config::LOADING_PATH   = ":/labels/images/labels/2.gif";

// background path
const QString Config::BG_MENU_PATH   = ":/backgrounds/images/backgrounds/aquarium3.png";
const QString Config::BG_GAME_PATH_1 = ":/backgrounds/images/backgrounds/aquarium1.png";

// foods path
const QString Config::FOODS_PATH     = ":/foods/images/foods/food.png";

// money path
const QString Config::MONEY_PATH     = ":/money/images/money/money.png";

// loading size
const int Config::LOADING_WIDth        = 256;
const int Config::LOADING_HEIGHT       = 256;

// pool size
const int Config::POOL_UPPER_BOUND     = 80;
const int Config::POOL_LOWER_BOUND     = 660;

// fish size
const int Config::FISH_WIDTH           = 80;
const int Config::FISH_HEIGHT          = 80;
const int Config::ULTURAVORE_WIDTH     = 160;
const int Config::ULTURAVORE_HEIGHT    = 160;

// aliens size
const int Config::ALIENS_WIDTH         = 160;
const int Config::ALIENS_HEIGHT        = 160;

// money size
const int Config::MONEY_WIDTH          = 72;
const int Config::MONEY_HEIGHT         = 72;

// tick size
const int Config::TICK_WIDTH           = 160;
const int Config::TICK_HEIGHT          = 120;

// money display size
const int Config::MONEY_DISPLAY_WIDTH  = 80;
const int Config::MONEY_DISPLAY_HEIGHT = 60;

// numbers size
const int Config::NUMBERS_WIDTH        = 20;
const int Config::NUMBERS_HEIGHT       = 13;

// init const
const int Config::INIT_FOODS_RESTRICT = 1;   // defualt 1
const int Config::INIT_FISH_COUNT     = 2;   // default 2
const int Config::INIT_MONEY          = 99999;   // default 0

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

const int Config::NORMAL_SWIM_LEFT_STATE_INDEX   = 0;
const int Config::NORMAL_SWIM_RIGHT_STATE_INDEX  = 1;
const int Config::NORMAL_TURN_LEFT_STATE_INDEX   = 2;
const int Config::NORMAL_TURN_RIGHT_STATE_INDEX  = 3;
const int Config::HUNGRY_SWIM_LEFT_STATE_INDEX   = 4;
const int Config::HUNGRY_SWIM_RIGHT_STATE_INDEX  = 5;
const int Config::HUNGRY_TURN_LEFT_STATE_INDEX   = 6;
const int Config::HUNGRY_TURN_RIGHT_STATE_INDEX  = 7;
const int Config::DIE_LEFT_STATE_INDEX           = 8;
const int Config::DIE_RIGHT_STATE_INDEX          = 9;

const int Config::GRUBBER_MOVE_STATE_INDEX       = 0;
const int Config::GRUBBER_HUNGRY_STATE_INDEX     = 1;
const int Config::GRUBBER_DIE_STATE_INDEX        = 2;

const int Config::ALIEN_SWIM_LEFT_STATE_INDEX    = 0;
const int Config::ALIEN_SWIM_RIGHT_STATE_INDEX   = 1;
const int Config::ALIEN_TURN_LEFT_STATE_INDEX    = 2;
const int Config::ALIEN_TURN_RIGHT_STATE_INDEX   = 3;

const int Config::PETS_SWIM_LEFT_STATE_INDEX     = 0;
const int Config::PETS_SWIM_RIGHT_STATE_INDEX    = 1;
const int Config::PETS_TURN_LEFT_STATE_INDEX     = 2;
const int Config::PETS_TURN_RIGHT_STATE_INDEX    = 3;
const int Config::PETS_SPECIAL_LEFT_STATE_INDEX  = 4;
const int Config::PETS_SPECIAL_RIGHT_STATE_INDEX = 5;

const int Config::FISH_STATE_COUNT               = 10;
const int Config::FISH_INDEX_COUNT               = 10;

const int Config::ALIEN_STATE_COUNT              = 4;
const int Config::ALIEN_INDEX_COUNT              = 10;

const int Config::FOOD_STATE_COUNT               = 5;
const int Config::FOOD_INDEX_COUNT               = 10;

const int Config::MONEY_STATE_COUNT              = 7;
const int Config::MONEY_INDEX_COUNT              = 10;

const int Config::PETS_STATE_COUNT               = 4;
const int Config::PETS_INDEX_COUNT               = 10;

const int Config::MORE_FOOD_STATE_COUNT          = 6;
const int Config::EGG_STATE_COUNT                = 3;

// speed up
const qreal Config::HUNGRY_INCREASE = 1.5;

// sink speed
const int Config::BODY_SINK_SPEED   = 4;
const int Config::FOOD_SINK_SPEED   = 2;
const int Config::MONEY_SINK_SPEED  = 4;

// attack alien
const int Config::ATTACK_ALIEN_DAMAGE = 10;

// grubber
const int Config::GRUBBER_JUMP_MAX_HEIGHT = 360;
const int Config::GRUBBER_JUMP_SPEED      = 25;
const int Config::GRUBBER_POS_Y           = 579;

// steps
const int Config::HUNGRY_STEP             = 15;
const int Config::UPDATE_PAINT_STEP       = 5;
const int Config::CHANGE_DIRECTION_STEP   = 5;
const int Config::CHASE_STEP              = 2;
const int Config::FIND_FOOD_STEP          = 5;
const int Config::ALIENS_ATTACK_BASE_STEP = 599; // default maybe 2000
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
    { "bigBreeder",    1000 },
    { "grubber",       1000 },
    { "gekko",         1000 }
};

const QHash<QString, int> Config::FISH_SPEED = {
    { "smallGuppy",    5 },
    { "middleGuppy",   5 },
    { "bigGuppy",      5 },
    { "kingGuppy",     5 },
    { "carnivore",     6 },
    { "ulturavore",    8 },
    { "middleBreeder", 5 },
    { "bigBreeder",    5 },
    { "grubber",       6 },
    { "gekko",         6 }
};

const QHash<QString, int> Config::FISH_PAINT_WIDTH = {
    { "smallGuppy",    40  },
    { "middleGuppy",   50  },
    { "bigGuppy",      70  },
    { "kingGuppy",     75  },
    { "carnivore",     75  },
    { "ulturavore",    150 },
    { "middleBreeder", 55  },
    { "bigBreeder",    70  },
    { "grubber",       65  },
    { "gekko",         70  }
};

const QHash<QString, int> Config::FISH_PAINT_HEIGHT = {
    { "smallGuppy",    40  },
    { "middleGuppy",   45  },
    { "bigGuppy",      65  },
    { "kingGuppy",     70  },
    { "carnivore",     70  },
    { "ulturavore",    135 },
    { "middleBreeder", 50  },
    { "bigBreeder",    60  },
    { "grubber",       70  },
    { "gekko",         75  }
};

const QHash<QString, QString> Config::FISH_PATH = {
    { "smallGuppy",    ":/fish/images/fish/smallGuppy.png" },
    { "middleGuppy",   ":/fish/images/fish/mediumGuppy.png" },
    { "bigGuppy",      ":/fish/images/fish/bigGuppy.png" },
    { "kingGuppy",     ":/fish/images/fish/kingGuppy.png" },
    { "carnivore",     ":/fish/images/fish/carnivore.png" },
    { "ulturavore",    ":/fish/images/fish/398405234521987523.png" },
    { "middleBreeder", ":/fish/images/fish/mediumBreeder.png" },
    { "bigBreeder",    ":/fish/images/fish/bigBreeder.png" },
    { "grubber",       ":/fish/images/fish/grubgrubber.png" },
    { "gekko",         ":/fish/images/fish/gekko.png" }
};

const QHash<QString, int> Config::FISH_EATEN_EXP = {
    { "smallGuppy",    10 },
    { "middleGuppy",   15 },
    { "bigGuppy",      20 },
    { "kingGuppy",     25 },
    { "carnivore",     30 },
    { "ulturavore",    45 },
    { "middleBreeder", 15 },
    { "bigBreeder",    20 },
    { "grubber",       25 },
    { "gekko",         40 }
};

const QHash<QString, int> Config::FISH_UPGRADE_EXP = {
    { "smallGuppy",    30   },
    { "middleGuppy",   45   },
    { "bigGuppy",      60   },
    { "kingGuppy",     9999 },
    { "carnivore",     9999 },
    { "ulturavore",    9999 },
    { "middleBreeder", 45   },
    { "bigBreeder",    60   },
    { "grubber",       9999 },
    { "gekko",         9999 }
};

const QHash<QString, int> Config::FISH_INIT_HUNGRY = {
    { "smallGuppy",    85  },
    { "middleGuppy",   125 },
    { "bigGuppy",      170 },
    { "kingGuppy",     210 },
    { "carnivore",     125 },
    { "ulturavore",    250 },
    { "middleBreeder", 125 },
    { "bigBreeder",    170 },
    { "grubber",       170 },
    { "gekko",         150 }
};

const QHash<QString, int> Config::FISH_MAX_HUNGRY = {
    { "smallGuppy",    100 },
    { "middleGuppy",   150 },
    { "bigGuppy",      200 },
    { "kingGuppy",     250 },
    { "carnivore",     200 },
    { "ulturavore",    400 },
    { "middleBreeder", 150 },
    { "bigBreeder",    200 },
    { "grubber",       200 },
    { "gekko",         200 }
};

const QHash<QString, int> Config::FISH_HUNGRY_THRESHOLD = {
    { "smallGuppy",    50  },
    { "middleGuppy",   75  },
    { "bigGuppy",      100 },
    { "kingGuppy",     125 },
    { "carnivore",     100 },
    { "ulturavore",    200 },
    { "middleBreeder", 75  },
    { "bigBreeder",    100 },
    { "grubber",       110 },
    { "gekko",         80  }
};

const QHash<QString, int> Config::FISH_FULL_THRESHOLD = {
    { "smallGuppy",    85  },
    { "middleGuppy",   125 },
    { "bigGuppy",      170 },
    { "kingGuppy",     210 },
    { "carnivore",     125 },
    { "ulturavore",    250 },
    { "middleBreeder", 125 },
    { "bigBreeder",    170 },
    { "grubber",       180 },
    { "gekko",         180 }
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
    { "deepBlue",    50 },
    { "gus",         50 },
    { "balrog",      50 },
    { "psychosquid", 60 }
};

const QHash<QString, QString> Config::ALIENS_PATH = {
    { "deepBlue",    ":/aliens/images/aliens/sylv.png" },
    { "gus",         ":/aliens/images/aliens/750884456123613082.png" },
    { "balrog",      ":/aliens/images/aliens/balrog.png" },
    { "psychosquid", ":/aliens/images/aliens/psychosquid.png" }
};

const QHash<QString, int> Config::ALIENS_PAINT_WIDTH = {
    { "deepBlue",    120 },
    { "gus",         120 },
    { "balrog",      135 },
    { "psychosquid", 155 }
};

const QHash<QString, int> Config::ALIENS_PAINT_HEIGHT = {
    { "deepBlue",    160 },
    { "gus",         150 },
    { "balrog",      150 },
    { "psychosquid", 160 }
};

const QHash<QString, int> Config::ALIENS_SPEED = {
    { "deepBlue",    6 },
    { "gus",         6 },
    { "balrog",      6 },
    { "psychosquid", 6 }
};

const QHash<int, QString> Config::ALIENS_NAME = {
    { 0, "deepBlue"    },
    { 1, "gus"         },
    { 2, "balrog"      },
    { 3, "psychosquid" }
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
    { "stinky",  ":/pets/images/pets/884088821102378968.png" },
    { "vert",    ":/pets/images/pets/vert.png" },
    { "clyde",   ":/pets/images/pets/clyde.png" },
    { "prego",   ":/pets/images/pets/prego.png" },
    { "niko",    ":/pets/images/pets/niko.png" },
    { "meryl",   ":/pets/images/pets/meryl.png" }
};

const QHash<QString, int> Config::PETS_SPEED = {
    { "stinky", 2 },
    { "vert",   5 },
    { "clyde",  5 },
    { "prego",  5 },
    { "niko",   0 },
    { "meryl",  5 }
};

const QHash<QString, int> Config::PETS_PAINT_WIDTH = {
    { "stinky", 80 },
    { "vert",   80 },
    { "clyde",  80 },
    { "prego",  80 },
    { "niko",   80 },
    { "meryl",  80 }
};

const QHash<QString, int> Config::PETS_PAINT_HEIGHT = {
    { "stinky", 60 },
    { "vert",   60 },
    { "clyde",  75 },
    { "prego",  75 },
    { "niko",   80 },
    { "meryl",  75 }
};

const QHash<QString, int> Config::PETS_INIT_POS_X = {
    { "stinky", 480 },   // Config::SCREEN_WIDTH / 2
    { "vert",   320 },   // chosen casually
    { "clyde",  720 },
    { "prego",  360 },
    { "niko",   640 },
    { "meryl",  320 }
};

const QHash<QString, int> Config::PETS_INIT_POS_Y = {
    { "stinky", 579 },    // Config::POOL_LOWER_BOUND - Config::PETS_HEIGHT - 1
    { "vert",   480 },
    { "clyde",  240 },
    { "prego",  180 },
    { "niko",   540 },
    { "meryl",  240 }
};

const QHash<QString, int> Config::PETS_YIELD_STEP = {
    { "stinky", 9999 },
    { "vert",   500 },
    { "clyde",  9999 },
    { "prego",  500 },
    { "niko",   500 },
    { "meryl",  500 }
};

const QHash<QString, int> Config::ORIGIN_IMAGE_ROWS = {
    { "smallGuppy",       5 },
    { "middleGuppy",      5 },
    { "bigGuppy",         5 },
    { "kingGuppy",        5 },
    { "carnivore",        5 },
    { "ulturavore",       5 },
    { "middleBreeder",    5 },
    { "bigBreeder",       5 },
    { "grubber",          3 },
    { "gekko",            5 },

    { "stinky",           3 },
    { "vert",             2 },
    { "clyde",            1 },
    { "prego",            2 },
    { "niko",             2 },
    { "meryl",            2 },

    { "deepBlue",         2 },
    { "gus",              2 },
    { "balrog",           2 },
    { "psychosquid",      4 },

    { "startGameBtn",     1 },
    { "nextLevelBtn",     1 },
    { "restartBtn",       1 },
    { "confirmBtn",       1 },

    { "smallGuppyBtn",    1 },
    { "middleBreederBtn", 1 },
    { "grubberBtn",       1 },
    { "carnivoreBtn",     1 },
    { "ulturavoreBtn",    1 },
    { "foodUpgradeBtn",   1 },
    { "moreFoodBtn",      6 },
    { "eggBtn",           3 },

    { "stinkyBtn",        1 },
    { "vertBtn",          1 },
    { "clydeBtn",         1 },
    { "pregoBtn",         1 },
    { "nikoBtn",          1 },
    { "merylBtn",         1 },
    { "gekkoBtn",         1 }
};

const QHash<QString, QString> Config::BTNS_PATH = {
    { "startGameBtn",     ":/buttons/images/buttons/startGameBtn.png" },
    { "nextLevelBtn",     ":/buttons/images/buttons/344947327402287738.png" },
    { "restartBtn",       ":/buttons/images/buttons/756209509054362040.png" },
    { "confirmBtn",       ":/buttons/images/buttons/494578962922118304.png" },

    { "smallGuppyBtn",    ":/buttons/images/buttons/button1.png" },
    { "middleBreederBtn", ":/buttons/images/buttons/button2.png" },   
    { "carnivoreBtn",     ":/buttons/images/buttons/button3.png" },
    { "ulturavoreBtn",    ":/buttons/images/buttons/button4.png" },
    { "grubberBtn",       ":/buttons/images/buttons/button6.png" },
    { "gekkoBtn",         ":/buttons/images/buttons/button7.png" },
    { "foodUpgradeBtn",   ":/buttons/images/buttons/button8.png" },
    { "moreFoodBtn",      ":/buttons/images/buttons/button9.png" },
    { "eggBtn",           ":/buttons/images/buttons/362283261707809117.png" },

    { "stinkyBtn",        ":/buttons/images/buttons/29204779860393857.png" },
    { "vertBtn",          ":/buttons/images/buttons/269280215658910314.png" },
    { "clydeBtn",         ":/buttons/images/buttons/566282524902953530.png" },
    { "pregoBtn",         ":/buttons/images/buttons/722550347237888875.png" },
    { "nikoBtn",          ":/buttons/images/buttons/215038652394933910.png" },
    { "merylBtn",         ":/buttons/images/buttons/610390542174633425.png" }
};

const QHash<QString, int> Config::BTNS_WIDTH = {
    { "startGameBtn",     288 },
    { "nextLevelBtn",     288 },
    { "restartBtn",       288 },
    { "confirmBtn",       288 },

    { "smallGuppyBtn",    100 },
    { "middleBreederBtn", 100 },  
    { "carnivoreBtn",     100 },
    { "ulturavoreBtn",    100 },
    { "grubberBtn",       100 },
    { "gekkoBtn",         100 },
    { "foodUpgradeBtn",   100 },
    { "moreFoodBtn",      100 },
    { "eggBtn",           100 },

    { "stinkyBtn",        200 },
    { "vertBtn",          200 },
    { "clydeBtn",         200 },
    { "pregoBtn",         200 },
    { "nikoBtn",          200 },
    { "merylBtn",         200 }
};

const QHash<QString, int> Config::BTNS_HEIGHT = {
    { "startGameBtn",     33 },
    { "nextLevelBtn",     33 },
    { "restartBtn",       33 },
    { "confirmBtn",       33 },

    { "smallGuppyBtn",    75 },
    { "middleBreederBtn", 75 },    
    { "carnivoreBtn",     75 },
    { "ulturavoreBtn",    75 },
    { "grubberBtn",       75 },
    { "gekkoBtn",         75 },
    { "foodUpgradeBtn",   75 },
    { "moreFoodBtn",      75 },
    { "eggBtn",           75 },

    { "stinkyBtn",        150 },
    { "vertBtn",          150 },
    { "clydeBtn",         150 },
    { "pregoBtn",         150 },
    { "nikoBtn",          150 },
    { "merylBtn",         150 }
};

const QHash<QString, QPointF> Config::BTNS_INIT_POS = {
    { "startGameBtn",     QPointF(336, 480) },   // Config::SCREEN_WIDTH - Config::MENU_BTN_WIDTH) / 2.0,
                                                 // Config::SCREEN_HEIGHT * 2.0 / 3.0
    { "nextLevelBtn",     QPointF(345, 540) },
    { "restartBtn",       QPointF(345, 540) },
    { "confirmBtn",       QPointF(345, 540) },

    { "smallGuppyBtn",    QPointF(0  , 0  ) },
    { "middleBreederBtn", QPointF(100, 0  ) },
    { "carnivoreBtn",     QPointF(200, 0  ) },
    { "ulturavoreBtn",    QPointF(300, 0  ) },
    { "grubberBtn",       QPointF(400, 0  ) },
    { "gekkoBtn",         QPointF(500, 0  ) },
    { "foodUpgradeBtn",   QPointF(600, 0  ) },
    { "moreFoodBtn",      QPointF(700, 0  ) },
    { "eggBtn",           QPointF(800, 0  ) },

    { "stinkyBtn",        QPointF(280, 80 ) },
    { "vertBtn",          QPointF(480, 80 ) },
    { "clydeBtn",         QPointF(280, 230) },
    { "pregoBtn",         QPointF(480, 230) },
    { "nikoBtn",          QPointF(280, 380) },
    { "merylBtn",         QPointF(480, 380) }
};

const QHash<QString, int> Config::BTNS_COST = {
    { "startGameBtn",     0     },
    { "nextLevelBtn",     0     },
    { "restartBtn",       0     },
    { "confirmBtn",       0     },

    { "smallGuppyBtn",    100   },
    { "middleBreederBtn", 200   },
    { "carnivoreBtn",     1000  },
    { "ulturavoreBtn",    10000 },
    { "grubberBtn",       750   },
    { "gekkoBtn",         2000  },
    { "foodUpgradeBtn",   200   },
    { "moreFoodBtn",      300   },
    { "eggBtn",           1000  },

    { "stinkyBtn",        0     },
    { "vertBtn",          0     },
    { "clydeBtn",         0     },
    { "pregoBtn",         0     },
    { "nikoBtn",          0     },
    { "merylBtn",         0     }
};

const QHash<QString, QPointF> Config::TICK_POS = {
    { "stinkyBtn", QPointF(340, 120) },
    { "vertBtn",   QPointF(540, 120) },
    { "clydeBtn",  QPointF(340, 270) },
    { "pregoBtn",  QPointF(540, 270) },
    { "nikoBtn",   QPointF(340, 420) },
    { "merylBtn",  QPointF(540, 420) }
};

const QHash<QString, QString> Config::LABELS_PATH = {
    { "nextLevelLabel", ":/labels/images/labels/92184686600866551.png" },
    { "restartLabel",   ":/labels/images/labels/168117158668655894.png" },
    { "choosePetLabel", ":/labels/images/labels/461148065737624740.png" },
    { "tickLabel",      ":/labels/images/labels/810190804463658840.png" }
};

const QHash<int, QString> Config::NUMBERS_PATH = {
    { 0,  ":/numbers/images/num/0.png" },
    { 1,  ":/numbers/images/num/1.png" },
    { 2,  ":/numbers/images/num/2.png" },
    { 3,  ":/numbers/images/num/3.png" },
    { 4,  ":/numbers/images/num/4.png" },
    { 5,  ":/numbers/images/num/5.png" },
    { 6,  ":/numbers/images/num/6.png" },
    { 7,  ":/numbers/images/num/7.png" },
    { 8,  ":/numbers/images/num/8.png" },
    { 9,  ":/numbers/images/num/9.png" },
    { 10, ":/numbers/images/num/10.png" }
};

const QHash<int, QPointF> Config::NUMBERS_INIT_POS = {
    { 0, QPointF(0  , 77) },
    { 1, QPointF(22 , 77) },
    { 2, QPointF(44 , 77) },
    { 3, QPointF(66 , 77) },
    { 4, QPointF(88 , 77) },
    { 5, QPointF(110, 77) }
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
    "bigBreeder",
    "grubber",
    "gekko"
};

const QStringList Config::PETS_TYPE = {
    "stinky",
    "vert",
    "clyde",
    "prego",
    "niko",
    "meryl"
};

const QStringList Config::MONEY_TYPE = {
    "silver",
    "gold",
    "star",
    "diamond",
    "treasure",
    "insect",
    "pearl"
};

const QStringList Config::GUPPY_TYPE = {
    "smallGuppy",
    "middleGuppy",
    "bigGuppy",
    "kingGuppy"
};

const QStringList Config::EDIBLE_TYPE = {
    "smallGuppy",
    "middleGuppy",
    "bigGuppy",
    "kingGuppy",
    "carnivore",
    "ulturavore",
    "middleBreeder",
    "bigBreeder",
    "grubber",
    "gekko",

    "food"
};

const QHash<QString, QStringList> Config::COLLIDABLE_ITEMS = {
    { "smallGuppy",    QStringList("food")       },
    { "middleGuppy",   QStringList("food")       },
    { "bigGuppy",      QStringList("food")       },
    { "kingGuppy",     QStringList("food")       },
    { "carnivore",     Config::GUPPY_TYPE        },
    { "ulturavore",    QStringList("carnivore")  },
    { "middleBreeder", QStringList("food")       },
    { "bigBreeder",    QStringList("food")       },
    { "grubber",       QStringList("smallGuppy") },
    { "gekko",         QStringList("insect")     },

    { "deepBlue",      Config::FISH_TYPE         },
    { "gus",           Config::EDIBLE_TYPE       },
    { "balrog",        Config::FISH_TYPE         },
    { "psychosquid",   Config::FISH_TYPE         },

    { "stinky",        Config::MONEY_TYPE        },
    { "vert",          QStringList("")           },
    { "clyde",         Config::MONEY_TYPE        },
    { "prego",         QStringList("food")       },
    { "niko",          QStringList("")           },
    { "meryl",         QStringList("")           }
};

// sounds path
const QHash<QString, QString> Config::SOUNDS_PATH = {
    { "nextLevelSound", ":/sounds/sounds/applause.wav"  },
    { "buySound",       ":/sounds/sounds/buy.wav"       },
    { "kingGuppySound", ":/sounds/sounds/crowned1.wav"  },
    { "hitAlienSound",  ":/sounds/sounds/hit.wav"       },
    { "nikoCloseSound", ":/sounds/sounds/nikoclose.wav" },
    { "nikoOpenSound",  ":/sounds/sounds/nikoopen.wav"  },
    { "splashSound",    ":/sounds/sounds/SPLASH.wav"    },
    { "warningSound",   ":/sounds/sounds/warning.wav"   }
};
