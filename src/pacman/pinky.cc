#include "pinky.h"
#include "cell.h"
#include "color.h"

#include <cstdlib>
#include <curses.h>

void Pinky::move(int (&maze)[HEIGHT][WIDTH]) {
  // Yeah yeah, I know how complex the original AI is.
  Point newPosition{position.X + velocity.X, position.Y + velocity.Y};

  // If not wall, move.
  if (!isWall(static_cast<Cell>(maze[newPosition.X][newPosition.Y]))) {
    position.X = newPosition.X;
    position.Y = newPosition.Y;
    return;
  }

  // Switch to a random direction.
  switch ((std::rand() % 4) + 1) {
  case 1:
    velocity.X = 1;
    velocity.Y = 0;
    break;
  case 2:
    velocity.X = -1;
    velocity.Y = 0;
    break;
  case 3:
    velocity.X = 0;
    velocity.Y = 1;
    break;
  case 4:
    velocity.X = 0;
    velocity.Y = -1;
    break;
  }
}

void Pinky::print() {
  attron(COLOR_PAIR(Color::PinkyC));
  mvprintw(position.X + 1, position.Y * 2, GHOST);
  attroff(COLOR_PAIR(Color::PinkyC));
}