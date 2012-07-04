#ifndef MAPDRAWER_H
#define MAPDRAWER_H

#include <QGraphicsScene>
#include <QMap>

#include "drawer.h"
#include "birddrawer.h"
#include "obstacledrawer.h"

#include "model/bird.h"
#include "model/obstacle.h"
#include "model/map.h"


namespace steering_behaviors {

class MapDrawer : public Drawer {
public:
    explicit MapDrawer(Map & map):
        m_map(map) {
        conditionalInsert();
    }

    void draw (QGraphicsScene * scene) {
        conditionalInsert();

        // TODO:
        // iterate over each m_map.birds(),
        // find their drawer,
        // let it draw it

        conditionalRemove();
    }

protected:

private:

    Map & m_map;
    QMap<Bird *, BirdDrawer *> m_birdDrawers;
    QMap<Obstacle *, ObstacleDrawer *> m_obstacleDrawers;

    void conditionalInsert(void) {
        for (int i = 0; i < m_map.birds().size(); i++) {
            Bird & bird = m_map.birds()[i];
            if (!m_birdDrawers.contains(&bird)) {
                m_birdDrawers.insert(&bird, new BirdDrawer(bird));
            }
        }

        for (int i = 0; i < m_map.obstacles().size(); i++) {
            Obstacle & obstacle = m_map.obstacles()[i];
            if (!m_obstacleDrawers.contains(&obstacle)) {
                m_obstacleDrawers.insert(&obstacle, new ObstacleDrawer(obstacle));
            }
        }
    }

    void conditionalRemove(void) {
        // TODO
        // find each bird/obstacle that hasn't been drawn
        // and remove it's appropriate drawer;
        // afterwars reset each birds/obstacles drawers drawn-flag
    }

};

}

#endif // MAPDRAWER_H
