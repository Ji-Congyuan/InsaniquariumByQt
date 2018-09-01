#include "abstractmovableitem.h"

AbstractMovableItem::AbstractMovableItem(qreal w, qreal h, const QPointF &pos,
                                         qreal speed, const QPixmaps2 &pixs2,
                                         QGraphicsScene *scene, QGraphicsItem *parent)
    : AbstractGameItem(w, h, scene, parent),
      m_pos(pos), m_speed(speed),
      m_direction(RandomMaker::creatRandom(6)), m_pixStateIndex(0),
      m_hasTarget(false), m_target(nullptr)
{   
    for (int j = 0; j < pixs2.size(); ++j) {
        QPixmaps tempPixs;
        for (int i = 0; i < pixs2[0].size(); ++i) {
            QPixmap temp(pixs2.at(j).at(i));
            QPixmap t = temp.scaled(m_w, m_h, Qt::KeepAspectRatioByExpanding);
            tempPixs.append(t);
        }
        m_pixs2.append(tempPixs);
    }
    setPos(m_pos);
}

EDGE AbstractMovableItem::checkPos()
{
    if (scenePos().rx() <= 0) return LEFT;
    if (scenePos().ry() <= 0) return UP;
    if (scenePos().rx() + m_w >= Config::SCREEN_WIDTH) return RIGHT;
    if (scenePos().ry() + m_h >= Config::SCREEN_HEIGHT - Config::GROUND_HEIGHT) return DOWN;
    return INSIDE;
}
