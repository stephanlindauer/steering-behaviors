#ifndef MAPDRAWER_H
#define MAPDRAWER_H

#include <QtGui>
#include <birddrawer.h>

class MapDrawer : public Drawer
{
public:

    MapDrawer(QVector birds){
        this->birds = birds;
    }

    void draw (const QGraphicsScene *scene){
        foreach (BirdDrawer birdDrawer, birds){
            birdDrawer.draw(scene);
        }
    }

private:
        QVector<BirdDrawer> birds ;
};


#endif // MAPDRAWER_H
