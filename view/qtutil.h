#ifndef QTUTIL_H
#define QTUTIL_H

#include <QColor>

namespace steering_behaviors {

inline QColor randomColor(void) {
    return QColor(qrand()%256, qrand()%256, qrand()%256);
}

}

#endif // QTUTIL_H
