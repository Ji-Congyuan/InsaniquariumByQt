#include "alienfactory.h"

AbstractAlien *AlienFactory::createAlien(const QString &name,
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

    alien->setSpeed(Config::ALIENS_SPEED[name]);
    alien->setDirection(RandomMaker::creatRandom(-314, 314) / 100.0);
    alien->setPaintWidth(Config::ALIENS_PAINT_WIDTH[name]);
    alien->setPaintHeight(Config::ALIENS_PAINT_HEIGHT[name]);

    alien->updateDirection();

    return alien;
}
