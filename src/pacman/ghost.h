#ifndef GHOST_H
#define GHOST_H

#include "constants.h"
#include "point.h"

class Ghost {
public:
  Point position{GHOST_X, GHOST_Y};
  Point velocity{1, 0};

  void move(int (&maze)[HEIGHT][WIDTH]);
};

#endif