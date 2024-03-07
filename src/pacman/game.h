#ifndef GAME_H
#define GAME_H

#include "blinky.h"
#include "clyde.h"
#include "constants.h"
#include "hero.h"
#include "inky.h"
#include "pinky.h"
#include <array>
#include <iostream>
#include <memory>

class Game {
private:
  int maze[HEIGHT][WIDTH]{}; // The game maze.
  int score{};
  int pelletCount{};
  int pelletsEaten{};

  // Characters.
  Hero hero;
  std::array<std::unique_ptr<Ghost>, 4> ghosts = {
      std::make_unique<Blinky>(BLINKY_X, BLINKY_Y),
      std::make_unique<Pinky>(PINKY_X, PINKY_Y),
      std::make_unique<Inky>(INKY_X, INKY_Y),
      std::make_unique<Clyde>(CLYDE_X, CLYDE_Y),
  };

private:
  static void readMaze(const std::string &path, int (&maze)[HEIGHT][WIDTH]);
  void printWall(const Cell &cell);
  void printMaze();

public:
  Game(std::string mazeFile);
  void run();
};

#endif
