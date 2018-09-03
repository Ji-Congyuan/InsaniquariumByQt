#include "menubtn.h"
#include <QDebug>

MenuBtn::MenuBtn(const QString & name,
                 qreal pos_x, qreal pos_y,
                 qreal w, qreal h,
                 const QPixmaps &pixs,
                 QGraphicsScene *scene,
                 QGraphicsObject *parent)
    : AbstractBtn(w, h, pixs, scene, parent),
      m_name(name)
{
    setPos(pos_x, pos_y);
}

QRectF MenuBtn::boundingRect() const
{
    return m_pixs.at(0).rect();
}

QPainterPath MenuBtn::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void MenuBtn::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pixs.at(m_pixIndex));
}

const QString & MenuBtn::name() const
{
    return m_name;
}

void MenuBtn::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        event->accept();
        m_pixIndex = Config::PRESSED_MENU_BTN_INDEX;
        update();
        emit sgn_startGame();
    } else {
        event->ignore();
    }
}

void MenuBtn::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    event->accept();
    m_pixIndex = Config::HOVER_MENU_BTN_INDEX;
    update();
}

void MenuBtn::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    event->accept();
    m_pixIndex = Config::DEFAULT_MENU_BTN_INDEX;
    update();
}

