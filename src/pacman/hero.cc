#include "hero.h"
#include "cell.h"

int Hero::move(int (&maze)[HEIGHT][WIDTH]) {
  Point newPosition{position.X + velocity.X, position.Y + velocity.Y};

  // Don't move if wall.
  if (isWall(static_cast<Cell>(maze[newPosition.X][newPosition.Y]))) {
    return 0;
  }

  position.X = newPosition.X;
  position.Y = newPosition.Y;

  // If the new position has a pellet, eat it.
  if (maze[position.X][position.Y] == pellet) {
    maze[position.X][position.Y] = Cell::empty;
    return 1;
  }

  return 0;
}

void Hero::input(int (&maze)[HEIGHT][WIDTH], const char &input) {
  // So, there's the thing. A couldn't recognize arrow keys. Could be a mac
  // issue? Using wasd to unblock myself. TODO(future me): Support arrow keys.
  switch (input) {
  case 'w':
    if (isWall(static_cast<Cell>(maze[position.X - 1][position.Y]))) {
      return;
    }

    velocity.X = -1;
    velocity.Y = 0;
    break;
  case 's':
    if (isWall(static_cast<Cell>(maze[position.X + 1][position.Y]))) {
      return;
    }

    velocity.X = 1;
    velocity.Y = 0;
    break;
  case 'a':
    if (isWall(static_cast<Cell>(maze[position.X][position.Y - 1]))) {
      return;
    }

    velocity.X = 0;
    velocity.Y = -1;
    break;
  case 'd':
    if (isWall(static_cast<Cell>(maze[position.X][position.Y + 1]))) {
      return;
    }

    velocity.X = 0;
    velocity.Y = 1;
    break;
  }
}