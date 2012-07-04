#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QVector>

#include "area.h"
#include "vector2d.h"

namespace steering_behaviors {

class Obstacle : public Area {

public:

    explicit Obstacle():
        Area(Vector2D(), Vector2D()) {}

    explicit Obstacle(const Vector2D position,
                      const Vector2D dimension):
        Area(position, dimension) {}

protected:

private:

};

typedef QVector<Obstacle> ObstacleVector;

}

#endif // OBSTACLE_H
