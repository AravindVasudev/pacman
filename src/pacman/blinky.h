#ifndef BLINKY_H
#define BLINKY_H

#include "ghost.h"

class Blinky : public Ghost {
public:
  Blinky(int X, int Y) : Ghost{X, Y} {}
  void move(int (&maze)[HEIGHT][WIDTH]) override;
  void print() override;
};

#endif