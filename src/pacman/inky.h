#ifndef INKY_H
#define INKY_H

#include "ghost.h"

class Inky : public Ghost {
public:
  void move(int (&maze)[HEIGHT][WIDTH]) override;
  void print() override;
};

#endif