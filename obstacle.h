#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "object.h"

class Obstacle : public Object {
    public:
        Vector2D m_rectStartPoint;
        Vector2D m_rectEndPoint;
};

#endif // OBSTACLE_H
