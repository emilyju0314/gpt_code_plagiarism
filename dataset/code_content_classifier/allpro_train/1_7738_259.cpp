#include <bits/stdc++.h>
using namespace std;
int main() {
  double w, h, alpha;
  cin >> w >> h >> alpha;
  if (w < h) swap(w, h);
  if (alpha > 90) alpha = 180 - alpha;
  alpha = alpha * 3.14159265359 / 180.0;
  double beta = 2 * atan2(h, w);
  double ans = 0;
  if (alpha < 1E-10) {
    ans = h * w;
  } else if (alpha >= beta) {
    double trapezoids = (w - (h / (cos(3.14159265359 / 2 - alpha)))) * h;
    ans = h * w - trapezoids;
  } else {
    double h1 = (h * cos(alpha) + w * sin(alpha) - h) / 2.0;
    double b1 = h1 / tan(alpha) + h1 / tan(3.14159265359 / 2.0 - alpha);
    double h2 = (w * cos(alpha) + h * sin(alpha) - w) / 2.0;
    double b2 = h2 / tan(alpha) + h2 / tan(3.14159265359 / 2.0 - alpha);
    ans = h * w - (h1 * b1 + h2 * b2);
  }
  printf("%.9lf\n", ans);
  return 0;
}
