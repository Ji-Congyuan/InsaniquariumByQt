#include "psychosquid.h"
#include <QDebug>

Psychosquid::Psychosquid(qreal w, qreal h, const QPointF &pos,
                         const QPixmaps2 &pixs2, QGraphicsScene *scene,
                         QGraphicsItem *parent)
    : AbstractAlien(w, h, pos, pixs2, scene, parent),
      m_name("psychosquid"), m_recovering(false),
      m_firstRec(false), m_secRec(false)
{
    m_health = Config::ALIENS_MAX_HEALTH["psychosquid"];
    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()),
            this, SLOT(slt_finishRecovering()));
    m_timer->setSingleShot(true);
}

const QString &Psychosquid::name() const
{
    return m_name;
}

void Psychosquid::doCollide()
{
    if (!m_recovering){
        AbstractAlien::doCollide();
    }
}

void Psychosquid::eat(const int)
{
    // do nothing
}

void Psychosquid::findFood()
{
    if (!m_recovering){
        AbstractAlien::findFood();
    }
}

void Psychosquid::advance(int)
{
    AbstractAlien::advance(0);

    if (m_health <= Config::ALIENS_MAX_HEALTH["psychosquid"] * 2 / 3
            && !m_firstRec
            && !m_recovering){
        m_firstRec = true;
        m_recovering = true;
        m_timer->start(5000);
        m_hasTarget = false;
        m_target = nullptr;

    }
    if (m_health <= Config::ALIENS_MAX_HEALTH["psychosquid"] / 3
            && m_firstRec
            && !m_secRec
            && !m_recovering){
        m_secRec = true;
        m_recovering = true;
        m_timer->start(5000);
        m_hasTarget = false;
        m_target = nullptr;
    }
    if (m_health > Config::ALIENS_MAX_HEALTH["psychosquid"] * 2 / 3
            && m_firstRec){
        m_firstRec = false;
    }
    if (m_health > Config::ALIENS_MAX_HEALTH["psychosquid"] / 3
            && m_secRec){
        m_secRec = false;
    }
    if (m_step % Config::UPDATE_PAINT_STEP == 0
            && m_recovering){
        m_pixStateIndex += 4;
        if (m_pixStateIndex >= 8){
            m_pixStateIndex -= 4;
        }
    }

}

void Psychosquid::slt_finishRecovering()
{
    m_recovering = false;
    m_pixStateIndex -= 4;
    if (m_pixStateIndex < 0){
        m_pixStateIndex += 4;
    }
    update();
    findFood();
}

void Psychosquid::slt_attacked(const QPointF & pos)
{
    if (!m_recovering){
        AbstractAlien::slt_attacked(pos);
    } else {
        m_health += Config::ATTACK_ALIEN_DAMAGE;
    }
}
