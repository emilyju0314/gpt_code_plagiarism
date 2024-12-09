#include <bits/stdc++.h>
using namespace std;
double x[3], y[3], r[3];
double ang[3];
const int off_x[4] = {1, 0, 0, -1};
const int off_y[4] = {0, 1, -1, 0};
inline double dis(double x1, double y1, double x2, double y2) {
  return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}
double eval(double x0, double y0) {
  for (int i = 0; i < 3; i++) ang[i] = dis(x0, y0, x[i], y[i]) / r[i];
  double val = 0;
  for (int i = 0; i < 3; i++)
    val += ((ang[i] - ang[(i + 1) % 3]) * (ang[i] - ang[(i + 1) % 3]));
  return val;
}
int main() {
  for (int i = 0; i < 3; i++) {
    cin >> x[i] >> y[i] >> r[i];
  }
  double x0 = x[0] + (x[1] - x[0]) * r[0] / (r[0] + r[1]);
  double y0 = y[0] + (y[1] - y[0]) * r[0] / (r[0] + r[1]);
  double v, mv = eval(x0, y0);
  double step = 1.0;
  for (int i = 0; i < 100000; i++) {
    double x1, y1;
    int c = 0;
    for (int d = 0; d < 4; d++) {
      double x2 = x0 + off_x[d] * step;
      double y2 = y0 + off_y[d] * step;
      v = eval(x2, y2);
      if (v < mv) {
        c++;
        mv = v;
        x1 = x2;
        y1 = y2;
      }
    }
    if (c) {
      x0 = x1;
      y0 = y1;
    } else {
      step /= 2;
    }
  }
  if (mv < 1e-6) {
    printf("%.5f %.5f\n", x0, y0);
  }
  return 0;
}
