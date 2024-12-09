#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30) - 1;
const long double EPS = 1e-9;
const long double PI = fabsl(atan2l(0.0, -1.0));
int n;
double a[5222];
void load() {
  scanf("%d", &n);
  n *= 2;
  for (int i = 0; i < n; i++) {
    scanf("%lf", &a[i]);
  }
}
int b[5333];
void solve() {
  int bad = 0;
  double s = 0;
  int s2 = 0;
  for (int i = 0; i < n; i++) {
    b[i] = (int)floor(a[i]);
    if (fabs(b[i] - a[i]) < EPS) {
      bad++;
    }
    s += a[i];
    s2 += b[i];
  }
  int good = n - bad;
  double best = 1e42;
  for (int same = 0; same <= bad / 2; same++) {
    int rem = bad - 2 * same;
    for (int addZero = 0; addZero <= rem; addZero++) {
      int cur = s2;
      if (addZero > good) {
        break;
      }
      int rem2 = rem - addZero;
      int remGood = good - addZero;
      if (remGood < rem2) {
        continue;
      }
      cur += rem2;
      remGood -= rem2;
      if (remGood % 2 != 0) {
        continue;
      }
      cur += remGood / 2;
      best = min(best, fabs(s - cur));
    }
  }
  printf("%.3lf\n", best);
}
int main() {
  clock_t start = clock();
  load();
  solve();
  ;
  return 0;
}
