#ifndef FACTORY_H
#define FACTORY_H

#include "deepblue.h"
#include "gus.h"

#include "smallguppy.h"
#include "middleguppy.h"
#include "bigguppy.h"
#include "kingguppy.h"
#include "carnivore.h"
#include "ulturavore.h"
#include "middlebreeder.h"
#include "bigbreeder.h"

#include "food.h"

#include "silver.h"
#include "gold.h"
#include "diamond.h"
#include "treasure.h"

#include "stinky.h"
#include "vert.h"
#include "clyde.h"
#include "prego.h"
#include "niko.h"

#include "btn.h"
#include "moneydisplayer.h"

#include <QImage>

class Factory
{
public:
    // pos is the point where the left top of image is
    static AbstractAlien * createAlien(const QString & name,
                                       const QPointF & pos,
                                       QGraphicsScene *scene);
    static AbstractFish * creatFish(const QString & name,
                                    const QPointF & pos,
                                    QGraphicsScene *scene);
    static Food * createFood(const QString & name,
                             const QPointF & pos,
                             QGraphicsScene * scene);
    static AbstractMoney * createMoney(const QString & name,
                                       const QPointF & pos,
                                       QGraphicsScene *scene);
    static AbstractPet * createPet(const QString & name,
                                   const QPointF & pos,
                                   QGraphicsScene *scene);
    static Btn * creatBtn(const QString & name,
                          QGraphicsScene *scene);
    /*
    static MoneyDisplayer * createDisplayer(const int digital,
                                            QGraphicsScene *scene);
    */
private:
    explicit Factory(){}
};

#endif // FACTORY_H
