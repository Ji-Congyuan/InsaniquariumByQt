#include "niko.h"

Niko::Niko(qreal w, qreal h, const QPointF &pos,
           const QPixmaps2 &pixs2, QGraphicsScene *scene,
           QGraphicsItem *parent)
    : AbstractPet(w, h, pos, pixs2, scene, parent),
      m_name("niko"), m_mature(false), m_harvested(false),
      m_gainable(false)
{
    m_openSound = new QSoundEffect;
    m_openSound->setSource(QUrl::fromLocalFile(Config::SOUNDS_PATH["nikoOpenSound"]));
    m_openSound->setLoopCount(1);

    m_closeSound = new QSoundEffect;
    m_closeSound->setSource(QUrl::fromLocalFile(Config::SOUNDS_PATH["nikoCloseSound"]));
    m_closeSound->setLoopCount(1);
}

Niko::~Niko()
{
    delete m_openSound;
    m_openSound = nullptr;
    delete m_closeSound;
    m_closeSound = nullptr;
}

const QString &Niko::name() const
{
    return m_name;
}

void Niko::move()
{
    // can't move
}

void Niko::doCollide()
{
    // won't collide
}

void Niko::advance(int)
{
    AbstractMovableItem::advance(0);
    if (m_step % Config::PETS_YIELD_STEP["niko"] == 0){
        m_mature = true;
        m_pixStateIndex = 0;
        m_pixIndex = 0;
        m_openSound->play();
    }
    if (m_step % Config::UPDATE_PAINT_STEP == 0){
        if (m_mature || m_harvested){
            m_pixIndex++;
            update();
        }
    }
    if (m_pixIndex == Config::PETS_INDEX_COUNT){
        if (m_mature){
            m_pixIndex--;
            m_gainable = true;
            m_mature = false;
        }
        else if (m_harvested){
            m_pixIndex--;
            m_harvested = false;
        }
    }
}

void Niko::findTarget()
{
    // no target
}

void Niko::yield()
{
    // do nothing
}

void Niko::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    if (m_gainable){
        m_gainable = false;
        m_harvested = true;
        m_pixStateIndex = 1;
        m_pixIndex = 0;
        m_step = 0;
        emit sgn_specialSkill("niko", scenePos());
        m_closeSound->play();
    }
}
