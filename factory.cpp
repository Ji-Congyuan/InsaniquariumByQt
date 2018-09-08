#include "factory.h"
#include <QDebug>

AbstractAlien *Factory::createAlien(const QString &name,
                                    const QPointF &pos,
                                    QGraphicsScene *scene)
{
    QPixmaps2 pixs2;
    QPixmap pic(Config::ALIENS_PATH[name]);
    QPixmaps2 origins = PixmapsMaker::createQPixmaps(pic, 10, 2);

    QPixmaps alienSwimL;
    QPixmaps alienSwimR;
    QPixmaps alienTurnL;
    QPixmaps alienTurnR;

    int width = Config::ALIENS_WIDTH;
    int height = Config::ALIENS_HEIGHT;

    for (int i = 0; i < Config::ALIEN_INDEX_COUNT; i++){
        // ALIEN_SWIM_LEFT_STATE
        alienSwimL.append(origins.at(0).at(i)
                          .scaled(width, height,
                                  Qt::KeepAspectRatioByExpanding));

        // ALIEN_SWIM_RIGHT_STATE
        QImage originImg = origins.at(0).at(i)
                .toImage();
        QImage mirrored = originImg.mirrored(true, false);
        QPixmap temp = QPixmap::fromImage(mirrored)
                .scaled(width, height,
                        Qt::KeepAspectRatioByExpanding);
        alienSwimR.append(temp);

        // ALIEN_TURN_LEFT_STATE
        alienTurnL.append(origins.at(1).at(Config::ALIEN_INDEX_COUNT - i - 1)
                          .scaled(width, height,
                                  Qt::KeepAspectRatioByExpanding));

        // ALIEN_TURN_RIGHT_STATE
        alienTurnR.append(origins.at(1).at(i)
                          .scaled(width, height,
                                  Qt::KeepAspectRatioByExpanding));
    }
    pixs2.append(alienSwimL);
    pixs2.append(alienSwimR);
    pixs2.append(alienTurnL);
    pixs2.append(alienTurnR);

    AbstractAlien * alien;
    if (name == "deepBlue"){
        alien = new DeepBlue(Config::ALIENS_WIDTH,
                             Config::ALIENS_HEIGHT,
                             pos, pixs2, scene);
    }
    else if (name == "gus"){
        alien = new Gus(Config::ALIENS_WIDTH,
                        Config::ALIENS_HEIGHT,
                        pos, pixs2, scene);
    }

    alien->setSpeed(Config::ALIENS_SPEED[name]);
    alien->setDirection(RandomMaker::creatRandom(-314, 314) / 100.0);
    alien->setPaintWidth(Config::ALIENS_PAINT_WIDTH[name]);
    alien->setPaintHeight(Config::ALIENS_PAINT_HEIGHT[name]);

    alien->updateDirection();

    return alien;
}

