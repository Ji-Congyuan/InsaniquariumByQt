#include "moneydisplayer.h"
#include <QDebug>

MoneyDisplayer::MoneyDisplayer(QGraphicsScene *scene,
                               QGraphicsItem *parent)
    : AbstractGameItem(Config::NUMBERS_WIDTH,
                       Config::NUMBERS_HEIGHT,
                       scene, parent),
      m_name("moneyDisplay")
{
    m_pixIndex = 0;
    m_pixs = PixmapsMaker::createNumberPixs();
}

QRectF MoneyDisplayer::boundingRect() const
{
    return m_pixs.at(0).rect();
}

QPainterPath MoneyDisplayer::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void MoneyDisplayer::paint(QPainter *painter,
                         const QStyleOptionGraphicsItem *option,
                         QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pixs.at(m_pixIndex));
}

void MoneyDisplayer::setIndex(const int index)
{
    m_pixIndex = index;
}

void MoneyDisplayer::setDigital(const int digital)
{
    m_digital = digital;
}

const int MoneyDisplayer::digital() const
{
    return m_digital;
}

const QString &MoneyDisplayer::name() const
{
    return m_name;
}

void MoneyDisplayer::slt_moneyChanged(int money)
{
    switch (m_digital) {
    case 0:
        break;
    case 1:
        m_pixIndex = money / 10000;
        break;
    case 2:
        m_pixIndex = (money % 10000) / 1000;
        break;
    case 3:
        m_pixIndex = (money % 1000) / 100;
        break;
    case 4:
        m_pixIndex = (money % 100) / 10;
        break;
    case 5:
        m_pixIndex = money % 10;
        break;
    default:
        break;
    }
    update();
}
