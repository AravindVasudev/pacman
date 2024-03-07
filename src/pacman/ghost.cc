#include "ghost.h"
#include "color.h"

#include <ncurses.h>

void Ghost::frightenedMove(int (&maze)[HEIGHT][WIDTH]) { move(maze); }

void Ghost::reset() {
  position.X = start.X;
  position.Y = start.Y;
  isFrightened = false;
  frightenedTimeoutBlink = false;
}

void Ghost::draw(const Color &color) {
  Color ghostColor;
  if (isFrightened) {
    // When in the last few seconds of frightened mode, i.e.,
    // "frightenedTimeoutBlink", use frightenedBlinkSwitch to draw b/w
    // FrightenedBlinkC & FrightenedC to blink and notify the user.
    if (frightenedTimeoutBlink && frightenedBlinkSwitch) {
      frightenedBlinkSwitch = false;
      ghostColor = Color::FrightenedBlinkC;
    } else {
      ghostColor = Color::FrightenedC;
      if (frightenedTimeoutBlink) {
        frightenedBlinkSwitch = true;
      }
    }
  } else {
    ghostColor = color;
  }

  attron(COLOR_PAIR(ghostColor));
  mvprintw(position.X + 1, position.Y * 2, GHOST);
  attroff(COLOR_PAIR(ghostColor));
}