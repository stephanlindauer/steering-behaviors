#ifndef MAP_H
#define MAP_H

#include <QVector>
#include "object.h"
#include "bird.h"
#include "obstacle.h"
#include "nullobject.h"
#include "vector2d.h"

class Map {
public:
    Map(unsigned int width = 10, unsigned int height = 10) :
        m_width(width),
        m_height(height) {
        m_objects.reserve(m_width * m_height);
        m_objects.insert(0, m_width * m_height, NULL_OBJECT);
    }

    void addObject(Object * o) {
        m_objects.replace((o->m_position), o);
    }

    void delObject(Object * o) {
        m_objects.replace(pos(o->m_position), NULL_OBJECT);
    }

private:
    unsigned int m_width;
    unsigned int m_height;
    QVector<Object *> m_objects;

    unsigned int x(const Vector2D vector) {
        return (int) vector.x();
    }

    unsigned int y(const Vector2D vector) {
        return (int) vector.y();
    }

    unsigned int pos(const Vector2D vector) {
        return y(vector) * m_width + y(vector);
    }

};

#endif // MAP_H
