#ifndef FOLLOW_H
#define FOLLOW_H

#include <typeinfo>

#include "base.h"

namespace steering_behaviors {

class Follow : public Base {

protected:

    void applyBird(const Vector2D & position, Vector2D & velocity, const Bird * bird) {

    }

    /*void applyObstacle(const Vector2D & position, Vector2D & velocity, const Obstacle * obstacle) {
        // do not follow obstacles
    }*/

};

}

#endif // FOLLOW_H
