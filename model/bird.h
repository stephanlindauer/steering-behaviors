#ifndef BIRD_H
#define BIRD_H

#include <QVector>

#include "object.h"
#include "vector2d.h"
//#include "strategy.h" // TODO

namespace steering_behaviors {

class Bird : public Object {

public:

    explicit Bird():
        Object(Vector2D()),
        m_velocity(Vector2D()) {}

    explicit Bird (const Vector2D position,
                   const Vector2D velocity):
        Object(position),
        m_velocity(velocity) {}

    const Vector2D & velocity(void) const {
        return m_velocity;
    }

    Vector2D & velocity(void) {
        return m_velocity;
    }

protected:

    Vector2D m_velocity;
    // Strategy m_strategy // TODO

private:

};

typedef QVector<Bird> BirdVector;

}

#endif // BIRD_H
