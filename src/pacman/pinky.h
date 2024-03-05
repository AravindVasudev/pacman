#ifndef PINKY_H
#define PINKY_H

#include "ghost.h"

class Pinky : public Ghost {
public:
  void move(int (&maze)[HEIGHT][WIDTH]) override;
  void print() override;
};

#endif