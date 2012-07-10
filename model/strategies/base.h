#ifndef BASE_H
#define BASE_H

#include <typeinfo>

#include "model/strategy.h"
#include "model/bird.h"
#include "model/object.h"
#include "model/obstacle.h"

namespace steering_behaviors {

class Base : public Strategy {

public:
    explicit Base(const int priority):
        Strategy(priority) {}

    void apply(const Vector2D & position, Vector2D & velocity, const float speed, const Object * object) {
        if (typeid(*object) == typeid(Bird))
            applyBird(position, velocity, speed, (Bird *) object);

        if (typeid(*object) == typeid(Obstacle))
            applyObstacle(position, velocity, speed, (Obstacle *) object);
    }

protected:

    virtual void applyBird(const Vector2D & position, Vector2D & velocity, const float speed, const Bird * bird) { }

    virtual void applyObstacle(const Vector2D & position, Vector2D & velocity, const float speed, const Obstacle * obstacle) { }

};

}

#endif // BASE_H
