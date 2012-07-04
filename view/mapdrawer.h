#ifndef MAPDRAWER_H
#define MAPDRAWER_H

#include <QtGui>
#include <birddrawer.h>
#include <obstacledrawer.h>
#include <map.h>

class MapDrawer : public Drawer
{
public:

    MapDrawer(QVector birds , QVector obstacles, Map map) :
        m_birds(birds),
        m_obstacles(obstacles),
        m_map(map){}


    void draw (const QGraphicsScene *scene){
        for (int i = 0; i < m_birds.size(); i++) {
            m_birds[i].draw(scene);
        }
        for (int j = 0; j < m_obstacles.size(); j++) {
            m_obstacles[i].draw(scene);
        }
    }

private:
        QVector<BirdDrawer> m_birds ;
        QVector<ObstacleDrawer> m_obstacles;
        Map m_map;
};


#endif // MAPDRAWER_H
