#ifndef GHOST_H
#define GHOST_H

#include "color.h"
#include "constants.h"
#include "point.h"

class Ghost {
public:
  Point start;
  Point position;
  Point velocity{1, 0};
  bool isFrightened{};
  bool frightenedTimeoutBlink{};
  bool frightenedBlinkSwitch{};

  Ghost(int X, int Y) : position{X, Y}, start{X, Y} {}
  virtual void move(int (&maze)[HEIGHT][WIDTH]) = 0;
  void frightenedMove(int (&maze)[HEIGHT][WIDTH]);
  void reset();
  virtual void print() = 0;
  void draw(const Color &color);
  virtual ~Ghost(){};
};

#endif