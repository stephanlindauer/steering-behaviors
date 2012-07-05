#ifndef DRAWER_H
#define DRAWER_H

#include <QGraphicsScene>
#include "model/vector2d.h"

namespace steering_behaviors {

class Drawer {
public:
    static qreal x(const Vector2D vector) {
        return (qreal) vector.x();
    }

    static qreal y(const Vector2D vector) {
        return (qreal) vector.y();
    }

    Drawer():m_drawn(false) {}

    virtual void draw (QGraphicsScene * scene) = 0;

    bool hasBeenDrawn(void) const {
        return m_drawn;
    }

    void drawn(void) {
        m_drawn = true;
    }

    void reset(void)  {
        m_drawn = false;
    }


protected:

private:

    bool m_drawn;

};

}

#endif // DRAWER_H
