#ifndef HERO_H
#define HERO_H

#include "cell.h"
#include "constants.h"
#include "point.h"

class Hero {
private:
  bool heroMouthOpen{};

public:
  // Throwing everything into public since the view layer might need access to
  // these. I guess the ideal ideal way of exposing these would be to have
  // getters but I'm choosing the `lazy` design pattern.
  Point position{HERO_X, HERO_Y};
  Point velocity{0, -1};

  int move(int (&maze)[HEIGHT][WIDTH]); // Returns score.
  void input(int (&maze)[HEIGHT][WIDTH], const char &input);
  void print();
};

#endif