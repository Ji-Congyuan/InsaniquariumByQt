#include "abstractmovableitem.h"
#include <QDebug>

AbstractMovableItem::AbstractMovableItem(qreal w, qreal h, const QPointF &pos,
                                         const QPixmaps2 &pixs2, QGraphicsScene *scene,
                                         QGraphicsItem *parent)
    : AbstractGameItem(w, h, scene, parent),
      m_pixStateIndex(0), m_hasTarget(false), m_target(nullptr),
      m_left(false), m_right(false), m_turning(false), m_eatenExp(0)
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
}

QRectF AbstractMovableItem::boundingRect() const
{
    QRectF outerRect = m_pixs2.at(0).at(0).rect();
    qreal outerX = outerRect.x();
    qreal outerY = outerRect.y();
    qreal outerWidth = outerRect.width();
    qreal outerHeight = outerRect.height();
    qreal innerX = outerX + outerWidth / 2 - paintWidth() / 2;
    qreal innerY = outerY + outerHeight / 2 - paintHeight() / 2;
    return QRectF(innerX, innerY, paintWidth(), paintHeight());
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
    if (!isVisible()) return INSIDE;
    if (scenePos().rx() + (width()  - paintWidth()) / 2  <= 0) return LEFTEDGE;
    if (scenePos().ry() + (height() - paintHeight()) / 2 <= Config::POOL_UPPER_BOUND) return UPEDGE;
    if (scenePos().rx() + (width()  + paintWidth()) / 2  >= Config::SCREEN_WIDTH) return RIGHTEDGE;
    if (scenePos().ry() + (height() + paintHeight()) / 2 >= Config::POOL_LOWER_BOUND) return DOWNEDGE;
    return INSIDE;
}

void AbstractMovableItem::advance(int)
{
    doCollide();
    m_step++;
    if (m_step == 999999){
        m_step = 0;
    }
}

void AbstractMovableItem::aimAt(AbstractMovableItem *target)
{
    if (target == Q_NULLPTR){ // target doesn't exist
        m_hasTarget = false;
    } else {
        qreal tx = target->centrePos().x();
        qreal ty = target->centrePos().y();
        qreal mx = centrePos().x();
        qreal my = centrePos().y();
        qreal dir = atan2(ty - my, tx - mx);
        if (dir < 0){
            dir += Config::PI * 2;
        }
        setDirection(dir);
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

void AbstractMovableItem::setPaintWidth(const qreal w)
{
    m_paintWidth = w;
}

void AbstractMovableItem::setPaintHeight(const qreal h)
{
    m_paintHeight = h;
}

void AbstractMovableItem::setState(const int state)
{
    m_pixStateIndex = state;
}

qreal AbstractMovableItem::paintWidth() const
{
    return m_paintWidth;
}

qreal AbstractMovableItem::paintHeight() const
{
    return m_paintHeight;
}

void AbstractMovableItem::setEatenExp(const int e)
{
    m_eatenExp = e;
}

int AbstractMovableItem::eatenExp() const
{
    return m_eatenExp;
}

void AbstractMovableItem::slt_lostAim()
{
    m_hasTarget = false;
    m_target = Q_NULLPTR;
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
        if (!right()){
            toRight();
            turning(true);
            m_pixIndex = 0;
        }
    }
    else if (dir > Config::PI / 2 && dir <= Config::PI * 3 / 2){
        if (!left()){
            toLeft();
            turning(true);
            m_pixIndex = 0;
        }
    }
}

void AbstractMovableItem::vanish()
{    
    setVisible(false);
    emit sgn_deleting();
    setPos(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT);
    setFlag(QGraphicsItem::ItemIsMovable, false);

    // scene()->removeItem(this);

    // delete this;

}

QPointF AbstractMovableItem::centrePos()
{
    QPointF leftTop = scenePos();
    QPointF center;
    center.rx() = leftTop.rx() + width() / 2;
    center.ry() = leftTop.ry() + height() / 2;
    return center;
}

void AbstractMovableItem::keepInScene()
{
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
