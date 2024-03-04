#ifndef GAME_H
#define GAME_H

#include "constants.h"
#include "ghost.h"
#include "hero.h"
#include "view.h"
#include <iostream>

class Game {
private:
  int maze[HEIGHT][WIDTH]{}; // The game maze.
  View view;
  Hero hero;
  Ghost ghost;
  int score{};

private:
  static void readMaze(const std::string &path, int (&maze)[HEIGHT][WIDTH]);

public:
  Game(std::string mazeFile);
  void run();
};

#endif
