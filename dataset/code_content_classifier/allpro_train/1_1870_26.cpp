#include <bits/stdc++.h>
using namespace std;
int m, n, j, k, l, i, o, p, __t, kth;
double r1, r2;
const double exchange = 1000;
int main() {
  scanf("%d", &o);
  for (; o--;) {
    scanf("%lf%lf%d", &r1, &r2, &kth);
    double x1 = exchange / (2 * r1);
    double x2 = exchange / (2 * r2);
    double r = (x2 - x1) * 0.5;
    double X = (x1 + x2) / 2.0;
    double Y = kth * (x2 - x1);
    double dis = sqrt(X * X + Y * Y);
    printf("%.10lf\n", (exchange / (dis - r) - exchange / (dis + r)) / 2);
  }
}
