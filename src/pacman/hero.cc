#include "hero.h"
#include "cell.h"

void Hero::move(int (&maze)[HEIGHT][WIDTH], const char &input) {
  if (maze[position.X][position.Y - 1] > Cell::empty &&
      maze[position.X][position.Y - 1] < Cell::pellet) {
    return;
  }

  position.Y--;
}