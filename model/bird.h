#ifndef BIRD_H
#define BIRD_H

#include <QVector>

#include "object.h"
#include "vector2d.h"
#include "strategy.h"
#include "random.h"

namespace steering_behaviors {

class Bird : public Object {

    static const int MAX_SPEED = 25;

    static float randf(void) {
        const int r1 = Random::random(MAX_SPEED) - MAX_SPEED;
        return (float) r1;
    }

public:

    static Vector2D randVector(void) {
        return Vector2D(randf(), randf());
    }

    explicit Bird (const Vector2D position = randVector(),
                   const Vector2D velocity = randVector()):
        Object(position),
        m_velocity(velocity),
        m_strategies(StrategyMap()),
        m_speed(m_velocity.getLength()){
        m_strategies.setInsertInOrder(true);
        m_velocity.normalize();
    }

    const Vector2D & velocity(void) const {
        return m_velocity;
    }

    Vector2D & velocity(void) {
        return m_velocity;
    }

    void add(Strategy * strategy) {
        m_strategies.insert(strategy->priority(), strategy);
    }

    StrategyMap & strategies(void) {
        return m_strategies;
    }

    float speed(void) const {
        return m_speed;
    }

protected:

    Vector2D m_velocity;
    StrategyMap m_strategies;
    float m_speed;

private:

};

typedef QVector<Bird> BirdVector;

}

#endif // BIRD_H
