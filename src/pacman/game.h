#ifndef GAME_H
#define GAME_H

#include "blinky.h"
#include "constants.h"
#include "ghost.h"
#include "hero.h"
#include <iostream>

class Game {
private:
  int maze[HEIGHT][WIDTH]{}; // The game maze.
  Hero hero;
  Blinky blinky;
  int score{};

private:
  static void readMaze(const std::string &path, int (&maze)[HEIGHT][WIDTH]);
  void printWall(const Cell &cell);
  void printMaze();

public:
  Game(std::string mazeFile);
  void run();
};

#endif
