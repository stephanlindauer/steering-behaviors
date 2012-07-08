#ifndef BRAIN_H
#define BRAIN_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>

#include "model/map.h"
#include "view/mapdrawer.h"

#include "model/vector2d.h"

namespace steering_behaviors {

class Brain {

    static Vector2D rotate(const Vector2D vec) {
        const int MIN = 15;
        const int MAX = 180 - MIN;

        int angle = rand() % MAX;

        while (angle < MIN)
            angle = rand() % MAX;

        Vector2D result = vec;
        result.setAngle(result.getAngle() + (float) angle / 360.f);
        return result;
    }

    static bool boundary(QGraphicsScene * scene, QGraphicsItem * item) {
        if (scene == NULL)
            return false;

        if (item == NULL)
            return false;

        if (item->x() < 0)
            return false;

        if (item->x() > scene->width())
            return false;

        if (item->y() < 0)
            return false;

        if (item->y() > scene->height())
            return false;

        return true;
    }

public:

    static void process (QGraphicsScene * scene, Map & map, MapDrawer & mapDrawer) {
        for (int i = 0; i < map.birds().size(); i++) {
            Bird & bird = map.birds()[i];
            Vector2D & position = bird.position();
            Vector2D & velocity = bird.velocity();

            BirdDrawer * birdDrawer = mapDrawer.birdDrawer(&bird);
            if (birdDrawer == NULL)
                continue;

            QGraphicsItem * item = (QGraphicsItem *) birdDrawer->item();
            if (item == NULL)
                continue;

            QList<QGraphicsItem *> collidingItems = scene->collidingItems(item);

            if (collidingItems.size() > 0 || !boundary(scene, item)) {
                velocity = rotate(velocity);
            }

            Vector2D vel = velocity.divide(1000.f/60.f);

            position = position + vel;
        }
    }

protected:

private:

};

}

#endif // BRAIN_H
