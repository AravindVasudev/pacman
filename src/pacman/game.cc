#include "game.h"
#include "color.h"
#include "hero.h"

#include <chrono>
#include <curses.h>
#include <fstream>
#include <locale.h>
#include <string>
#include <unistd.h>

Game::Game(std::string mazeFile) {
  // Load the maze.
  readMaze(mazeFile, maze);

  // Init Graphics.
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
  init_pair(Color::BlinkyC, COLOR_BLACK, COLOR_RED);
  init_pair(Color::InkyC, COLOR_BLACK, COLOR_CYAN);
  init_pair(Color::PinkyC, COLOR_BLACK, COLOR_MAGENTA);
  init_pair(Color::ClydeC, COLOR_BLACK,
            COLOR_YELLOW); // TODO: Make Clyde orange.
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

void Game::printWall(const Cell &cell) {
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

void Game::printMaze() {
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

void Game::run() {
  auto heroTime = std::chrono::steady_clock::now();
  auto ghostTime = std::chrono::steady_clock::now();

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
    auto heroTimeElapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(now - heroTime)
            .count();

    if (heroTimeElapsed > HERO_SPEED) {
      score += hero.move(maze);
      heroTime = std::chrono::steady_clock::now();
    }

    auto ghostTimeElapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(now - ghostTime)
            .count();
    if (ghostTimeElapsed > GHOST_SPEED) {
      blinky.move(maze);
      ghostTime = std::chrono::steady_clock::now();
    }

    // Draw the canvas.
    printMaze();
    hero.print();
    blinky.print();

    // Game over :(
    if (hero.position.X == blinky.position.X &&
        hero.position.Y == blinky.position.Y) {
      move(0, 0);
      printw("GAME OVER!!!!! SCORE: %d\n", score);
      return;
    }

    // Draw the frame.
    refresh();

    // Handle frame rate.
    usleep(1000000 / FRAME_RATE);
  }
}