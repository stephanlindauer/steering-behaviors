#ifndef MAP_H
#define MAP_H

#include "area.h"
#include "vector2d.h"
#include "bird.h"
#include "obstacle.h"

namespace steering_behaviors {

class Map : public Area {
public:

    explicit Map(const Vector2D position,
                 const Vector2D dimension,
                 const BirdVector birds,
                 const ObstacleVector obstacles):
        Area(position, dimension),
        m_birds(birds),
        m_obstacles(obstacles) {}

    const BirdVector & birds(void) const {
        return m_birds;
    }

    BirdVector & birds(void) {
        return m_birds;
    }

    const ObstacleVector & obstacles(void) const {
        return m_obstacles;
    }

    ObstacleVector & obstacles(void) {
        return m_obstacles;
    }

    /*void step(void) {
        for (int i = 0; i < m_birds.size(); i++)
    }*/

protected:
    BirdVector m_birds;
    ObstacleVector m_obstacles;

private:

};

}

#endif // MAP_H
