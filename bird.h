#ifndef BIRD_H
#define BIRD_H

#include <QtGui>
#include "vector2d.h"

class Bird
{

public:

    static int STAGE_WIDTH = 100;
    static int STAGE_HEIGHT = 100;
    static int _mass = 1;
    static int _maxSpeed = 10;

    Bird(const Vector2d position, const Vector2d velocity) :
        m_position (position),
        m_velocity (velocity) {}

    void draw( QGraphicsScene * scene ){
        QBrush redBrush(Qt::red);
        QPen blackPen(Qt::black);
        blackPen.setWidth(1);
        QGraphicsEllipseItem * ellipse = scene->addEllipse(m_position.x, m_position.y, 10, 10, blackPen, redBrush);
        ellipse->setX(4.0);
    }

    void bounce(){
        if(m_position.x() > STAGE_WIDTH) {
            m_position.x(STAGE_WIDTH);
            m_velocity.x(m_velocity.x()*-1);

        } else if(m_position.x() < 0) {
            m_position.x(0);
            m_velocity.x(m_velocity.x()*-1);
        }

        if(m_position.y() > STAGE_HEIGHT) {
            m_position.y(STAGE_HEIGHT);
            m_velocity.y(m_velocity.y()*-1);

        } else if(m_position.y() < 0) {
            m_position.y(0);
            m_velocity.y(m_velocity.y()*-1);
        }
    }

    void update() {
        m_position += m_velocity;
        bounce();
    }

    Vector2d velocity (void) {
        return m_velocity;
    }

    void velocity(Vector2d velocity) {
        m_velocity = velocity;
    }

private:

    Vector2d m_position;
    Vector2d m_velocity;

};

#endif // BIRD_H
