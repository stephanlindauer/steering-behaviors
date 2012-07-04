#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QVector>

#include "object.h"

class Obstacle : public Object {
public:
    typedef QVector<Obstacle> ObstacleVector;

    Vector2D dimension;
};

#endif // OBSTACLE_H
