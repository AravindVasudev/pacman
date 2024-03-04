#include "game.h"
#include "hero.h"
#include "view.h"

#include <chrono>
#include <curses.h>
#include <fstream>
#include <locale.h>
#include <string>
#include <unistd.h>

Game::Game(std::string mazeFile) {
  // Load the maze.
  readMaze(mazeFile, maze);
}

void Game::readMaze(const std::string &path, int (&maze)[HEIGHT][WIDTH]) {
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
  auto oldTime = std::chrono::steady_clock::now();

  while (true) {
    char input = getch();

    if (input == 'q') {
      break;
    }

    // Process input.
    hero.input(maze, input);

    // This time elapsed check just ensures that the hero's speed is independent
    // from the frame rate.
    auto now = std::chrono::steady_clock::now();
    auto timeElapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(now - oldTime)
            .count();

    if (timeElapsed > HERO_SPEED) {
      score += hero.move(maze);
      oldTime = std::chrono::steady_clock::now();
    }

    // Draw the canvas.
    view.printMaze(maze, score);
    view.printHero(hero);
    refresh();

    // Handle frame rate.
    usleep(1000000 / FRAME_RATE);
  }

  endwin();
}