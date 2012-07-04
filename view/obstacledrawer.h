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
        m_obstacle(obstacle) {}

    void draw (QGraphicsScene * scene) {

    }

    const Obstacle & obstacle(void) const {
        return m_obstacle;
    }

protected:

private:

    const Obstacle & m_obstacle;

};

}


#endif // OBSTACLEDRAWER_H
