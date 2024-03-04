#include "ghost.h"
#include "cell.h"

void Ghost::move(int (&maze)[HEIGHT][WIDTH]) {
  Point newPosition{position.X + 1, position.Y};

  // Don't move if wall.
  if (isWall(static_cast<Cell>(maze[newPosition.X][newPosition.Y]))) {
    return;
  }

  position.X = newPosition.X;
  position.Y = newPosition.Y;
}