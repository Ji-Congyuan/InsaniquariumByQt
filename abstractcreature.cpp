#include "abstractcreature.h"
#include <QDebug>

AbstractCreature::AbstractCreature(qreal w, qreal h, const QPointF &pos,
                                   const QPixmaps2 &pixs2, QGraphicsScene *scene,
                                   QGraphicsItem *parent)
    : AbstractMovableItem(w, h, pos, pixs2, scene, parent), m_alive(true)
{
}

void AbstractCreature::advance(int)
{
    AbstractMovableItem::advance(0);
}

void AbstractCreature::die()
{
    m_alive = false;
}

void AbstractCreature::move()
{

    if (!m_hasTarget && !turning() ){
        if (m_step % Config::CHANGE_DIRECTION_STEP == 0){
            setDirection(direction() + RandomMaker::creatRandom(-5, 6) / 40.0);
        }
    }

    AbstractMovableItem::move();
    QPointF pos = scenePos();

    // restrict in the scene
    switch (checkPos()) {
    case INSIDE:
        break;
    case UPEDGE:
        setDirection( 2 * Config::PI - direction());
        pos.ry() = Config::POOL_UPPER_BOUND - (height() - paintHeight()) / 2;
        break;
    case DOWNEDGE:
        setDirection( 2 * Config::PI - direction());
        pos.ry() = Config::POOL_LOWER_BOUND - (height() + paintHeight()) / 2;
        break;
    case LEFTEDGE:
        setDirection(Config::PI - direction());
        pos.rx() = - (width() - paintWidth()) / 2;
        m_pixIndex = 0;
        break;
    case RIGHTEDGE:
        setDirection(Config::PI - direction());
        pos.rx() = Config::SCREEN_WIDTH - (width() + paintWidth()) / 2;
        m_pixIndex = 0;
        break;
    default:
        break;
    }

    setPos(pos);

}

bool AbstractCreature::isAlive()
{
    return m_alive;
}

