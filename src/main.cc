/**
 * Pacman on your terminal!
 *
 * author: Aravind Vasudevan
 */

#include "terminal.hpp"
#include <locale.h>
#include <curses.h>

#define WIDTH 28
#define HEIGHT 3

int maze[HEIGHT][WIDTH] = {
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3},
    {6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
    {4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5},
};

int main() {
    /* Terminal terminal(10, 10); */
    // Init basics.
    setlocale(LC_ALL, ""); // Get the terminal outta boomer-mode.
    initscr();
    raw();
    noecho();

    // Print the damn maze
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK); // Wall color.
    attron(A_BOLD);
    attron(COLOR_PAIR(1));

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            switch (maze[i][j]) {
                case 0:
                    printw("  ");
                    break;
                case 1:
                    /* addch('═'); */
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
            }
        }
        addch('\n');
    }

    /* printw("Hello World"); */
    attroff(A_BOLD);

    refresh();
    getch();

    endwin();
}
