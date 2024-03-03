#include "hero.h"
#include "cell.h"

void Hero::move(int (&maze)[HEIGHT][WIDTH]) {
  Point newPosition{position.X + velocity.X, position.Y + velocity.Y};

  // Don't move if wall.
  if (maze[newPosition.X][newPosition.Y] > Cell::empty &&
      maze[newPosition.X][newPosition.Y] < Cell::pellet) {
    return;
  }

  position.X = newPosition.X;
  position.Y = newPosition.Y;
}

void Hero::input(const char &input) {
  // So, there's the thing. A couldn't recognize arrow keys. Could be a mac
  // issue? Using wasd to unblock myself. TODO(future me): Support arrow keys.
  switch (input) {
  case 'w':
    velocity.X = -1;
    velocity.Y = 0;
    break;
  case 's':
    velocity.X = 1;
    velocity.Y = 0;
    break;
  case 'a':
    velocity.X = 0;
    velocity.Y = -1;
    break;
  case 'd':
    velocity.X = 0;
    velocity.Y = 1;
    break;
  }
}