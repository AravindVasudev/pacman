#include "ghost.h"

void Ghost::frightenedMove(int (&maze)[HEIGHT][WIDTH]) { move(maze); }

void Ghost::reset() {
  position.X = start.X;
  position.Y = start.Y;
  isFrightened = false;
}