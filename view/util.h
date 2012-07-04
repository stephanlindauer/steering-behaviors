#ifndef UTIL_H
#define UTIL_H

#include <QColor>

namespace steering_behaviors {

QColor random(void) {
    return QColor(qrand()%256, qrand()%256, qrand()%256);
}

}

#endif // UTIL_H