AbstractFish *Factory::creatFish(const QString &name,
                                 const QPointF &pos,
                                 QGraphicsScene *scene)
{
    QPixmaps2 pixs2;
    QPixmap pic(Config::FISH_PATH[name]);
    QPixmaps2 origins = PixmapsMaker::createQPixmaps(pic, 10, Config::ORIGIN_IMAGE_ROWS[name]);

    if (Config::ORIGIN_IMAGE_ROWS[name] == 5){
        QPixmaps normalSwimL;
        QPixmaps normalSwimR;
        QPixmaps normalTurnL;
        QPixmaps normalTurnR;
        QPixmaps hungrySwimL;
        QPixmaps hungrySwimR;
        QPixmaps hungryTurnL;
        QPixmaps hungryTurnR;
        QPixmaps dieL;
        QPixmaps dieR;

        int width = Config::FISH_WIDTH;
        int height = Config::FISH_HEIGHT;

        for (int i = 0; i < Config::FISH_INDEX_COUNT; ++i){
            // NORMAL_SWIM_LEFT_STATE
            normalSwimL.append(origins.at(0).at(i)
                         .scaled(width, height,
                                 Qt::KeepAspectRatioByExpanding));

            // NORMAL_SWIM_RIGHT_STATE
            QImage originImg = origins.at(0).at(i)
                    .toImage();
            QImage mirrored = originImg.mirrored(true, false);
            QPixmap temp = QPixmap::fromImage(mirrored)
                    .scaled(width, height,
                            Qt::KeepAspectRatioByExpanding);
            normalSwimR.append(temp);

            // NORMAL_TURN_LEFT_STATE
            normalTurnL.append(origins.at(1).at(Config::FISH_INDEX_COUNT - i - 1)
                               .scaled(width, height,
                                       Qt::KeepAspectRatioByExpanding));

            // NORMAL_TURN_RIGHT_STATE
            normalTurnR.append(origins.at(1).at(i)
                               .scaled(width, height,
                                       Qt::KeepAspectRatioByExpanding));

            // HUNGRY_SWIM_LEFT_STATE
            hungrySwimL.append(origins.at(2).at(i)
                               .scaled(width, height,
                                       Qt::KeepAspectRatioByExpanding));

            // HUNGRY_SWIM_RIGHT_STATE
            originImg = origins.at(2).at(i)
                    .toImage();
            mirrored = originImg.mirrored(true, false);
            temp = QPixmap::fromImage(mirrored)
                    .scaled(width, height,
                            Qt::KeepAspectRatioByExpanding);
            hungrySwimR.append(temp);

            // HUNGRY_TURN_LEFT_STATE
            hungryTurnL.append(origins.at(3).at(Config::FISH_INDEX_COUNT - i - 1)
                               .scaled(width, height,
                                       Qt::KeepAspectRatioByExpanding));

            // HUNGRY_TURN_RIGHT_STATE
            hungryTurnR.append(origins.at(3).at(i)
                              .scaled(width, height,
                                      Qt::KeepAspectRatioByExpanding));

            // DIE_LEFT_STATE
            dieL.append(origins.at(4).at(i)
                        .scaled(width, height,
                                Qt::KeepAspectRatioByExpanding));

            // DIE_RIGHT_STATE
            originImg = origins.at(4).at(i)
                    .toImage();
            mirrored = originImg.mirrored(true, false);
            temp = QPixmap::fromImage(mirrored)
                    .scaled(width, height,
                            Qt::KeepAspectRatioByExpanding);
            dieR.append(temp);

        }

        pixs2.append(normalSwimL);
        pixs2.append(normalSwimR);
        pixs2.append(normalTurnL);
        pixs2.append(normalTurnR);
        pixs2.append(hungrySwimL);
        pixs2.append(hungrySwimR);
        pixs2.append(hungryTurnL);
        pixs2.append(hungryTurnR);
        pixs2.append(dieL);
        pixs2.append(dieR);
    }

    AbstractFish * fish;
    if (name == "smallGuppy"){
        fish = new SmallGuppy(Config::FISH_WIDTH,
                              Config::FISH_HEIGHT,
                              pos, pixs2, scene);
    }
    else if (name == "middleGuppy"){
        fish = new MiddleGuppy(Config::FISH_WIDTH,
                               Config::FISH_HEIGHT,
                               pos, pixs2, scene);
    }
    else if (name == "bigGuppy"){
        fish = new BigGuppy(Config::FISH_WIDTH,
                            Config::FISH_HEIGHT,
                            pos, pixs2, scene);
    }
    else if (name == "kingGuppy"){
        fish = new KingGuppy(Config::FISH_WIDTH,
                             Config::FISH_HEIGHT,
                             pos, pixs2, scene);
    }
    else if (name == "carnivore"){
        fish = new Carnivore(Config::FISH_WIDTH,
                             Config::FISH_HEIGHT,
                             pos, pixs2, scene);
    }
    else if (name == "ulturavore"){
        fish = new Ulturavore(Config::ULTURAVORE_WIDTH,
                              Config::ULTURAVORE_HEIGHT,
                              pos, pixs2, scene);
    }
    else if (name == "middleBreeder"){
        fish = new MiddleBreeder(Config::FISH_WIDTH,
                                 Config::FISH_HEIGHT,
                                 pos, pixs2, scene);
    }
    else if (name == "bigBreeder"){
        fish = new BigBreeder(Config::FISH_WIDTH,
                              Config::FISH_HEIGHT,
                              pos, pixs2, scene);
    }

    fish->setSpeed(Config::FISH_SPEED[name]);
    fish->setDirection(RandomMaker::creatRandom(-314, 314) / 100.0);
    fish->setPaintWidth(Config::FISH_PAINT_WIDTH[name]);
    fish->setPaintHeight(Config::FISH_PAINT_HEIGHT[name]);
    fish->setEatenExp(Config::FISH_EATEN_EXP[name]);

    fish->updateDirection();

    return fish;
}

