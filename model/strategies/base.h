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
    void apply(const Vector2D & position, Vector2D & velocity, const Object * object) {
        if (typeid(*object) == typeid(Bird))
            applyBird(position, velocity, (Bird *) object);

        if (typeid(*object) == typeid(Obstacle))
            applyObstacle(position, velocity, (Obstacle *) object);
    }

protected:

    virtual void applyBird(const Vector2D & position, Vector2D & velocity, const Bird * bird) { }

    virtual void applyObstacle(const Vector2D & position, Vector2D & velocity, const Obstacle * obstacle) { }

};

}

#endif // BASE_H
