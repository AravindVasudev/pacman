#ifndef INKY_H
#define INKY_H

#include "ghost.h"

class Inky : public Ghost {
public:
  Inky(int X, int Y) : Ghost{X, Y} {}
  void move(int (&maze)[HEIGHT][WIDTH]) override;
  void print() override;
};

#endif