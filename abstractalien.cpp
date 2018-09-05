#include "abstractalien.h"
#include <QDebug>

AbstractAlien::AbstractAlien(qreal w, qreal h, const QPointF &pos,
                             const QPixmaps2 &pixs2, QGraphicsScene *scene,
                             QGraphicsItem *parent)
    : AbstractCreature(w, h, pos, pixs2, scene, parent),
      m_health(0)
{

}

void AbstractAlien::advance(int)
{
    AbstractCreature::advance(0);

    if (!isAlive()){ //vanish if die
        vanish();
        return;
    }

    if (m_step % Config::UPDATE_PAINT_STEP == 0){ // update action, direction and pos
        updateDirection();

        m_pixIndex++;
        if (m_pixIndex == Config::ALIEN_INDEX_COUNT){
            m_pixIndex = 0;

            if (turning()){ // finish turning
                turning(false);
            }
        }
        else if (turning() && isAlive()){
            if (right()){
                m_pixStateIndex = Config::ALIEN_TURN_RIGHT_STATE_INDEX;
            }
            else if (left()){
                m_pixStateIndex = Config::ALIEN_TURN_LEFT_STATE_INDEX;
            }
        }
        else if (isAlive()){
            if (left()){
                m_pixStateIndex = Config::ALIEN_SWIM_LEFT_STATE_INDEX;
            }
            else if (right()){
                m_pixStateIndex = Config::ALIEN_SWIM_RIGHT_STATE_INDEX;
            }
        }

        move();
    }

    if (m_step % Config::FIND_FOOD_STEP == 0
            && !m_hasTarget
            && isAlive()){
        findFood();
    }
}

void AbstractAlien::injured(const int deltaHealth)
{
    m_health -= deltaHealth;
}

void AbstractAlien::move()
{
    if (m_hasTarget){
        if (m_step % Config::CHASE_STEP == 0){
            aimAt(m_target);
            setDirection(direction()
                         + RandomMaker::creatRandom(-10, 11) / 40.0);
        }
    }
    else if (!m_hasTarget && !turning()){
        if (m_step % Config::CHANGE_DIRECTION_STEP == 0){
            setDirection(direction()
                         + RandomMaker::creatRandom(-5, 6) / 40.0);
        }
    }
    AbstractMovableItem::move();
    keepInScene();
}

void AbstractAlien::findFood()
{
    QList<QGraphicsItem*> items_ = scene()->items();
    QList<AbstractMovableItem*> edibleItems;
    foreach (QGraphicsItem * item, items_){
        AbstractGameItem * gameItem = dynamic_cast<AbstractGameItem *> (item);
        if (Config::COLLIDABLE_ITEMS[name()]
                .contains(gameItem->name())
                && gameItem->isVisible()){
            edibleItems.append(dynamic_cast<AbstractMovableItem *>(gameItem));
        }
    }
    if (edibleItems.size() > 0){
        m_target = edibleItems.at(RandomMaker::creatRandom(edibleItems.size()));
        m_hasTarget = true;

        connect(m_target, SIGNAL(sgn_deleting()),
                this, SLOT(slt_lostAim()));
    }
}

void AbstractAlien::die()
{
    if (!isVisible()){
        return;
    }
    AbstractCreature::die();
    emit sgn_alienDie();
    yield();
}

void AbstractAlien::yield()
{
    emit sgn_yieldMoney("diamond", scenePos());
}

void AbstractAlien::slt_attacked(const QPointF & pos)
{
    QPointF mPos = centrePos();
    setDirection(atan2(mPos.y() - pos.y(),
                       mPos.x() - pos.x()));
    injured(Config::ATTACK_ALIEN_DAMAGE);
}
