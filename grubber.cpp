#include "grubber.h"
#include <QDebug>

Grubber::Grubber(qreal w, qreal h, const QPointF &pos,
                 const QPixmaps2 &pixs2, QGraphicsScene *scene,
                 QGraphicsItem *parent)
    : AbstractFish(w, h, pos, pixs2, scene, parent),
      m_name("grubber"), m_upping(false), m_downing(true)
{
    m_hungry = Config::FISH_INIT_HUNGRY[m_name];
}

void Grubber::advance(int)
{
    if (!isVisible()){
        return;
    }
    AbstractCreature::advance(0);

    if (m_step % Config::UPDATE_PAINT_STEP == 0){
        m_pixIndex++;
        if (m_pixIndex == Config::FISH_INDEX_COUNT){
            m_pixIndex = 0;
            if (!isAlive()){
                if(isVisible()){
                    vanish();
                    return;
                }
            }
        }
        if (willDie()){
            m_pixStateIndex = Config::GRUBBER_DIE_STATE_INDEX;
            m_pixIndex = 0;
            m_willDie = false;
        }
        else if (isAlive()){
            m_pixStateIndex = Config::GRUBBER_MOVE_STATE_INDEX;
        }
        if (isAlive() && isHungry()){
            m_pixStateIndex = Config::GRUBBER_HUNGRY_STATE_INDEX;
        }
        if (!isAlive()){
            update();
        }
        move();
    }
    if (m_step % Config::FIND_FOOD_STEP == 0
            && !m_hasTarget
            && !isFull()
            && isAlive()){
        findFood();
    }
    if (m_step % Config::HUNGRY_STEP == 0
            && isAlive()){
        gettingHungry();
    }
    if (m_step % Config::FISH_YIELD_STEP[name()] == 0
            && isAlive()){
        yield();
    }
}

void Grubber::doCollide()
{
    if (!m_hasTarget){
        return;
    }
    foreach (QGraphicsItem * t, collidingItems()) {
        AbstractGameItem * gameItem
                = dynamic_cast<AbstractGameItem *> (t);
        if (Config::COLLIDABLE_ITEMS[name()]
                .contains(gameItem->name())){
            AbstractFish * fish = dynamic_cast<AbstractFish *> (gameItem);
            eat(fish->eatenExp());
            fish->vanish();
            m_downing = true;
            m_upping = false;
        }
    }
}

void Grubber::findFood()
{
    if (m_downing){
        return;
    }
    QList<QGraphicsItem*> items_ = scene()->items();
    QVector<AbstractMovableItem*> edibleItems;
    foreach (QGraphicsItem * item, items_) {
        AbstractGameItem * gameItem
                = dynamic_cast<AbstractGameItem *> (item);
        if (Config::COLLIDABLE_ITEMS[name()]
                .contains(gameItem->name())
                && gameItem->isVisible()){
            QPointF aimPos = gameItem->scenePos();
            if (scenePos().y() - aimPos.y() < Config::GRUBBER_JUMP_MAX_HEIGHT
                    && abs(scenePos().x() - aimPos.x()) < 40){
                edibleItems.append(dynamic_cast<AbstractMovableItem *>(gameItem));
            }
        }
    }
    if (edibleItems.size() > 0){
        m_target = edibleItems.at(RandomMaker::creatRandom(edibleItems.size()));
        m_hasTarget = true;

        connect(m_target, SIGNAL(sgn_deleting()),
                this, SLOT(slt_lostAim()));
    }
}

const QString &Grubber::name() const
{
    return m_name;
}

void Grubber::upgrade()
{
    // do nothing
}

void Grubber::yield()
{
    emit sgn_yieldMoney("insect", scenePos());
}

void Grubber::move()
{
    if (isAlive()){
        if (m_hasTarget){
            m_upping = true;
            m_downing = false;
        }
        if (m_upping
                && scenePos().y() < Config::GRUBBER_POS_Y - Config::GRUBBER_JUMP_MAX_HEIGHT){
            m_upping = false;
            m_downing = true;
            m_hasTarget = false;
            m_target = nullptr;
        }
        if (m_upping){
            setSpeed(Config::GRUBBER_JUMP_SPEED);
            setDirection(Config::PI * 3 / 2);
            AbstractCreature::move();
        }
        else if (m_downing){
            setSpeed(Config::GRUBBER_JUMP_SPEED);
            setDirection(Config::PI / 2);
            if (scenePos().y() >= Config::GRUBBER_POS_Y){
                m_downing = false;
            }
            AbstractCreature::move();
        }
        else if (!m_upping && !m_downing){
            if (m_step % Config::CHANGE_DIRECTION_STEP == 0){
                setDirection(direction() + RandomMaker::creatRandom(-5, 6) / 40.0);
            }
            updateDirection();
            setSpeed(Config::FISH_SPEED["grubber"]);
            QPointF pos = scenePos();
            pos.ry() = Config::GRUBBER_POS_Y;
            pos.rx() += m_speed * (left() ? -1 : 1);
            setPos(pos);
            keepInScene();
        }

    }
}
