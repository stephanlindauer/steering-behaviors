#ifndef QTUTIL_H
#define QTUTIL_H

#include <QColor>

#include "model/random.h"

namespace steering_behaviors {

inline QColor randomColor(void) {
    return QColor(Random::random(256), Random::random(256), Random::random(256));
}

}

#endif // QTUTIL_H
