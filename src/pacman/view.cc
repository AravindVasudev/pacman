
#include "view.h"
#include "constants.h"
#include "cell.h"
#include "color.h"
#include "hero.h"
#include <locale.h>
#include <curses.h>

View::View() {
  // Init basics.
  setlocale(LC_ALL, ""); // Get the terminal outta boomer-mode.
  initscr();
  raw();
  noecho();

  // Init Colors.
  start_color();
  init_pair(Color::Wall, COLOR_BLUE, COLOR_BLACK);
  init_pair(Color::Pellet, COLOR_YELLOW, COLOR_BLACK);
  init_pair(Color::HeroC, COLOR_GREEN, COLOR_BLACK);

}

void View::printWall(const Cell& cell) {
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

void View::printMaze(int (&maze)[HEIGHT][WIDTH]) {
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

void View::printHero(const Hero& hero) {
    attron(COLOR_PAIR(Color::HeroC));
    mvprintw(hero.X, hero.Y, ">");
    attroff(COLOR_PAIR(Color::HeroC));
}