Food *Factory::createFood(const QString &name,
                          const QPointF &pos,
                          QGraphicsScene *scene)
{
    QPixmaps2 pixs2;
    QPixmap pic(Config::FOODS_PATH);
    QPixmaps2 all = PixmapsMaker::createQPixmaps(pic, 10, 5);
    pixs2.append(all.at(Config::FOODS_INDEX[name]));

    Food * food = new Food(Config::FOODS_WIDTH,
                        Config::FOODS_HEIGHT,
                        pos, pixs2, scene);

    food->setSpeed(Config::FOOD_SINK_SPEED);
    food->setDirection(Config::PI / 2);
    food->setPaintWidth(Config::FOODS_PAINT_WIDTH[name]);
    food->setPaintHeight(Config::FOODS_PAINT_HEIGHT[name]);
    food->setEatenExp(Config::FOODS_EXP[name]);

    return food;
}

AbstractMoney *Factory::createMoney(const QString &name,
                                    const QPointF &pos,
                                    QGraphicsScene *scene)
{
    QPixmaps2 pixs2;
    QPixmap pic(Config::MONEY_PATH);
    QPixmaps2 all = PixmapsMaker::createQPixmaps(pic,
                                                 Config::MONEY_INDEX_COUNT,
                                                 Config::MONEY_STATE_COUNT);
    pixs2.append(all.at(Config::MONEY_INDEX[name]));

    AbstractMoney * money;
    if (name == "silver"){
        money = new Silver(Config::MONEY_WIDTH,
                           Config::MONEY_HEIGHT,
                           pos, pixs2, scene);
    }
    else if (name == "gold"){
        money = new Gold(Config::MONEY_WIDTH,
                         Config::MONEY_HEIGHT,
                         pos, pixs2, scene);
    }
    else if (name == "diamond"){
        money = new Diamond(Config::MONEY_WIDTH,
                            Config::MONEY_HEIGHT,
                            pos, pixs2, scene);
    }
    else if (name == "treasure"){
        money = new Treasure(Config::MONEY_WIDTH,
                             Config::MONEY_HEIGHT,
                             pos, pixs2, scene);
    }

    money->setSpeed(Config::MONEY_SINK_SPEED);
    money->setDirection(Config::PI / 2);
    money->setPaintWidth(Config::MONEY_PAINT_WIDTH[name]);
    money->setPaintHeight(Config::MONEY_PAINT_HEIGHT[name]);

    return money;
}

