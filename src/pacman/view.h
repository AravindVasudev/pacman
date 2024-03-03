#ifndef VIEW_H
#define VIEW_H

#include "cell.h"
#include "constants.h"
#include "hero.h"

class View {
private:
  void printWall(const Cell &cell);

public:
  View();
  void printMaze(int (&maze)[HEIGHT][WIDTH]);
  void printHero(const Hero &hero);
};

#endif
