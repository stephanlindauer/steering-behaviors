#include <QtGui/QApplication>
#include "mainwindow.h"

#include "model/bird.h"
#include "model/brain.h"
#include "model/map.h"
#include "model/object.h"
#include "model/obstacle.h"

#include "view/birddrawer.h"
#include "view/drawer.h"
#include "view/mapdrawer.h"
#include "view/obstacledrawer.h"

int main(int argc, char *argv[])
{

    steering_behaviors::Bird * bird;
    steering_behaviors::Brain * brain;
    steering_behaviors::Map * map;
    steering_behaviors::Object * object;
    steering_behaviors::Obstacle * obstacle;

    steering_behaviors::BirdDrawer * birdDrawer;
    steering_behaviors::Drawer * Drawer;
    steering_behaviors::MapDrawer * mapDrawer;
    steering_behaviors::ObstacleDrawer * obstacleDrawer;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
