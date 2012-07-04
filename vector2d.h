#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>
#include <algorithm>

using namespace std;

class Vector2D {
public:

    Vector2D(): m_x(0.f), m_y(0.f) {}

    Vector2D(float x, float y) :
        m_x(x),
        m_y(y) {}

    Vector2D clone()
    {
        return Vector2D(m_x, m_y);
    }

    Vector2D zero()
    {
        m_x = 0;
        m_y = 0;
        return *this;
    }

    bool isZero()
    {
        return (m_x == 0) && (m_y == 0);
    }

    void setLength(float value)
    {
        float a = getAngle();
        m_x = cos(a) * value;
        m_y = sin(a) * value;
    }

    float getLength()
    {
        return sqrt(getLengthSQ());
    }

    float getLengthSQ()
    {
        return (m_x * m_x) + (m_y * m_y);
    }

    void setAngle(float value)
    {
        float len = getLength();
        m_x = cos(value) * len;
        m_y = sin(value) * len;
    }

    float getAngle()
    {
        return atan2(m_y, m_x);
    }

    Vector2D normalize()
    {
        if(getLength() == 0)
        {
            m_x = 1;
            return *this;
        }
        float len = getLength();
        m_x /= len;
        m_y /= len;
        return *this;
    }

    Vector2D truncate(float max)
    {
        setLength(min(max, getLength()));
        return *this;
    }

    Vector2D reverse()
    {
        m_x = -m_x;
        m_y = -m_y;
        return *this;
    }

    bool isNormalized()
    {
        return getLength() == 1.0;
    }

    float dotProd(Vector2D v2)
    {
        return (m_x * v2.m_x) + (m_y * v2.m_y);
    }

    float crossProd(Vector2D v2)
    {
        return m_x * v2.m_y - m_y * v2.m_x;
    }

    float  angleBetween(Vector2D v1, Vector2D v2)
    {
        if(!v1.isNormalized()) {
            v1 = v1.clone().normalize();
        }
        if(!v2.isNormalized()){
            v2 = v2.clone().normalize();
        }
        return acos(v1.dotProd(v2));
    }

    int sign(Vector2D v2)
    {
        return getPerp().dotProd(v2) < 0 ? -1 : 1;
    }

    Vector2D getPerp()
    {
        Vector2D* returnVector = new Vector2D(-m_y, m_x);
        return *returnVector;
    }

    float dist(Vector2D v2)
    {
        return sqrt(distSQ(v2));
    }

    float distSQ(Vector2D v2)
    {
        float  dx = v2.m_x - m_x;
        float  dy = v2.m_y - m_y;
        return dx * dx + dy * dy;
    }

    Vector2D add(Vector2D v2)
    {
        return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
    }

    Vector2D & operator+(Vector2D & v2) {
        *this = this->add(v2);
        return *this;
    }

    Vector2D subtract(Vector2D v2)
    {
        return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
    }

    Vector2D multiply(float value)
    {
        return Vector2D(m_x * value, m_y * value);
    }

    Vector2D divide(float value)
    {
        return Vector2D(m_x / value, m_y / value);
    }

    bool equals(Vector2D v2)
    {
        return m_x == v2.m_x && m_y == v2.m_y;
    }

    void x(float value)
    {
        m_x = value;
    }

    float x() const
    {
        return m_x;
    }

    void y(float value)
    {
        m_y = value;
    }

    float y() const
    {
        return m_y;
    }

private:

    float m_x;
    float m_y;

};

#endif // VECTOR2D_H
