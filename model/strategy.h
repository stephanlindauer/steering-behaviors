#ifndef STRATEGY_H
#define STRATEGY_H

#include <QVector>
#include "object.h"
#include "vector2d.h"

namespace steering_behaviors {

class Strategy {
public:
    virtual void apply(const Vector2D & position, Vector2D & velocity, const Object * object) = 0;
};

typedef QVector<Strategy *> StrategyVector;

}

#endif // STRATEGY_H
