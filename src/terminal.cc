/*
 * terminal.cc
 *
 * A simple wrapper around ncurses that exposes a nicer API.
 *
 */

#include "terminal.hpp"
#include <curses.h>

Terminal::Terminal(int X, int Y) {
    // Init
    initscr();
    cbreak();
    noecho();

    WINDOW *win = newwin(X, Y, 0, 0);
    waddch(win, 'a');
    printw("hello world");
    wrefresh(win);
}