AbstractPet *Factory::createPet(const QString &name,
                                const QPointF &pos,
                                QGraphicsScene *scene)
{
    QPixmaps2 pixs2;
    QPixmap pic(Config::PETS_PATH[name]);
    QPixmaps2 origins = PixmapsMaker::createQPixmaps(pic, 10, Config::ORIGIN_IMAGE_ROWS[name]);

    int width = Config::PETS_WIDTH;
    int height = Config::PETS_HEIGHT;

    if (Config::ORIGIN_IMAGE_ROWS[name] == 1){
        pixs2.append(origins.at(0));
    }

    else if (Config::ORIGIN_IMAGE_ROWS[name] >= 2){
        QPixmaps petSwimL;
        QPixmaps petSwimR;
        QPixmaps petTurnL;
        QPixmaps petTurnR;

        for (int i = 0; i < Config::PETS_INDEX_COUNT; i++){
            // PET_SWIM_LEFT_STATE
            petSwimL.append(origins.at(0).at(i)
                            .scaled(width, height,
                                    Qt::KeepAspectRatioByExpanding));

            // PET_SWIM_RIGHT_STATE
            QImage originImg = origins.at(0).at(i)
                    .toImage();
            QImage mirrored = originImg.mirrored(true, false);
            QPixmap temp = QPixmap::fromImage(mirrored)
                    .scaled(width, height,
                            Qt::KeepAspectRatioByExpanding);
            petSwimR.append(temp);

            // PET_TURN_LEFT_STATE
            petTurnL.append(origins.at(1).at(Config::PETS_INDEX_COUNT - i - 1)
                            .scaled(width, height,
                                    Qt::KeepAspectRatioByExpanding));

            // PET_TURN_RIGHT_STATE
            petTurnR.append(origins.at(1).at(i)
                            .scaled(width, height,
                                    Qt::KeepAspectRatioByExpanding));
        }
        pixs2.append(petSwimL);
        pixs2.append(petSwimR);
        pixs2.append(petTurnL);
        pixs2.append(petTurnR);
    }

    if (Config::ORIGIN_IMAGE_ROWS[name] >= 3){
        QPixmaps petSpecialL;
        QPixmaps petSpecialR;

        for (int i = 0; i < Config::PETS_INDEX_COUNT; i++){
            // PET_SPECIAL_LEFT
            petSpecialL.append(origins.at(2).at(i)
                               .scaled(width, height,
                                       Qt::KeepAspectRatioByExpanding));

            // PET_SPECIAL_RIGHT
            QImage originImg = origins.at(2).at(i)
                    .toImage();
            QImage mirrored = originImg.mirrored(true, false);
            QPixmap temp = QPixmap::fromImage(mirrored)
                    .scaled(width, height,
                            Qt::KeepAspectRatioByExpanding);
            petSpecialR.append(temp);
        }
        pixs2.append(petSpecialL);
        pixs2.append(petSpecialR);
    }

    AbstractPet * pet;
    if (name == "stinky"){
        pet = new Stinky(Config::PETS_WIDTH,
                         Config::PETS_HEIGHT,
                         pos, pixs2, scene);
    }
    else if (name == "vert"){
        pet = new Vert(Config::PETS_WIDTH,
                       Config::PETS_HEIGHT,
                       pos, pixs2, scene);
    }
    else if (name == "clyde"){
        pet = new Clyde(Config::PETS_WIDTH,
                        Config::PETS_HEIGHT,
                        pos, pixs2, scene);
    }

    pet->setSpeed(Config::PETS_SPEED[name]);
    pet->setDirection(RandomMaker::creatRandom(2) * Config::PI);
    pet->setPaintWidth(Config::PETS_PAINT_WIDTH[name]);
    pet->setPaintHeight(Config::PETS_PAINT_HEIGHT[name]);

    pet->updateDirection();

    return pet;
}

Btn *Factory::creatBtn(const QString &name, QGraphicsScene *scene)
{
    QPixmap pic(Config::BTNS_PATH[name]);
    QPixmaps2 pixs2;

    pixs2 = PixmapsMaker::createQPixmaps(pic, 3,
                                         Config::ORIGIN_IMAGE_ROWS[name]);

    Btn * btn = new Btn(name, Config::BTNS_INIT_POS[name],
                        Config::BTNS_WIDTH[name],
                        Config::BTNS_HEIGHT[name],
                        pixs2, scene);

    return btn;
}
