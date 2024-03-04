#include "hero.h"
#include "cell.h"

bool Hero::isWall(const Cell &cell) {
  return cell > Cell::empty && cell < Cell::pellet;
}

void Hero::move(int (&maze)[HEIGHT][WIDTH]) {
  Point newPosition{position.X + velocity.X, position.Y + velocity.Y};

  // Don't move if wall.
  if (isWall(static_cast<Cell>(maze[newPosition.X][newPosition.Y]))) {
    return;
  }

  position.X = newPosition.X;
  position.Y = newPosition.Y;
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