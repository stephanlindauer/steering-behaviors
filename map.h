#ifndef MAP_H
#define MAP_H

#include <QVector>
#include "object.h"
#include "bird.h"
#include "obstacle.h"
#include "vector2d.h"

class Map {
public:
    Map(unsigned int width = 10, unsigned int height = 10) {
        m_objects.reserve(width * height);
    }

private:

    QVector<Object> m_objects;

};

#endif // MAP_H
