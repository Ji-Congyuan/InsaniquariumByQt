#include "fishfactory.h"
#include <QDebug>

AbstractFish *FishFactory::creatFish(const QString &name,
                                     const QPointF &pos,
                                     QGraphicsScene *scene)
{
    QPixmaps2 pixs2;
    QPixmap pic(Config::FISH_PATH[name]);
    QPixmaps2 origins = PixmapsMaker::createQPixmaps(pic, 10, 5);

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

    fish->setSpeed(Config::FISH_SPEED[name]);
    fish->setDirection(RandomMaker::creatRandom(-314, 314) / 100.0);
    fish->setPaintWidth(Config::FISH_PAINT_WIDTH[name]);
    fish->setPaintHeight(Config::FISH_PAINT_HEIGHT[name]);   
    fish->setEatenExp(Config::FISH_EATEN_EXP[name]);

    fish->updateDirection();

    return fish;
}
