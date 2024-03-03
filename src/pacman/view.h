#ifndef VIEW_H
#define VIEW_H

#include "constants.h"
#include "cell.h"
#include "hero.h"

class View {
  private:
    void printWall(const Cell& cell);
  public:
    View();
    void printMaze(int (&maze)[HEIGHT][WIDTH]);
    void printHero(const Hero& hero);
};

#endif
