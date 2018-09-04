#include "moneyfactory.h"


Money *MoneyFactory::createMoney(const QString &name,
                                 const QPointF &pos,
                                 QGraphicsScene *scene)
{
    QPixmaps2 pixs2;
    QPixmap pic(Config::MONEY_PATH);
    QPixmaps2 all = PixmapsMaker::createQPixmaps(pic, 10, 6);
    pixs2.append(all.at(Config::MONEY_INDEX[name]));

    Money * money;
    if (name == "silver"){
        money = new Silver(Config::MONEY_WIDTH,
                           Config::MONEY_HEIGHT,
                           pos, pixs2, scene);
    }

    money->setSpeed(Config::MONEY_SINK_SPEED);
    money->setDirection(Config::PI / 2);
    money->setPaintWidth(Config::MONEY_PAINT_WIDTH[name]);
    money->setPaintHeight(Config::MONEY_PAINT_HEIGHT[name]);

    return money;
}
