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
        return Vector2D(x, y);
    }

    void zero()
    {
        _x = 0;
        _y = 0;
        return this;
    }

    bool isZero()
    {
        return (_x == 0) && (_y == 0);
    }

    void setLength(float value)
    {
        float a = angle;
        _x = cos(a) * value;
        _y = sin(a) * value;
    }

    float getLength()
    {
        return sqrt(lengthSQ);
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
        if(length == 0)
        {
            _x = 1;
            return this;
        }
        float len = getLength();
        _x /= len;
        _y /= len;
        return this;
    }

    Vector2D truncate(float max)
    {
        length = min(max, length);
        return this;
    }

    Vector2D reverse()
    {
        _x = -_x;
        _y = -_y;
        return this;
    }

    bool isNormalized()
    {
        return length == 1.0;
    }

    float dotProd(Vector2D v2)
    {
        return _x * v2.x + _y * v2.y;
    }

    void crossProd(Vector2D v2)
    {
        return _x * v2.y - _y * v2.x;
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
        return perp.dotProd(v2) < 0 ? -1 : 1;
    }

    Vector2D getPerp()
    {
        return new Vector2D(-y, x);
    }

    float dist(Vector2D v2)
    {
        return sqrt(distSQ(v2));
    }

    float distSQ(Vector2D v2)
    {
        float  dx = v2.x - x;
        float  dy = v2.y - y;
        return dx * dx + dy * dy;
    }

    Vector2D add(Vector2D v2)
    {
        return new Vector2D(_x + v2.x, _y + v2.y);
    }

    Vector2D subtract(Vector2D v2)
    {
        return new Vector2D(_x - v2.x, _y - v2.y);
    }

    Vector2D multiply(float value)
    {
        return new Vector2D(_x * value, _y * value);
    }

    Vector2D divide(float value)
    {
        return new Vector2D(_x / value, _y / value);
    }

    bool equals(Vector2D v2)
    {
        return _x == v2.x && _y == v2.y;
    }

    void x(float value)
    {
        _x = value;
    }

    float x()
    {
        return _x;
    }

    void y(float value)
    {
        _y = value;
    }
    float y()
    {
        return _y;
    }

}

#endif // VECTOR2D_H
