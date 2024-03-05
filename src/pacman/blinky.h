#ifndef BLINKY_H
#define BLINKY_H

#include "ghost.h"

class Blinky : public Ghost {
public:
  void move(int (&maze)[HEIGHT][WIDTH]) override;
};

#endif