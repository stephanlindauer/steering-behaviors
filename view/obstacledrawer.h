#ifndef OBSTACLEDRAWER_H
#define OBSTACLEDRAWER_H

#include <QGraphicsScene>
#include "drawer.h"
#include "model/obstacle.h"

namespace steering_behaviors {

class ObstacleDrawer : public Drawer {
public:
    explicit ObstacleDrawer(const Obstacle & obstacle):
        Drawer(),
        m_obstacle(obstacle),
        m_rectangle(NULL){}

    ~ObstacleDrawer() {
        if (m_rectangle != NULL)
            delete m_rectangle;
    }

    void draw (QGraphicsScene * scene) {
        drawn();
        const Vector2D & position = m_obstacle.position();
        const Vector2D & dimension = m_obstacle.dimension();

        if (m_rectangle != NULL) {
            // re-use existing rectangle
            m_rectangle->setRect(Drawer::x(position),
                                 Drawer::y(position),
                                 Drawer::x(dimension),
                                 Drawer::y(dimension));
            return;
        }

        // create new recangle
        QPen pen(Qt::black);
        QBrush brush(Qt::white);
        m_rectangle = scene->addRect(Drawer::x(position), Drawer::y(position), Drawer::x(dimension), Drawer::y(dimension), pen, brush);
    }

    const Obstacle & obstacle(void) const {
        return m_obstacle;
    }

protected:

private:

    const Obstacle & m_obstacle;
    QGraphicsRectItem * m_rectangle;

};

}


#endif // OBSTACLEDRAWER_H
