#ifndef VECTOR2D_H
#define VECTOR2D_H



class Vector2D
{
private :
    float _x;
    float _y;

    Vector2D(float x, float y) :
        _x(x),
        _y(y) {}

    Vector2D    clone()
    {
        return Vector2D(x, y);
    }


    void    zero()
    {
        _x = 0;
        _y = 0;
        return this;
    }


    bool isZero()
    {
        return (_x == 0) && (_y == 0);
    }

    setLength(float value)
    {
        float a = angle;
        _x = Math.cos(a) * value;
        _y = Math.sin(a) * value;
    }

    float     getLength()
    {
        return Math.sqrt(lengthSQ);
    }

    float    getLengthSQ()
    {
        return (_x * _x) + (_y * _y);
    }

    void    setAngle(float value)
    {
        float len = getLength();
        _x = Math.cos(value) * len;
        _y = Math.sin(value) * len;
    }

    float  getAngle()
    {
        return Math.atan2(_y, _x);
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

    Vector2D  truncate(float max)
    {
        length = Math.min(max, length);
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

    crossProd(Vector2D v2)
    {
        return _x * v2.y - _y * v2.x;
    }

    float  angleBetween(Vector2D v1, Vector2D v2)
    {
        if(!v1.isNormalized()) v1 = v1.clone().normalize();
        if(!v2.isNormalized()) v2 = v2.clone().normalize();
        return Math.acos(v1.dotProd(v2));
    }

    int sign(Vector2D v2)
    {
        return perp.dotProd(v2) < 0 ? -1 : 1;
    }

    Vector2D    getPerp()
    {
        return new Vector2D(-y, x);
    }


    float dist(Vector2D v2)
    {
        return Math.sqrt(distSQ(v2));
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

    Vector2D    subtract(Vector2D v2)
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

    bool   equals(Vector2D v2)
    {
        return _x == v2.x && _y == v2.y;
    }

    void setX(float value):void
    {
        _x = value;
    }

    float  getX()    {
        return _x;
    }

    void  setY(float value)
    {
        _y = value;
    }
    float getY()
    {
        return _y;
    }

}









#endif // VECTOR2D_H
