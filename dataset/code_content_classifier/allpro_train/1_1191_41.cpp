#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
int n, T, a[MAX], b[MAX];
double t1, t2, sol;
struct par {
  double x, y;
  bool operator<(const par &r) const { return x < r.x; }
};
vector<par> v1, v2;
int main() {
  scanf("%d%d", &n, &T);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) {
    if (b[i] == T) {
      sol += a[i];
      continue;
    }
    if (b[i] > T) {
      t1 += 1.0 * a[i] * (b[i] - T);
      v1.push_back({1.0 * b[i] - T, 1.0 * a[i]});
    } else {
      t2 += 1.0 * a[i] * (T - b[i]);
      v2.push_back({1.0 * T - b[i], 1.0 * a[i]});
    }
  }
  if (t1 < t2) {
    for (auto u : v1) sol += u.y;
    sort(v2.begin(), v2.end());
    for (auto u : v2) {
      if (t1 > u.x * u.y) {
        t1 -= u.x * u.y;
        sol += u.y;
      } else {
        sol += t1 / u.x;
        break;
      }
    }
  } else {
    for (auto u : v2) sol += u.y;
    sort(v1.begin(), v1.end());
    for (auto u : v1) {
      if (t2 > u.x * u.y) {
        t2 -= u.x * u.y;
        sol += u.y;
      } else {
        sol += t2 / u.x;
        break;
      }
    }
  }
  printf("%.10lf\n", sol);
  return 0;
}
