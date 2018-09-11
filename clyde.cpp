#include "clyde.h"
#include "abstractmoney.h"

Clyde::Clyde(qreal w, qreal h, const QPointF &pos,
             const QPixmaps2 &pixs2, QGraphicsScene *scene,
             QGraphicsItem *parent)
    : AbstractPet(w, h, pos, pixs2, scene, parent),
      m_name("clyde")
{
}

const QString &Clyde::name() const
{
    return m_name;
}

void Clyde::move()
{
    if (!m_hasTarget){
        if (m_step % Config::CHANGE_DIRECTION_STEP == 0){
            setDirection(direction() + RandomMaker::creatRandom(-5, 6) / 40.0);
        }
    }
    else if (m_hasTarget){
        if (m_step % Config::CHASE_STEP == 0){
            aimAt(m_target);
        }
    }

    AbstractMovableItem::move();
    keepInScene();
}

void Clyde::doCollide()
{
    foreach (QGraphicsItem * t, collidingItems()) {
        AbstractGameItem * gameItem
                = dynamic_cast<AbstractGameItem *> (t);
        if (Config::COLLIDABLE_ITEMS[name()]
                .contains(gameItem->name())){
            AbstractMoney * money =
                    dynamic_cast<AbstractMoney *> (gameItem);
            connect(this, SIGNAL(sgn_pickMoney(int)),
                    money, SIGNAL(sgn_moneyPicked(int)));
            emit sgn_pickMoney(money->value());
            disconnect(this, SIGNAL(sgn_pickMoney(int)),
                       money, SIGNAL(sgn_moneyPicked(int)));
            money->vanish();
        }
    }
}

void Clyde::advance(int)
{
    AbstractMovableItem::advance(0);
    if (m_step % Config::UPDATE_PAINT_STEP == 0){
        updateDirection();
        m_pixIndex++;

        if (m_pixIndex == Config::PETS_INDEX_COUNT){
            m_pixIndex = 0;
        }

        move();
    }
    if (m_step % Config::FIND_TARGET_STEP == 0
            && !m_hasTarget){
        findTarget();
    }
}

void Clyde::findTarget()
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

void Clyde::yield()
{
    // do nothing
}
