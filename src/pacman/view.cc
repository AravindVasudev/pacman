
#include "view.h"
#include "constants.h"
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
              case 0:
                  printw("  ");
                  break;
              case 1:
                  printw("╔");
                  break;
              case 2:
                  printw("══");
                  break;
              case 3:
                  printw("╗");
                  break;
              case 4:
                  printw("╚");
                  break;
              case 5:
                  printw("╝");
                  break;
              case 6:
                  printw("║");
                  break;
              case 7:
                  printw("║ ");
                  break;
              case 8:
                  printw("╦═");
                  break;
              case 9:
                  printw("╚═");
                  break;
              case 10:
                  printw("╔═");
                  break;
              case 11:
                  printw("╗ ");
                  break;
              case 12:
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