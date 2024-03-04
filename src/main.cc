/**
 * Pacman on your terminal!
 *
 * author: Aravind Vasudevan
 */

#include "pacman/game.h"

#include <curses.h>
#include <fstream>
#include <iostream>
#include <locale.h>
#include <string>

const std::string &MAZE_PATH = "./assests/MAZE";

int main() {
  Game game(MAZE_PATH);
  game.run();

  // Reset timeout and block.
  timeout(-1);
  getch();
  endwin();
}
