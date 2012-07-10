#ifndef FOLLOW_H
#define FOLLOW_H

#include <typeinfo>

#include "base.h"

namespace steering_behaviors {

class Follow : public Base {

public:
    explicit Follow(const int priority = 10):
        Base(priority) {}

protected:

    void applyBird(const Vector2D & position, Vector2D & velocity, const float speed, const Bird * bird) {
        if (speed < bird->speed())
            velocity = bird->velocity();
    }

};

}

#endif // FOLLOW_H
