#ifndef GHOST_H
#define GHOST_H

#include "constants.h"
#include "point.h"

class Ghost {
public:
  Point position{GHOST_X, GHOST_Y};

  void move(int (&maze)[HEIGHT][WIDTH]);
};

#endif