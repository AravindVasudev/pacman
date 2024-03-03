
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
          }
      }
      addch('\n');
  }

  refresh();
  attroff(A_BOLD);
  attroff(COLOR_PAIR(1));
}