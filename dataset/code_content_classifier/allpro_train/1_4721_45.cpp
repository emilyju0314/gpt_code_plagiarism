#include <bits/stdc++.h>
using namespace std;
void rotate(double &x, double &y, double th) {
  double x1 = x * cos(th) - y * sin(th);
  double y1 = x * sin(th) + y * cos(th);
  x = x1;
  y = y1;
}
int main() {
  ios::sync_with_stdio(false);
  int x0, y0, x1, y1;
  cin >> x0 >> y0 >> x1 >> y1;
  if (x0 == x1 && y0 == y1) {
    cout << 0 << endl;
    return 0;
  }
  long long v, t;
  cin >> v >> t;
  long long ux, uy, wx, wy;
  cin >> ux >> uy >> wx >> wy;
  long long sx = x1 - x0;
  long long sy = y1 - y0;
  long long nx = -sy;
  long long ny = sx;
  long long s2 = sx * sx + sy * sy;
  long long un2 = (nx * ux + ny * uy) * (nx * ux + ny * uy);
  long long us = (sx * ux + sy * uy);
  double v1s = us + sqrt(double(v * v * s2 - un2));
  double tt = 0;
  if (v1s * t > s2) {
    tt = s2 / v1s;
  } else {
    sx -= ux * t;
    sy -= uy * t;
    sx += wx * t;
    sy += wy * t;
    nx = -sy;
    ny = sx;
    s2 = sx * sx + sy * sy;
    double wn2 = double(nx * wx + ny * wy) * (nx * wx + ny * wy);
    double ws = double(sx * wx + sy * wy);
    double v2s = ws + sqrt(double(v * v * s2 - wn2));
    tt = s2 / v2s;
  }
  cout << fixed << setprecision(10) << tt << endl;
  return 0;
}
