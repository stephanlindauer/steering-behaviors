#ifndef BRAIN_H
#define BRAIN_H

#include "bird.h"
#include "obstacle.h"
#include "map.h"

namespace steering_behaviors {

class Brain {

public:

    static void process (Map & map) {
        process(map.birds(), map.obstacles());
    }

    // take birds strategies and calculate the new direction based on the other birds directions and the obstacles
    static void process (BirdVector & birds, const ObstacleVector & obstacles) {
        for (int i = 0; i < birds.size(); i++) {
            Bird & bird = birds[i];
            Vector2D & position = bird.position();
            Vector2D & velocity = bird.velocity();
            position = position + velocity;
        }
    }

protected:

private:

};

}

#endif // BRAIN_H
