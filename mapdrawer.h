#ifndef MAPDRAWER_H
#define MAPDRAWER_H

#include <QtGui>
#include <birdrawer.h>

class MapDrawer
{
public:
    QVector<BirdDrawer> birds ;
    QVector<QColor> m_color;
};


#endif // MAPDRAWER_H
