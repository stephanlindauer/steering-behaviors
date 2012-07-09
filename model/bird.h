#ifndef BIRD_H
#define BIRD_H

#include <QVector>

#include "object.h"
#include "vector2d.h"
#include "strategy.h"

namespace steering_behaviors {

class Bird : public Object {

    static const int MAX_SPEED = 15;

    static float randf(void) {
        const int r1 = (rand() % MAX_SPEED) - MAX_SPEED;
        const int r2 = (rand() % MAX_SPEED) - MAX_SPEED;
        return (float) (r1 + 1) / (float) (r2 == 0 ? 1 : r2);
    }

public:

    static Vector2D randVector(void) {
        return Vector2D(randf(), randf());
    }

    explicit Bird (const Vector2D position = randVector(),
                   const Vector2D velocity = randVector()):
        Object(position),
        m_velocity(velocity),
        m_strategies(StrategyVector()){}

    void limit(void) {
        m_velocity.truncate((float) MAX_SPEED);
    }

    const Vector2D & velocity(void) const {
        return m_velocity;
    }

    Vector2D & velocity(void) {
        return m_velocity;
    }

    void add(Strategy * strategy) {
        m_strategies.append(strategy);
    }

    StrategyVector & strategies(void) {
        return m_strategies;
    }

protected:

    Vector2D m_velocity;
    StrategyVector m_strategies;

private:

};

typedef QVector<Bird> BirdVector;

}

#endif // BIRD_H
