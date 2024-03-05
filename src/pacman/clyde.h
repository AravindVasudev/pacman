#ifndef CLYDE_H
#define CLYDE_H

#include "ghost.h"

class Clyde : public Ghost {
public:
  void move(int (&maze)[HEIGHT][WIDTH]) override;
  void print() override;
};

#endif