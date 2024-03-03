
#include "view.h"
#include "constants.h"
#include "cell.h"
#include <locale.h>
#include <curses.h>

View::View() {
  // Init basics.
  setlocale(LC_ALL, ""); // Get the terminal outta boomer-mode.
  initscr();
  raw();
  noecho();

  // Print the damn maze
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK); // Wall color.
}

void View::printMaze(int (&maze)[HEIGHT][WIDTH]) {
  attron(A_BOLD);
  attron(COLOR_PAIR(1));

  for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
          switch (maze[i][j]) {
              case Cell::empty:
                  printw("  ");
                  break;
              case Cell::topLeftCorner:
                  printw("╔");
                  break;
              case Cell::horizontal:
                  printw("══");
                  break;
              case Cell::topRightCorner:
                  printw("╗");
                  break;
              case Cell::bottomLeftCorner:
                  printw("╚");
                  break;
              case Cell::bottomRightCorner:
                  printw("╝");
                  break;
              case Cell::veritical:
                  printw("║");
                  break;
              case Cell::innerVertical:
                  printw("║ ");
                  break;
              case Cell::leftTee:
                  printw("╦═");
                  break;
              case Cell::innerBottomLeftCorner:
                  printw("╚═");
                  break;
              case Cell::innerTopLeftCorner:
                  printw("╔═");
                  break;
              case Cell::innerTopRightCorner:
                  printw("╗ ");
                  break;
              case Cell::innerBottomRightCorner:
                  printw("╝ ");
                  break;
          }
      }
      addch('\n');
  }

  refresh();
  attroff(A_BOLD);
  attroff(COLOR_PAIR(1));
}