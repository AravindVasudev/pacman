/**
 * Pacman on your terminal!
 *
 * author: Aravind Vasudevan
 */

#include "pacman/game.h"

#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>
#include <curses.h>

const std::string& MAZE_PATH = "./assests/MAZE";

int main() {
    Game game(MAZE_PATH);
    game.run();
}
