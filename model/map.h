#ifndef MAP_H
#define MAP_H

#include "sector.h"

/**
  *
  * elements of a map:
  * - obstacles (can be added or removed, but stay at position)
  * - birds (change position all the time)
  *
  */

class Map {
public:
    /**
      * takes the birds' coordinates to calculate the sectors
      * lets the bird process each sector
      */
    void process (const Bird * bird);
private:

};

#endif // MAP_H
