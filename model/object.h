#ifndef OBJECT_H
#define OBJECT_H

#include "vector2d.h"

namespace steering_behaviors {

class Object {

public:

    explicit Object(const Vector2D position):
        m_position(position) {}

    virtual const Vector2D & position(void) const {
        return m_position;
    }

    virtual Vector2D & position(void) {
        return m_position;
    }

protected:

    Vector2D m_position;

private:

};

}

#endif // OBJECT_H
