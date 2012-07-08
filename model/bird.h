#ifndef BIRD_H
#define BIRD_H

//#include "stdio.h"

#include <QVector>

#include "object.h"
#include "vector2d.h"
//#include "strategy.h" // TODO

namespace steering_behaviors {

class Bird : public Object {

    static const int MAX_SPEED = 15;

    static float randSpeed(void) {
        const int r1 = (rand() % MAX_SPEED) - MAX_SPEED;
        const int r2 = (rand() % MAX_SPEED) - MAX_SPEED;
        return (float) (r1 + 1) / (float) (r2 == 0 ? 1 : r2);
    }

public:

    explicit Bird():
        Object(Vector2D()),
        m_velocity(Vector2D()) {}

    explicit Bird (const Vector2D position,
                   const Vector2D velocity = Vector2D(randSpeed(),
                                                      randSpeed())):
        Object(position),
        m_velocity(velocity) {
        //printf("v: (%2f|%2f)\n", m_velocity.x(), m_velocity.y());
    }

    const Vector2D & velocity(void) const {
        return m_velocity;
    }

    Vector2D & velocity(void) {
        return m_velocity;
    }

protected:

    Vector2D m_velocity;
    // Strategy m_strategy; // TODO

private:

};

typedef QVector<Bird> BirdVector;

}

#endif // BIRD_H
