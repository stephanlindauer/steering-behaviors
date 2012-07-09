#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>
#include <algorithm>

using namespace std;

class Vector2D {
public:

    Vector2D(): m_x(0.f), m_y(0.f) {}

    Vector2D(float x, float y):
        m_x(x),
        m_y(y) {}

    void zero() {
        m_x = 0.f;
        m_y = 0.f;
    }

    bool isZero() const
    {
        return (m_x == 0.f) && (m_y == 0.f);
    }

    void setLength(float value)
    {
        float a = getAngle();
        m_x = cos(a) * value;
        m_y = sin(a) * value;
    }

    float getLength() const
    {
        return sqrt(getLengthSQ());
    }

    float getLengthSQ() const
    {
        return (m_x * m_x) + (m_y * m_y);
    }

    void setAngle(float value)
    {
        float len = getLength();
        m_x = cos(value) * len;
        m_y = sin(value) * len;
    }

    float getAngle() const
    {
        return atan2(m_y, m_x);
    }

    void normalize()
    {
        if(getLength() == 0)
        {
            m_x = 1;
        }
        float len = getLength();
        m_x /= len;
        m_y /= len;
    }

    void truncate(float max)
    {
        setLength(min(max, getLength()));
    }

    void reverse()
    {
        m_x = -m_x;
        m_y = -m_y;
    }

    bool isNormalized() const
    {
        return getLength() == 1.0;
    }

    float dotProd(const Vector2D v2) const
    {
        return (m_x * v2.m_x) + (m_y * v2.m_y);
    }

    float crossProd(const Vector2D v2) const
    {
        return m_x * v2.m_y - m_y * v2.m_x;
    }

    static float angleBetween(const Vector2D v1, const Vector2D v2)
    {
        Vector2D x1 = v1;
        if(!x1.isNormalized())
            x1.normalize();

        Vector2D x2 = v2;
        if(!x2.isNormalized())
            x2.normalize();

        return acos(x1.dotProd(x2));
    }

    int sign(const Vector2D v2) const
    {
        return getPerp().dotProd(v2) < 0 ? -1 : 1;
    }

    const Vector2D getPerp(void) const
    {
        Vector2D returnVector = Vector2D(-m_y, m_x);
        return returnVector;
    }

    float dist(const Vector2D v2) const
    {
        return sqrt(distSQ(v2));
    }

    float distSQ(const Vector2D v2) const
    {
        float  dx = v2.m_x - m_x;
        float  dy = v2.m_y - m_y;
        return dx * dx + dy * dy;
    }

    const Vector2D add(const Vector2D v2) const
    {
        return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
    }

    const Vector2D subtract(const Vector2D v2) const
    {
        return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
    }

    const Vector2D multiply(float value) const
    {
        return Vector2D(m_x * value, m_y * value);
    }

    const Vector2D divide(float value) const
    {
        return Vector2D(m_x / value, m_y / value);
    }

    bool equals(const Vector2D v2) const
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
