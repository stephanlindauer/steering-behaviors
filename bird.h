#ifndef BIRD_H
#define BIRD_H

#include <QtGui>
#include "vector2d.h"

class Bird
{

public:

    static int STAGE_WIDTH;
    static int STAGE_HEIGHT;
    static unsigned int MASS;
    static unsigned int MAXSPEED;

    static Vector2D randomPosition(void) {
        const unsigned int x = rand() % Bird::STAGE_WIDTH;
        const unsigned int y = rand() % Bird::STAGE_HEIGHT;

        const Vector2D position((float) x, (float) y);
        return position;
    }

    static Vector2D randomVelocity(void) {
        const unsigned int x = (rand() % Bird::MAXSPEED) - Bird::MAXSPEED / 2;
        const unsigned int y = (rand() % Bird::MAXSPEED) - Bird::MAXSPEED / 2;

        const Vector2D velocity((float) x, (float) y);
        return velocity;
    }

    Bird():
        m_position(randomPosition()),
        m_velocity(randomVelocity()) {}

    Bird(const Vector2D position, const Vector2D velocity) :
        m_position (position),
        m_velocity (velocity) {}

    void draw( QGraphicsScene * scene ){
        QBrush redBrush(QColor(rand()%255, rand()%255, rand()%255));
        QPen blackPen(Qt::black);
        blackPen.setWidth(1);
        QGraphicsEllipseItem * ellipse = scene->addEllipse((int) m_position.x(), (int) m_position.y(), 10, 10, blackPen, redBrush);
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
        m_position = m_position + m_velocity;
        bounce();
    }

    Vector2D velocity (void) {
        return m_velocity;
    }

    void velocity(Vector2D velocity) {
        m_velocity = velocity;
    }

private:

    Vector2D m_position;
    Vector2D m_velocity;

};

#endif // BIRD_H
