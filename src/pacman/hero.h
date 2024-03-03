#ifndef HERO_H
#define HERO_H

#include "constants.h"

class Hero {
  public:
    int X {HERO_X};
    int Y {HERO_Y};

    void move(int (&maze)[HEIGHT][WIDTH], const char& input);
};

#endif