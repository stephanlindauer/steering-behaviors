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

        // iterate over each bird/obstacle,find their drawer and let it draw

        for (int i = 0; i < m_map.birds().size(); i++) {
            Bird & bird = m_map.birds()[i];
            m_birdDrawers[&bird]->draw(scene);
        }

        for (int i = 0; i < m_map.obstacles().size(); i++) {
            Obstacle & obstacle = m_map.obstacles()[i];
            m_obstacleDrawers[&obstacle]->draw(scene);
        }

        conditionalRemove();
    }

    BirdDrawer * birdDrawer(Bird * bird) {
        if (m_birdDrawers.contains(bird))
            return m_birdDrawers[bird];

        return NULL;
    }

protected:

private:

    Map & m_map;
    QMap<Bird *, BirdDrawer *> m_birdDrawers;
    QMap<Obstacle *, ObstacleDrawer *> m_obstacleDrawers;

    void conditionalInsert(void) {
        // for each bird/obstacle test if there is already a drawer; if not add it
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
        // for each BirdDrawer/ObstacleDrawer
        // test if it has that has been drawn:
        // if it has been, reset the drawers drawn-flag;
        // else remove it's appropriate drawer;

        {
            QList<Bird *> keys = m_birdDrawers.uniqueKeys();
            for (int i = 0; i < keys.size(); i++) {
                Bird * bird = keys[i];
                BirdDrawer * birdDrawer = m_birdDrawers[bird];
                if (birdDrawer->hasBeenDrawn()) {
                    birdDrawer->reset();
                    continue;
                }

                m_birdDrawers.remove(bird);
                delete birdDrawer;
            }
        }

        {
            QList<Obstacle *> keys = m_obstacleDrawers.uniqueKeys();
            for (int i = 0; i < keys.size(); i++) {
                Obstacle * obstacle = keys[i];
                ObstacleDrawer * obstacleDrawer = m_obstacleDrawers[obstacle];
                if (obstacleDrawer->hasBeenDrawn()) {
                    obstacleDrawer->reset();
                    continue;
                }

                m_obstacleDrawers.remove(obstacle);
                delete obstacleDrawer;
            }
        }
    }

};

}

#endif // MAPDRAWER_H
