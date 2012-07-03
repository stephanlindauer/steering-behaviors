#ifndef OBSTACLEDRAWER_H
#define OBSTACLEDRAWER_H

#include <QtGui>
#include <vector2d.h>

class ObstacleDrawer : public Drawer {
public:
    ObstacleDrawer(const Obstacle & obstacle):
        m_obstacle(obstacle) {}

    void draw(const QGraphicsScene * scene) {
     //TODO
    }

private:
    const Obstacle & m_obstacle;
};

#endif // OBSTACLEDRAWER_H
