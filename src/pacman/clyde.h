#ifndef CLYDE_H
#define CLYDE_H

#include "ghost.h"

class Clyde : public Ghost {
public:
  Clyde(int X, int Y) : Ghost{X, Y} {}
  void move(int (&maze)[HEIGHT][WIDTH]) override;
  void print() override;
};

#endif