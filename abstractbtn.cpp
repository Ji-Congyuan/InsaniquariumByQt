#include "abstractbtn.h"

AbstractBtn::AbstractBtn(qreal w, qreal h,
                         const QPixmaps &pixs,
                         QGraphicsScene *scene,
                         QGraphicsObject *parent)
    : AbstractGameItem(w, h, scene, parent)
{
    for (int i = 0; i < pixs.size(); ++i) {
        QPixmap temp = pixs.at(i);
        QPixmap t = temp.scaled(m_w, m_h,
                                Qt::KeepAspectRatioByExpanding);
        m_pixs.append(t);
    }
}
