#ifndef BIRD_H
#define BIRD_H

#include <QtGui>

class Bird
{

public:

    Bird(int x , int y , int velocityX, int velocityY) :
        _positionX (x),
        _positionY (y),
        _velocityX (velocityX),
        _velocityY (velocityY) {}

    void draw( QGraphicsScene * scene ){
        QBrush redBrush(Qt::red);
        QPen blackPen(Qt::black);
        blackPen.setWidth(1);
       QGraphicsEllipseItem ellipse = scene->addEllipse( _positionX ,_positionY,10,10, blackPen, redBrush);
       ellipse.setX();
    }

    void bounce(){
        if(_positionX > _stageWidth)
        {
            _positionX = _stageWidth;
            _velocityX *= -1;
        }
        else if(_positionX < 0)
        {
            _positionX = 0;
            _velocityX *= -1;
        }

        if(_positionY > _stageHeight)
        {
            _positionY = _stageHeight;
            _velocityY *= -1;
        }
        else if(_positionY < 0)
        {
            _positionY = 0;
            _velocityY *= -1;
        }
    }


private:

    int _stageWidth;
    int _stageHeight;
    int _positionX;
    int _positionY;
    float _velocityX;
    float _velocityY;
    static const int _mass = 1;
    static const int _maxSpeed = 10;

};



#endif // BIRD_H
