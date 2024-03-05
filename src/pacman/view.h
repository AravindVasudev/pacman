#ifndef VIEW_H
#define VIEW_H

#include "blinky.h"
#include "cell.h"
#include "constants.h"
#include "ghost.h"
#include "hero.h"

class View {
private:
  void printWall(const Cell &cell);
  bool heroMouthOpen{};

public:
  View();
  void printMaze(int (&maze)[HEIGHT][WIDTH], const int &score);
  void printHero(const Hero &hero);
  void printGhost(const Blinky &ghost);
};

#endif
