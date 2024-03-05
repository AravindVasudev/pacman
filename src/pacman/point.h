#ifndef POINT_H
#define POINT_H

struct Point {
  int X, Y;

  static bool doesOverlap(const Point &p1, const Point &p2);
};

#endif
