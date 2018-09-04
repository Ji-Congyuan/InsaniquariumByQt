#include "foodfactory.h"
#include <QDebug>

Food *FoodFactory::createFood(const QString &name,
                              const QPointF &pos,
                              QGraphicsScene *scene)
{
    QPixmaps2 pixs2;
    QPixmap pic(Config::FOODS_PATH);
    QPixmaps2 all = PixmapsMaker::createQPixmaps(pic, 10, 5);
    pixs2.append(all.at(Config::FOODS_INDEX[name]));

    Food * food;
    if (name == "smallFood"){
        food = new Food(Config::FOODS_WIDTH,
                        Config::FOODS_HEIGHT,
                        pos, pixs2, scene);
    }

    food->setSpeed(Config::FOOD_SINK_SPEED);
    food->setDirection(Config::PI / 2);
    food->setPaintWidth(Config::FOODS_PAINT_WIDTH[name]);
    food->setPaintHeight(Config::FOODS_PAINT_HEIGHT[name]);
    food->setEatenExp(Config::FOODS_EXP[name]);

    return food;
}
