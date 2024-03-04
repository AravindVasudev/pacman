#include "ghost.h"
#include "cell.h"

#include <cstdlib>

void Ghost::move(int (&maze)[HEIGHT][WIDTH]) {

  // Yeah yeah, I know how complex the original AI is.
  Point move{};
  switch ((std::rand() % 4) + 1) {
  case 1:
    move.X = 1;
    move.Y = 0;
    break;
  case 2:
    move.X = -1;
    move.Y = 0;
    break;
  case 3:
    move.X = 0;
    move.Y = 1;
    break;
  case 4:
    move.X = 0;
    move.Y = -1;
  }

  Point newPosition{position.X + move.X, position.Y + move.Y};

  // Don't move if wall.
  if (isWall(static_cast<Cell>(maze[newPosition.X][newPosition.Y]))) {
    return;
  }

  position.X = newPosition.X;
  position.Y = newPosition.Y;
}