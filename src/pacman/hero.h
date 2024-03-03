#ifndef HERO_H
#define HERO_H

#include "constants.h"
#include "point.h"

class Hero {
public:
  // Throwing everything into public since the view layer might need access to
  // these. I guess the ideal ideal way of exposing these would be to have
  // getters but I'm choosing the `lazy` design pattern.
  Point position{HERO_X, HERO_Y};
  Point velocity{0, -1};

  void move(int (&maze)[HEIGHT][WIDTH]);
  void input(const char &input);
};

#endif