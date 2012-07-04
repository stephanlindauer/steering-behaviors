#ifndef BIRDDRAWER_H
#define BIRDDRAWER_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QBrush>

#include "drawer.h"
#include "util.h"
#include "model/bird.h"
#include "model/vector2d.h"

namespace steering_behaviors {

class BirdDrawer : public Drawer {

    static const qreal WIDTH = 5;
    static const qreal HEIGHT = 5;

public:
    explicit BirdDrawer(const Bird & bird):
        Drawer(),
        m_bird(bird) {}

    void draw (QGraphicsScene * scene) {
        drawn();
        const Vector2D & position = m_bird.position();

        if (m_ellipse != NULL) {
            // re-use existing ellipse
            m_ellipse->setX(Drawer::x(position));
            m_ellipse->setY(Drawer::y(position));
            return;
        }

        // create new ellipse
        QPen pen(random());
        QBrush brush(random());
        m_ellipse = scene->addEllipse(Drawer::x(position), Drawer::y(position), WIDTH, HEIGHT, pen, brush);
    }

    const Bird & bird(void) const {
        return m_bird;
    }

protected:

private:

    const Bird & m_bird;
    QGraphicsEllipseItem * m_ellipse;

};

}

#endif // BIRDDRAWER_H
