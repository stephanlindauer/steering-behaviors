#ifndef BIRD_H
#define BIRD_H

#include <QVector>

#include "vector2d.h"
#include "object.h"
#include "sector.h"

class Bird : public Object {
public:
    void process (const Sector sector);
    Vector2D m_velocity;
};

typedef QVector<Bird> BirdVector;
typedef BirdVector::iterator BirdPointer;

#endif // BIRD_H
