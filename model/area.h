#ifndef AREA_H
#define AREA_H

#include "object.h"
#include "vector2d.h"

namespace steering_behaviors {

class Area : public Object {

public:

    explicit Area(const Vector2D position,
                  const Vector2D dimension):
        Object(position),
        m_dimension(dimension) {}

    const Vector2D & dimension(void) const {
        return m_dimension;
    }

    Vector2D & dimension(void) {
        return m_dimension;
    }

protected:

    Vector2D m_dimension;

private:

};

}

#endif // AREA_H
