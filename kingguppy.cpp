#include "kingguppy.h"
#include <QSoundEffect>

KingGuppy::KingGuppy(qreal w, qreal h, const QPointF &pos,
                     const QPixmaps2 &pixs2, QGraphicsScene *scene,
                     QGraphicsItem *parent)
    : Guppy(w, h, pos, pixs2, scene, parent),
      m_name("kingGuppy")
{
    m_hungry = Config::FISH_INIT_HUNGRY[m_name];
    QSoundEffect *bornSound = new QSoundEffect;
    bornSound->setSource(QUrl::fromLocalFile(Config::SOUNDS_PATH["kingGuppySound"]));
    bornSound->setLoopCount(1);
    bornSound->play();
}

const QString &KingGuppy::name() const
{
    return m_name;
}

void KingGuppy::doCollide()
{
    Guppy::doCollide();
}

void KingGuppy::upgrade()
{
    // do nothing
}

void KingGuppy::yield()
{
    emit sgn_yieldMoney("diamond", scenePos());
}

void KingGuppy::advance(int)
{
    if (!isVisible())
    {
        return;
    }
    Guppy::advance(0);
}
