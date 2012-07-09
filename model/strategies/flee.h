#ifndef FLEE_H
#define FLEE_H

#include "base.h"

namespace steering_behaviors {

class Flee : public Base {

protected:

    /*void applyBird(const Vector2D & position, Vector2D & velocity, const Bird * bird) {
        // do not flee from other birds
    }*/

    void applyObstacle(const Vector2D & position, Vector2D & velocity, const Obstacle * obstacle) {
        // if we move towards the object, the distance between position and object becomes smaller
        float distance = position.dist(obstacle->position());
        if (distance > position.add(velocity).dist(obstacle->position()))
            velocity.setAngle(velocity.getAngle() + 1.f);
    }

};

}

#endif // FLEE_H
