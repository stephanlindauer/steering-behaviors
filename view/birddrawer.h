#ifndef BIRDDRAWER_H
#define BIRDDRAWER_H

#include <stdio.h>

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QBrush>

#include "drawer.h"
#include "qtutil.h"
#include "model/bird.h"
#include "model/vector2d.h"

namespace steering_behaviors {

class BirdDrawer : public Drawer {

public:

    static const qreal WIDTH = 10;
    static const qreal HEIGHT = 10;

    explicit BirdDrawer(const Bird & bird):
        Drawer(),
        m_bird(bird),
        m_ellipse(NULL) {}

    ~BirdDrawer() {
        if (m_ellipse != NULL)
            delete m_ellipse;
    }

    void draw (QGraphicsScene * scene) {
        drawn();
        const Vector2D & position = m_bird.position();

        const qreal x = Drawer::x(position);
        const qreal y = Drawer::y(position);

        if (m_ellipse != NULL) {
            // re-use existing ellipse
            m_ellipse->setX(x);
            m_ellipse->setY(y);
            return;
        }

        // create new ellipse
        QPen pen(randomColor());
        QBrush brush(randomColor());
        m_ellipse = scene->addEllipse(0, 0, WIDTH, HEIGHT, pen, brush);
        m_ellipse->setX(x);
        m_ellipse->setY(y);
    }

    const Bird & bird(void) const {
        return m_bird;
    }

    QGraphicsEllipseItem * item(void) const {
        return m_ellipse;
    }

protected:

private:

    const Bird & m_bird;
    QGraphicsEllipseItem * m_ellipse;

};

}

#endif // BIRDDRAWER_H
