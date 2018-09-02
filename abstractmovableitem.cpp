#include "abstractmovableitem.h"

AbstractMovableItem::AbstractMovableItem(qreal w, qreal h, const QPointF &pos,
                                         const QPixmaps2 &pixs2, QGraphicsScene *scene,
                                         QGraphicsItem *parent)
    : AbstractGameItem(w, h, scene, parent),
      m_pixStateIndex(0), m_hasTarget(false), m_target(nullptr),
      m_left(false), m_right(false), m_turning(false)
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
    setPos(pos);

    m_distance = sqrt(Config::SCREEN_WIDTH * Config::SCREEN_WIDTH +
                      Config::SCREEN_HEIGHT * Config::SCREEN_HEIGHT);
}

QRectF AbstractMovableItem::boundingRect() const
{
    return m_pixs2.at(0).at(0).rect();
}

QPainterPath AbstractMovableItem::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void AbstractMovableItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pixs2.at(m_pixStateIndex).at(m_pixIndex));
}

EDGE AbstractMovableItem::checkPos()
{
    if (scenePos().rx() <= 0) return LEFTEDGE;
    if (scenePos().ry() <= Config::POOL_UPPER_BOUND) return UPEDGE;
    if (scenePos().rx() + m_w >= Config::SCREEN_WIDTH) return RIGHTEDGE;
    if (scenePos().ry() + m_h >= Config::POOL_LOWER_BOUND) return DOWNEDGE;
    return INSIDE;
}

void AbstractMovableItem::advance(int)
{
    m_step++;
    if (m_step == 999999){
        m_step = 0;
    }
}

void AbstractMovableItem::move()
{
    QPointF pos = scenePos();
    pos.rx() += m_speed * cos(m_direction);
    pos.ry() += m_speed * sin(m_direction);
    setPos(pos);
}

qreal AbstractMovableItem::speed() const
{
    return m_speed;
}

qreal AbstractMovableItem::direction() const
{
    return m_direction;
}

void AbstractMovableItem::setSpeed(const qreal speed)
{
    m_speed = speed;
}

void AbstractMovableItem::setDirection(const qreal dir)
{
    m_direction = dir;
}

qreal AbstractMovableItem::calDistance(QPointF &pos)
{
    QPointF myPos = scenePos();
    return sqrt((myPos.rx() - pos.rx()) * (myPos.rx() - pos.rx()) +
                (myPos.ry() - pos.ry()) * (myPos.ry() - pos.ry()));
}

bool AbstractMovableItem::left() const
{
    return m_left;
}

bool AbstractMovableItem::right() const
{
    return m_right;
}

bool AbstractMovableItem::turning() const
{
    return m_turning;
}

void AbstractMovableItem::toLeft()
{
    m_left = true;
    m_right = false;
}

void AbstractMovableItem::toRight()
{
    m_left = false;
    m_right = true;
}

void AbstractMovableItem::turning(const bool turn)
{
    m_turning = turn;
}

void AbstractMovableItem::updateDirection()
{
    if (direction() < 0){
        setDirection(direction() + Config::PI * 2);
    }
    if (direction() > Config::PI * 2){
        setDirection(direction() - Config::PI * 2);
    }

    qreal dir = direction();
    if (dir <= Config::PI / 2 || dir > Config::PI * 3 / 2){
        if (left()){
            toRight();
            turning(true);
            m_pixIndex = 0;
        }
    }
    else if (dir > Config::PI / 2 && dir <= Config::PI * 3 / 2){
        if (right()){
            toLeft();
            turning(true);
            m_pixIndex = 0;
        }
    }
}

void AbstractMovableItem::vanish()
{
    setFlag(QGraphicsItem::ItemIsMovable, false);
    setVisible(false);
    deleteLater();
    // FIXME emit something
}
