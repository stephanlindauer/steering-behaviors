#ifndef FLEE_H
#define FLEE_H

#include <typeinfo>

#include "model/strategy.h"
#include "model/bird.h"
#include "model/object.h"
#include "model/obstacle.h"

namespace steering_behaviors {

class Flee : public Strategy {
public:
    void apply(const Vector2D & position, Vector2D & velocity, const Object * object) {
        //printf("apply() - typeid(*object).name(): '%s'; typeid(Bird).name(): '%s'\n", typeid(*object).name(), typeid(Bird).name());

        if (typeid(*object) == typeid(Bird))
            applyBird(position, velocity, (Bird *) object);

        if (typeid(*object) == typeid(Obstacle))
            applyObstacle(position, velocity, (Obstacle *) object);
    }
private:

    void applyBird(const Vector2D & position, Vector2D & velocity, const Bird * bird) {
        // do not flee from other birds
    }

    void applyObstacle(const Vector2D & position, Vector2D & velocity, const Obstacle * obstacle) {
        Vector2D difference = obstacle->position().subtract(position);
        difference.normalize();
        velocity = velocity.add(difference.setLength(velocity.getLength()));
    }

};

}

#endif // FLEE_H
