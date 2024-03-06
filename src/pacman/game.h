#ifndef GAME_H
#define GAME_H

#include "blinky.h"
#include "clyde.h"
#include "constants.h"
#include "hero.h"
#include "inky.h"
#include "pinky.h"
#include <iostream>

class Game {
private:
  int maze[HEIGHT][WIDTH]{}; // The game maze.
  int score{};

  // Characters.
  Hero hero;
  Blinky blinky{BLINKY_X, BLINKY_Y};
  Pinky pinky{PINKY_X, PINKY_Y};
  Inky inky{INKY_X, INKY_Y};
  Clyde clyde{CLYDE_X, CLYDE_Y};

  int pelletCount{};

private:
  static void readMaze(const std::string &path, int (&maze)[HEIGHT][WIDTH]);
  void printWall(const Cell &cell);
  void printMaze();

public:
  Game(std::string mazeFile);
  void run();
};

#endif
