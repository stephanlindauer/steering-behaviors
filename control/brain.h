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

public:

    static void process (bool sightbox, QGraphicsScene * scene, Map & map, MapDrawer & mapDrawer) {
        clearBoxes(scene);

        for (int i = 0; i < map.birds().size(); i++) {
            Bird & bird = map.birds()[i];
            Vector2D & position = bird.position();
            Vector2D & velocity = bird.velocity();

            const BirdDrawer * birdDrawer = mapDrawer.birdDrawer(&bird);
            if (birdDrawer == NULL)
                continue;

            QGraphicsItem * item = (QGraphicsItem *) birdDrawer->item();
            if (item == NULL)
                continue;

            // visible range
            QRectF rectangle = item->boundingRect();
            expand(rectangle);
            rectangle.moveCenter(QPointF(item->x() + BirdDrawer::WIDTH / 2, item->y() + BirdDrawer::HEIGHT / 2));
            if (sightbox)
                rectangles.append(scene->addRect(rectangle));

            // items in visible range of the current bird
            QList<QGraphicsItem *> items = scene->items(rectangle, Qt::ContainsItemBoundingRect, Qt::AscendingOrder);
            for (int j = 0; j < items.size(); j++) {
                QGraphicsItem * viewedItem = items[j];
                if (item == viewedItem) // looking at us
                    continue;

                for (int k = 0; k < bird.strategies().size(); k++) {
                    Strategy * strategy = bird.strategies()[k];
                    strategy->apply(position, velocity, mapDrawer.fromItem(viewedItem));
                }
            }

            bird.limit();

            Vector2D v = velocity.divide(1000.f/60.f);

            position = position.add(v);
        }
    }

protected:

private:

    static void expand(QRectF & rectangle) {
        rectangle.adjust(-20, -20, 20, 20);
    }

    static void clearBoxes(QGraphicsScene * scene) {
        for (int i = 0; i < rectangles.size(); i++)
            scene->removeItem(rectangles[i]);

        rectangles.clear();
    }

    static QList<QGraphicsRectItem *> rectangles;

};

QList<QGraphicsRectItem *> Brain::rectangles;

}

#endif // BRAIN_H
