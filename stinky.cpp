#include "stinky.h"
#include <QDebug>

Stinky::Stinky(qreal w, qreal h, const QPointF &pos,
               const QPixmaps2 &pixs2, QGraphicsScene *scene,
               QGraphicsItem *parent)
    : AbstractPet(w, h, pos, pixs2, scene, parent),
      m_name("stinky"), m_hiding(false)
{
}

const QString &Stinky::name() const
{
    return m_name;
}

void Stinky::move()
{
    if (!m_hasTarget && !turning()){
        if (m_step % Config::CHANGE_DIRECTION_STEP == 0){
            setDirection(direction() + RandomMaker::creatRandom(-5, 6) / 40.0);
        }
    }
    else if (m_hasTarget){
        if (m_step % Config::CHASE_STEP == 0){
            aimAt(m_target);
        }
    }

    QPointF pos = scenePos();
    pos.ry() = Config::POOL_LOWER_BOUND - height() - 5;
    pos.rx() += m_speed * (left() ? -1 : 1);
    setPos(pos);
    keepInScene();
}

void Stinky::doCollide()
{
    foreach (QGraphicsItem * t, collidingItems()) {
        AbstractMovableItem * movableItem
                = dynamic_cast<AbstractMovableItem *> (t);
        if (Config::COLLIDABLE_ITEMS[name()]
                .contains(movableItem->name())){
            AbstractMoney * money =
                    dynamic_cast<AbstractMoney *> (movableItem);
            connect(this, SIGNAL(sgn_pickMoney(int)),
                    money, SIGNAL(sgn_moneyPicked(int)));
            emit sgn_pickMoney(money->value());
            disconnect(this, SIGNAL(sgn_pickMoney(int)),
                       money, SIGNAL(sgn_moneyPicked(int)));
            money->vanish();
        }
    }
}

void Stinky::advance(int)
{
    AbstractPet::advance(0);

    if (m_step % Config::FIND_TARGET_STEP == 0
            && !m_hasTarget){
        findTarget();
    }

    if (m_hiding){
        if (left()){
            m_pixStateIndex = Config::PETS_SPECIAL_LEFT_STATE_INDEX;
        }
        else if (right()){
            m_pixStateIndex = Config::PETS_SPECIAL_RIGHT_STATE_INDEX;
        }
        m_pixIndex = 9;
        setSpeed(0);
    }
}

void Stinky::findTarget()
{
    QList<QGraphicsItem *> items_ = scene()->items();
    QVector<AbstractMoney *> money;
    foreach (QGraphicsItem * item, items_) {
        AbstractGameItem * gameItem
                = dynamic_cast<AbstractGameItem *> (item);
        if (Config::COLLIDABLE_ITEMS[name()]
                .contains(gameItem->name())
                && gameItem->isVisible()){
            money.append(dynamic_cast<AbstractMoney *>(gameItem));
        }
    }
    if (money.size() > 0){
        m_target = money.at(RandomMaker::creatRandom(money.size()));
        m_hasTarget = true;

        connect(m_target, SIGNAL(sgn_deleting()),
                this, SLOT(slt_lostAim()));
    }
}

void Stinky::yield()
{
    // do nothing
}

void Stinky::slt_specialSkill()
{
    // do nothing
}

void Stinky::slt_alienComes(const QString &)
{
    m_hiding = true;
}

void Stinky::slt_alienDies()
{
    m_hiding = false;
    setSpeed(Config::PETS_SPEED["stinky"]);
}

