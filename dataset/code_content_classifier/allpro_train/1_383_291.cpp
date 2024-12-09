#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int main() {
  int N, t[10], w[10], a, b;
  for (int i = 1; i <= 5; i++) scanf("%d", &t[i]);
  for (int i = 1; i <= 5; i++) scanf("%d", &w[i]);
  scanf("%d %d", &a, &b);
  double val = 100.0 * a - 50.0 * b;
  for (int i = 1; i <= 5; i++) {
    double x = i * 500.0;
    double curr = x - (double)x * t[i] / 250.0 - 50.0 * w[i];
    if (0.3 * x > curr) curr = 0.3 * x;
    val += curr;
  }
  printf("%.lf\n", val);
  return 0;
}
