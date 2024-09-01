#include "hero.h"

#include <curses.h>

#include <string>

#include "cell.h"
#include "color.h"

int Hero::move(int (&maze)[HEIGHT][WIDTH]) {
  Point newPosition{position.X + velocity.X, position.Y + velocity.Y};

  // Don't move if wall.
  if (isWall(static_cast<Cell>(maze[newPosition.X][newPosition.Y]))) {
    return 0;
  }

  position.X = newPosition.X;
  position.Y = newPosition.Y;

  // If the new position has a pellet, eat it.
  if (maze[position.X][position.Y] >= Cell::pellet) {
    int score =
        (maze[position.X][position.Y] == Cell::powerPellet ? POWER_PELLET_POINT
                                                           : 1);
    maze[position.X][position.Y] = Cell::empty;
    return score;
  }

  return 0;
}

void Hero::input(int (&maze)[HEIGHT][WIDTH], const int &input) {
  // So, there's the thing. A couldn't recognize arrow keys. Could be a mac
  // issue? Using wasd to unblock myself. TODO(future me): Support arrow keys.
  switch (input) {
    case 'w':
    case KEY_UP:
      if (isWall(static_cast<Cell>(maze[position.X - 1][position.Y]))) {
        return;
      }

      velocity.X = -1;
      velocity.Y = 0;
      break;
    case 's':
    case KEY_DOWN:
      if (isWall(static_cast<Cell>(maze[position.X + 1][position.Y]))) {
        return;
      }

      velocity.X = 1;
      velocity.Y = 0;
      break;
    case 'a':
    case KEY_LEFT:
      if (isWall(static_cast<Cell>(maze[position.X][position.Y - 1]))) {
        return;
      }

      velocity.X = 0;
      velocity.Y = -1;
      break;
    case 'd':
    case KEY_RIGHT:
      if (isWall(static_cast<Cell>(maze[position.X][position.Y + 1]))) {
        return;
      }

      velocity.X = 0;
      velocity.Y = 1;
      break;
  }
}

void Hero::print() {
  // Simulate hero chewing.
  std::string mouth;
  if (heroMouthOpen) {
    if (velocity.X == -1 && velocity.Y == 0) {  // Up
      mouth = "V";
    } else if (velocity.X == 1 && velocity.Y == 0) {  // Down
      mouth = "^";
    } else if (velocity.X == 0 && velocity.Y == -1) {  // Left
      mouth = ">";
    } else {  // Right
      mouth = "<";
    }

    heroMouthOpen = false;
  } else {
    mouth = "—";
    heroMouthOpen = true;
  }

  attron(COLOR_PAIR(Color::HeroC));
  mvprintw(position.X + 1, position.Y * 2,
           mouth.c_str());  // Wierd offsets, I know.
  attroff(COLOR_PAIR(Color::HeroC));
}