/**
 * Pacman on your terminal!
 *
 * author: Aravind Vasudevan
 */

#include "terminal.hpp"

#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>
#include <curses.h>

#define WIDTH 28
#define HEIGHT 31

/**
 *  Cell represents a maze cell.
 **/
enum Cell {
    topLeftCorner = 1,
    topRightCorner = 2,
    bottomLeftCorner = 3,
    bottomRightCorner = 5,
    horizontal = 2,
    veritical = 6,
    innerTopLeftCorner = 10,
    innerTopRightCorner = 11,
    innerBottomLeftCorner = 9,
    innerBottomRightCorner = 12,
    innerVertical = 7,
    tee = 8,
    empty = 0,
};

const std::string& MAZE_PATH = "./assests/MAZE";

/* readMaze parses the given MAZE file. */
void readMaze(const std::string& path, int (&maze)[HEIGHT][WIDTH]) {
    std::ifstream mazeFile(path);
    std::string line;

    if (!mazeFile.is_open()) {
        throw;
    }

    int row = 0;
    while (mazeFile) {
        std::getline(mazeFile, line);

        // Ignore comments.
        if (line.substr(0, 2) == "//") {
            continue;
        }

        //
        for (int col = 0; col < WIDTH; col++) {
            maze[row][col] = std::atoi(line.substr(col * 3, col * 3 + 3).c_str());
        }

        row++;
    }
}

int main() {
    // Parse the maze.
    int maze[HEIGHT][WIDTH];
    readMaze(MAZE_PATH, maze);

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

    attroff(A_BOLD);

    refresh();
    getch();

    endwin();
}
