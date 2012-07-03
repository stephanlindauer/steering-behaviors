#ifndef BIRD_H
#define BIRD_H

#include "vector2d.h"
#include "object.h"

class Bird : public Object {
public:
    Vector2D m_velocity;
};

#endif // BIRD_H
