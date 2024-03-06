#ifndef GHOST_H
#define GHOST_H

#include "constants.h"
#include "point.h"

class Ghost {
public:
  Point position;
  Point velocity{1, 0};
  bool isFrightened{};

  Ghost(int X, int Y) : position{X, Y} {}
  virtual void move(int (&maze)[HEIGHT][WIDTH]) = 0;
  void frightenedMove(int (&maze)[HEIGHT][WIDTH]);
  virtual void print() = 0;
};

#endif