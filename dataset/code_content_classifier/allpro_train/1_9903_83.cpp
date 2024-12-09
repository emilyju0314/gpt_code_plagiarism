#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-20;
int s, a, b, c;
int main() {
  scanf("%d%d%d%d", &s, &a, &b, &c);
  double x, y, z;
  if (a == 0 && b == 0 && c == 0) {
    printf("0 0 0\n");
  } else {
    double t = a + b + c;
    t = s / t;
    printf("%.30lf %.30lf %.30lf\n", t * a, t * b, t * c);
  }
  return 0;
}
