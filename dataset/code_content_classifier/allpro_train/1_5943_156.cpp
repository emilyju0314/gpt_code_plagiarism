#include <bits/stdc++.h>
using namespace std;
int main() {
  double Rad, x1, x2, y1, y2;
  cin >> Rad >> x1 >> y1 >> x2 >> y2;
  double p1, p2, q1, q2, r, X, Y;
  double z = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
  if (z >= Rad) {
    printf("%0.15lf %0.15lf %0.15lf", x1, y1, Rad);
  } else {
    if (x1 != x2) {
      double slop = ((y2 - y1) * 1.0) / (x2 - x1);
      double c = y2 - slop * x2;
      double a01 = 1 + slop * slop;
      double a02 = x1 - slop * (c - y1);
      double a03 = (c - y1) * (c - y1) + x1 * x1 - Rad * Rad;
      double delta = a02 * a02 - a01 * a03;
      double rdel = sqrt(delta);
      p1 = (a02 + rdel) / a01, p2 = (a02 - rdel) / a01;
      q1 = slop * p1 + c, q2 = slop * p2 + c;
    } else {
      p1 = x1;
      p2 = x1;
      q1 = Rad + y1;
      q2 = -Rad + y1;
    }
    double distace1 = sqrt((x2 - p1) * (x2 - p1) + (y2 - q1) * (y2 - q1));
    double distace2 = sqrt((x2 - p2) * (x2 - p2) + (y2 - q2) * (y2 - q2));
    if (distace1 > distace2) {
      X = (p1 + x2) / 2.0;
      Y = (q1 + y2) / 2.0;
      r = distace1 / 2.0;
    } else {
      X = (p2 + x2) / 2.0;
      Y = (q2 + y2) / 2.0;
      r = distace2 / 2.0;
    }
    printf("%0.15lf %0.15lf %0.15lf", X, Y, r);
  }
  return 0;
}
