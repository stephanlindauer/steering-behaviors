#ifndef FLEE_H
#define FLEE_H

#include "base.h"

namespace steering_behaviors {

class Flee : public Base {

public:
    explicit Flee(const int priority = 99):
        Base(priority) {}

protected:

    void applyObstacle(const Vector2D & position, Vector2D & velocity, const float speed, const Obstacle * obstacle) {
        // if we move towards the object, the distance between us and object becomes smaller

        float distance = position.dist(obstacle->position());
        if (distance < position.add(velocity).dist(obstacle->position()))
            // distance becoming greater
            return;

        velocity.setAngle(velocity.getAngle() + 0.0174f   );
//        velocity = velocity.multiply(10.f);




    }

};

}

#endif // FLEE_H
