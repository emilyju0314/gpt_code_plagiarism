#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
int n, l, v1, v2, k;
int main() {
  scanf("%d%d%d%d%d", &n, &l, &v1, &v2, &k);
  if (k == n) {
    printf("%.12f\n", 1.0 * l / v2);
  } else {
    int m = n / k;
    if (m * k < n) m++;
    m--;
    double t = 1.0 * l / (2.0 * m * v1 * v2 / (v1 + v2) + v2);
    printf("%.12f\n", t + m * (2.0 * v2 / (v1 + v2) * t));
  }
  return 0;
}
