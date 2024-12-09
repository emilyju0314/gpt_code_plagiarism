#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e18;
const long long mod = (long long)1e9 + 7;
const double eps = (double)1e-9;
const double pi = acos(-1.0);
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};
const int N = 100500;
int x, h, m, t;
inline bool ok(int cur) {
  int h1 = cur / 60;
  int m1 = cur % 60;
  return (h1 / 10 == 7 || h1 % 10 == 7 || m1 / 10 == 7 || m1 % 10 == 7);
}
int main() {
  cin >> x >> h >> m;
  int t = h * 60 + m;
  for (int y = 0; y < 1440; y++) {
    int cur = t - x * y;
    while (cur < 0) cur += 1440;
    if (ok(cur)) {
      cout << y;
      return 0;
    }
  }
  assert(0);
  return 0;
}
