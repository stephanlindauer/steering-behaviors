#ifndef OBSTACLEDRAWER_H
#define OBSTACLEDRAWER_H

#include <QtGui>
#include <vector2d.h>

class ObstacleDrawer : public Drawer {
public:
    ObstacleDrawer(const Obstacle & obstacle):
        m_obstacle(obstacle) {}

    void draw(const QGraphicsScene * scene) {
     //TODO
    }

private:
    const Obstacle & m_obstacle;
    QGraphicsEllipseItem * m_ellipse;

    static const Vector2D RECT_START_POINT = 10;
    static const Vector2D RECT_END_POINT = 10;

    qreal x(void) {
        return (qreal) m_bird.m_position.x - (WIDTH / 2);
    }

    qreal y(void) {
        return (qreal) m_bird.m_position.y - (HEIGHT / 2);
    }

};



#endif // OBSTACLEDRAWER_H
