#include "hero.h"
#include "cell.h"

void Hero::move(int (&maze)[HEIGHT][WIDTH], const char& input) {
  if (maze[X][Y - 1] > Cell::empty && maze[X][Y - 1] < Cell::pellet) {
    return;
  }  

  Y--;
}