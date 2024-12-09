#include <bits/stdc++.h>
using namespace std;
int t[104000];
int v[101000];
int main() {
  int n, a, d;
  int i;
  double x = 0;
  scanf("%d%d%d", &n, &a, &d);
  for (i = 0; i < n; ++i) {
    scanf("%d%d", &t[i], &v[i]);
    double dt = v[i] * 1.0 / a;
    double ht;
    if (0.5 * a * dt * dt > d) {
      ht = sqrt((2 * d * 1.0 / a));
    } else {
      ht = dt + (d * 1.0 - 0.5 * a * dt * dt) / v[i];
    }
    ht = ht + t[i] * 1.0;
    if (ht < x)
      printf("%.7f\n", x);
    else {
      printf("%.7f\n", ht);
      x = ht;
    }
  }
  return 0;
}
