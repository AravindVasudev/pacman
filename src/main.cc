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

int main() {
    Game game(MAZE_PATH);
    game.run();
}
