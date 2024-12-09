#include <bits/stdc++.h>
using namespace std;
double fgcd(double a, double b) {
  if ((fabs((a) - (0)) < 1E-2)) return b;
  if ((fabs((b) - (0)) < 1E-2)) return a;
  return fgcd(b, fmod(a, b));
}
double diameter(double a, double b, double c) {
  double p = (a + b + c) / 2;
  double s = sqrt(p * (p - a) * (p - b) * (p - c));
  return a * b * c / (4 * s);
}
int main() {
  double x[3], y[3], d[3];
  int i = 0;
  while (~scanf("%lf%lf", &x[i], &y[i])) {
    i++;
    if (i == 3) {
      for (int j = 0; j < 3; ++j)
        d[j] = sqrt((x[j] - x[(j + 1) % 3]) * (x[j] - x[(j + 1) % 3]) +
                    (y[j] - y[(j + 1) % 3]) * (y[j] - y[(j + 1) % 3]));
      double R = diameter(d[0], d[1], d[2]);
      double angle[4];
      for (int j = 0; j < 2; ++j)
        angle[j] = acos(1 - d[j] * d[j] / (2 * R * R));
      angle[2] = 2 * acos(-1.0) - angle[0] - angle[1];
      angle[3] = fgcd(angle[0], fgcd(angle[1], angle[2]));
      printf("%.6lf\n", R * R * sin(angle[3]) * (acos(-1.0) / angle[3]));
      i = 0;
    }
  }
}
