#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>
#include <algorithm>

using namespace std;

class Vector2D
{

private :

    float _x;
    float _y;

public:

    Vector2D(float x, float y) :
        _x(x),
        _y(y) {}

    Vector2D clone()
    {
        return Vector2D(_x, _y);
    }

    Vector2D zero()
    {
        _x = 0;
        _y = 0;
        return *this;
    }

    bool isZero()
    {
        return (_x == 0) && (_y == 0);
    }

    void setLength(float value)
    {
        float a = getAngle();
        _x = cos(a) * value;
        _y = sin(a) * value;
    }

    float getLength()
    {
        return sqrt(getLengthSQ());
    }

    float getLengthSQ()
    {
        return (_x * _x) + (_y * _y);
    }

    void setAngle(float value)
    {
        float len = getLength();
        _x = cos(value) * len;
        _y = sin(value) * len;
    }

    float getAngle()
    {
        return atan2(_y, _x);
    }

    Vector2D normalize()
    {
        if(getLength() == 0)
        {
            _x = 1;
            return *this;
        }
        float len = getLength();
        _x /= len;
        _y /= len;
        return *this;
    }

    Vector2D truncate(float max)
    {
        setLength(min(max, getLength()));
        return *this;
    }

    Vector2D reverse()
    {
        _x = -_x;
        _y = -_y;
        return *this;
    }

    bool isNormalized()
    {
        return getLength() == 1.0;
    }

    float dotProd(Vector2D v2)
    {
        return (_x * v2._x) + (_y * v2._y);
    }

    float crossProd(Vector2D v2)
    {
        return _x * v2._y - _y * v2._x;
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
        Vector2D* returnVector = new Vector2D(-_y, _x);
        return *returnVector;
    }

    float dist(Vector2D v2)
    {
        return sqrt(distSQ(v2));
    }

    float distSQ(Vector2D v2)
    {
        float  dx = v2._x - _x;
        float  dy = v2._y - _y;
        return dx * dx + dy * dy;
    }

    Vector2D add(Vector2D v2)
    {
        return Vector2D(_x + v2._x, _y + v2._y);
    }

    Vector2D & operator+(Vector2D & v2) {
        *this = this->add(v2);
        return *this;
    }

    Vector2D subtract(Vector2D v2)
    {
        return Vector2D(_x - v2._x, _y - v2._y);
    }

    Vector2D multiply(float value)
    {
        return Vector2D(_x * value, _y * value);
    }

    Vector2D divide(float value)
    {
        return Vector2D(_x / value, _y / value);
    }

    bool equals(Vector2D v2)
    {
        return _x == v2._x && _y == v2._y;
    }

    void x(float value)
    {
        _x = value;
    }

    float x() const
    {
        return _x;
    }

    void y(float value)
    {
        _y = value;
    }

    float y() const
    {
        return _y;
    }

};

#endif // VECTOR2D_H
