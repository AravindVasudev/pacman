#ifndef CELL_H
#define CELL_H

/**
 *  Cell represents a maze cell.
 **/
enum Cell {
    empty = 0,
    topLeftCorner,
    horizontal,
    topRightCorner,
    bottomLeftCorner,
    bottomRightCorner,
    veritical,
    innerVertical,
    leftTee,
    innerBottomLeftCorner,
    innerTopLeftCorner,
    innerTopRightCorner,
    innerBottomRightCorner,
    pellet,
    powerPellet,
};

#endif
