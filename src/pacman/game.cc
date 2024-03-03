#include "game.h"
#include "hero.h"
#include "view.h"

#include <locale.h>
#include <fstream>
#include <string>
#include <curses.h>
#include <unistd.h>


Game::Game(std::string mazeFile) {
  // Load the maze.
  readMaze(mazeFile, maze);
}

void Game::readMaze(const std::string& path, int (&maze)[HEIGHT][WIDTH]) {
    std::ifstream mazeFile(path);
    std::string line;

    if (!mazeFile.is_open()) {
        throw;
    }

    int row = 0;
    while (mazeFile) {
        if (row >= HEIGHT) {
            break;
        }

        std::getline(mazeFile, line);

        // Ignore comments.
        if (line.substr(0, 2) == "//") {
            continue;
        }

        for (int col = 0; col < WIDTH; col++) {
            maze[row][col] = std::stoi(line.substr(col * 3, col * 3 + 3));
        }

        row++;
    }
}

void Game::run() {
    
    
    refresh();

    while (true) {
        view.printMaze(maze);
        view.printHero(hero);

        refresh();

        hero.move();
        usleep(1000000 / FRAME_RATE);
    }


    getch();
    endwin();
}