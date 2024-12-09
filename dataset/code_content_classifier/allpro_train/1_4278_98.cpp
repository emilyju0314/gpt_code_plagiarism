#include <bits/stdc++.h>
using namespace std;
const double zero = 1e-8;
int main() {
  double t1, t2, t3;
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  if ((b - a == c - b) && (c - b == d - c)) {
    printf("%d\n", d + c - b);
    return 0;
  }
  if ((a != 0) && (b != 0) && (c != 0) && (d != 0) && (a != b)) {
    t1 = b / (a + 0.0);
    t2 = c / (b + 0.0);
    t3 = d / (c + 0.0);
    if (fabs(t1 - t2) < zero && fabs(t2 - t3) < zero) {
      double e = d * t1;
      if ((e - floor(e)) < zero) {
        printf("%.0lf\n", e);
        return 0;
      }
    }
  }
  printf("42\n");
  return 0;
}
