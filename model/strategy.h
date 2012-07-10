#ifndef STRATEGY_H
#define STRATEGY_H

#include <QMap>
#include "object.h"
#include "vector2d.h"

namespace steering_behaviors {

class Strategy {
public:

    explicit Strategy(const int priority):
        m_priority(priority) {}

    virtual void apply(const Vector2D & position, Vector2D & velocity, const float speed, const Object * object) = 0;

    int priority(void) const {
        return m_priority;
    }

private:

    const int m_priority;

};

typedef QMap<int, Strategy *> StrategyMap;

}

#endif // STRATEGY_H
