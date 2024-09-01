#ifndef CONSTANTS_H
#define CONSTANTS_H

#define FRAME_RATE 10

// Game maze size.
#define WIDTH 28
#define HEIGHT 31

// Start Positions.
#define HERO_X 23
#define HERO_Y 13

#define BLINKY_X 14
#define BLINKY_Y 11

#define INKY_X 14
#define INKY_Y 12

#define PINKY_X 14
#define PINKY_Y 13

#define CLYDE_X 14
#define CLYDE_Y 14

// Speeds.
// TODO: Setting independent speeds cause input lag. Fix this.
#define HERO_SPEED 0
#define GHOST_SPEED 0

#define FRIGHTENED_DURATION 5000    // 5 seconds.
#define FRIGHTENED_BLINK_START 3000 // Starts blinking after 3 seconds.

// Points.
#define POWER_PELLET_POINT 5
#define EAT_GHOST 10

// Box Drawing Constants.
#define EMPTY "  "
#define TOP_LEFT_CORNER "╔"
#define HORIZONTAL "══"
#define TOP_RIGHT_CORNER "╗"
#define BOTTOM_LEFT_CORNER "╚"
#define BOTTOM_RIGHT_CORNER "╝"
#define VERTICAL "║"
#define INNER_VERTICAL "║ "
#define LEFT_TEE "╦═"
#define INNER_BOTTOM_LEFT_CORNER "╚═"
#define INNER_TOP_LEFT_CORNER "╔═"
#define INNER_TOP_RIGHT_CORNER "╗ "
#define INNER_BOTTOM_RIGHT_CORNER "╝ "
#define PELLET ". "
#define POWER_PELLET "● "
#define GHOST "\""

#endif