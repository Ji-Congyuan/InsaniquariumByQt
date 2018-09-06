#include "btn.h"

Btn::Btn(const QString &name,
         const QPointF &pos,
         qreal w, qreal h,
         const QPixmaps2 &pixs2,
         QGraphicsScene *scene,
         QGraphicsObject *parent)
    : AbstractGameItem(w, h, scene, parent),
      m_name(name), m_pixStateIndex(0)
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

QRectF Btn::boundingRect() const
{
    return m_pixs2.at(0).at(0).rect();
}

QPainterPath Btn::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Btn::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pixs2.
                        at(m_pixStateIndex).
                        at(m_pixIndex));
}

const QString &Btn::name() const
{
    return m_name;
}

void Btn::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        event->accept();
        m_pixIndex = Config::PRESSED_BTN_INDEX;
        if (name() == "moreFoodBtn"){
            if (m_pixStateIndex < Config::MORE_FOOD_STATE_COUNT - 1){
                m_pixStateIndex++;
            }
        }
        else if (name() == "eggBtn"){
            if (m_pixStateIndex < Config::EGG_STATE_COUNT - 1){
                m_pixStateIndex++;
            }
        }
        update();
        emit sgn_btnClicked(m_name);
    } else {
        event->ignore();
    }
}

void Btn::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    event->accept();
    m_pixIndex = Config::HOVER_BTN_INDEX;
    update();
}

void Btn::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    event->accept();
    m_pixIndex = Config::HOVER_BTN_INDEX;
    update();
}

void Btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    event->accept();
    m_pixIndex = Config::DEFAULT_BTN_INDEX;
    update();
}
