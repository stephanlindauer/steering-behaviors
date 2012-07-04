#ifndef BIRDDRAWER_H
#define BIRDDRAWER_H

#include <QtGui>

class BirdDrawer : public Drawer {
public:
    BirdDrawer(const Bird & bird):
        m_bird(bird) {}

    void draw(const QGraphicsScene * scene) {
        if (m_ellipse != NULL) {
            m_ellipse->setPos(x(), y());
            return;
        }

        const QColor penColor(QColor(rand()%255, rand()%255, rand()%255));
        const QColor brushColor(QColor(rand()%255, rand()%255, rand()%255));

        m_ellipse = scene->addEllipse(x(), y(), WIDTH, HEIGHT, QPen(penColor), QBrush(brushColor));

    }

private:
    const Bird & m_bird;
    QGraphicsEllipseItem * m_ellipse;

    static const qreal WIDTH = 10;
    static const qreal HEIGHT = 10;

    qreal x(void) {
        return (qreal) m_bird.m_position.x - (WIDTH / 2);
    }

    qreal y(void) {
        return (qreal) m_bird.m_position.y - (HEIGHT / 2);
    }

};

#endif // BIRDDRAWER_H
