#ifndef BIRD_H
#define BIRD_H

#include <QVector>

#include "obstacle.h"
#include "sector.h"

class Bird : public Object {
public:
    typedef QVector<Bird> BirdVector;

    // jeder Vogel soll für sich selbst entscheiden können, wohin er fliegt
    // dazu benötigt er einen Sektor, dessen mittelpunkt er selbst ist
    // in diesem Sektor sind andere Vögel und Hindernisse
    void process ();
};

#endif // BIRD_H
