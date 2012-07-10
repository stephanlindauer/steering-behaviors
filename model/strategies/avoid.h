#ifndef AVOID_H
#define AVOID_H

#include "base.h"

namespace steering_behaviors {

class Avoid : public Base {

public:
    explicit Avoid(const int priority = 98):
        Base(priority) {}

protected:

    void applyObstacle(const Vector2D & position, Vector2D & velocity, const float speed, const Obstacle * obstacle) {












        ////////////////////////////////////////////////////////////////////////
        // if we move towards the object, the distance between us and object becomes smaller

        //float distance = position.dist(obstacle->position());
        //if (distance < position.add(velocity).dist(obstacle->position()))
        //distance becoming greater
        //return;

        // velocity.setAngle(velocity.getAngle() + 1.f);
        //        velocity = velocity.multiply(10.f);




    }

};

}

#endif // AVOID_H
