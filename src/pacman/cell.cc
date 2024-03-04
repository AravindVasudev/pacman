#include "cell.h"

bool isWall(const Cell &cell) {
  return cell > Cell::empty && cell < Cell::pellet;
}