
#include "view.h"
#include "cell.h"
#include "color.h"
#include "constants.h"
#include "ghost.h"
#include "hero.h"
#include <curses.h>
#include <locale.h>
#include <string>

View::View() {
  // Init basics.
  setlocale(LC_ALL, ""); // Get the terminal outta boomer-mode.
  initscr();
  keypad(stdscr, true);
  curs_set(false);
  timeout(0);
  raw();
  noecho();

  // Init Colors.
  start_color();
  init_pair(Color::Wall, COLOR_BLUE, COLOR_BLACK);
  init_pair(Color::Pellet, COLOR_YELLOW, COLOR_BLACK);
  init_pair(Color::HeroC, COLOR_BLACK, COLOR_YELLOW);
  init_pair(Color::Blinky, COLOR_BLACK, COLOR_RED);
  init_pair(Color::Inky, COLOR_BLACK, COLOR_CYAN);
  init_pair(Color::Pinky, COLOR_BLACK, COLOR_MAGENTA);
  init_pair(Color::Clyde, COLOR_BLACK,
            COLOR_YELLOW); // TODO: Make Clyde orange.
}

void View::printWall(const Cell &cell) {
  attron(COLOR_PAIR(Color::Wall));

  switch (cell) {
  case Cell::empty:
    printw(EMPTY);
    break;
  case Cell::topLeftCorner:
    printw(TOP_LEFT_CORNER);
    break;
  case Cell::horizontal:
    printw(HORIZONTAL);
    break;
  case Cell::topRightCorner:
    printw(TOP_RIGHT_CORNER);
    break;
  case Cell::bottomLeftCorner:
    printw(BOTTOM_LEFT_CORNER);
    break;
  case Cell::bottomRightCorner:
    printw(BOTTOM_RIGHT_CORNER);
    break;
  case Cell::veritical:
    printw(VERTICAL);
    break;
  case Cell::innerVertical:
    printw(INNER_VERTICAL);
    break;
  case Cell::leftTee:
    printw(LEFT_TEE);
    break;
  case Cell::innerBottomLeftCorner:
    printw(INNER_BOTTOM_LEFT_CORNER);
    break;
  case Cell::innerTopLeftCorner:
    printw(INNER_TOP_LEFT_CORNER);
    break;
  case Cell::innerTopRightCorner:
    printw(INNER_TOP_RIGHT_CORNER);
    break;
  case Cell::innerBottomRightCorner:
    printw(INNER_BOTTOM_RIGHT_CORNER);
    break;
  default:
    // Do nothing.
    break;
  }

  attroff(COLOR_PAIR(Color::Wall));
}

void View::printMaze(int (&maze)[HEIGHT][WIDTH], const int &score) {
  move(0, 0);
  printw("SCORE: %d\n", score);
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      switch (maze[i][j]) {
      case Cell::pellet:
        attron(COLOR_PAIR(Color::Pellet));
        printw(PELLET);
        attroff(COLOR_PAIR(Color::Pellet));
        break;
      case Cell::powerPellet:
        attron(COLOR_PAIR(Color::Pellet));
        printw(POWER_PELLET);
        attroff(COLOR_PAIR(Color::Pellet));
        break;
      default:
        printWall(static_cast<Cell>(maze[i][j]));
        break;
      }
    }
    addch('\n');
  }
}

void View::printHero(const Hero &hero) {
  // Simulate hero chewing.
  std::string mouth;
  if (heroMouthOpen) {
    if (hero.velocity.X == -1 && hero.velocity.Y == 0) { // Up
      mouth = "V";
    } else if (hero.velocity.X == 1 && hero.velocity.Y == 0) { // Down
      mouth = "^";
    } else if (hero.velocity.X == 0 && hero.velocity.Y == -1) { // Left
      mouth = ">";
    } else { // Right
      mouth = "<";
    }

    heroMouthOpen = false;
  } else {
    mouth = "—";
    heroMouthOpen = true;
  }

  attron(COLOR_PAIR(Color::HeroC));
  mvprintw(hero.position.X + 1, hero.position.Y * 2,
           mouth.c_str()); // Wierd offsets, I know.
  attroff(COLOR_PAIR(Color::HeroC));
}

void View::printGhost(const Ghost &ghost) {
  attron(COLOR_PAIR(Color::Blinky));
  mvprintw(ghost.position.X + 1, ghost.position.Y * 2, GHOST);
  attroff(COLOR_PAIR(Color::Blinky));
}
