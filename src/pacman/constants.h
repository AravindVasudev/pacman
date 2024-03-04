#ifndef CONSTANTS_H
#define CONSTANTS_H

#define FRAME_RATE 60 // 60 FPS

// Game maze size.
#define WIDTH 28
#define HEIGHT 31

// Start Positions.
#define HERO_X 23
#define HERO_Y 13
#define GHOST_X 1
#define GHOST_Y 1

// Speeds.
#define HERO_SPEED 200
#define GHOST_SPEED 300

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

// Direction Key Code.
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#endif