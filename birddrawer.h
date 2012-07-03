#ifndef BIRDDRAWER_H
#define BIRDDRAWER_H

#include <QtGui>

class BirdDrawer : public Drawer {
public:
    BirdDrawer(const Bird & bird):
        m_bird(bird) {}

    void draw(const QGraphicsScene * scene) {
        scene->addEllipse()
    }

private:
    const Bird & m_bird;
    QGraphicsEllipseItem * ellipse;

};

#endif // BIRDDRAWER_H
