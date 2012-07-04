#ifndef DRAWER_H
#define DRAWER_H

#include <QGraphicsScene>
#include "model/vector2d.h"

namespace steering_behaviors {

class Drawer {
public:
    Drawer():m_drawn(false) {}

    virtual void draw (QGraphicsScene * scene);

    static const qreal x(const Vector2D vector) {
        return (qreal) vector.x();
    }

    static const qreal y(const Vector2D vector) {
        return (qreal) vector.y();
    }

protected:

    const bool drawn(void) const {
        return m_drawn;
    }

    void drawn(void) {
        m_drawn = true;
    }

    void reset(void)  {
        m_drawn = false;
    }

private:

    bool m_drawn;

};

}

#endif // DRAWER_H
