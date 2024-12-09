#include <bits/stdc++.h>
using namespace std;
int64_t steps[6][3] = {{1, 2, 1},   {-1, 2, 0}, {-2, 0, 1},
                       {-1, -2, 1}, {1, -2, 1}, {2, 0, 1}};
inline int64_t f(int64_t const& x) {
  return 5 + 6 * (x * (x + 1) / 2 - 1) - x + 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  int64_t n;
  cin >> n;
  int64_t x, y, ring, times, lo, hi;
  x = y = ring = times = 0;
  lo = 1, hi = n > 1e9 ? 1e9 : n;
  while (lo < hi) {
    auto const&& mid = (hi + lo) >> 1;
    auto const&& x = f(mid);
    if (n < x) {
      hi = mid;
    } else {
      ring = x;
      times = mid;
      lo = mid + 1;
    }
    if (n == x) break;
  }
  x += times;
  y -= (times << 1);
  n -= ring;
  for (int in = 6; in > 0; steps[--in][2] += times)
    ;
  int index = 0;
  while (n > 0) {
    auto s = min(steps[index][2], n);
    x += steps[index][0] * s;
    y += steps[index][1] * s;
    n -= s;
    index = (index + 1) % 6;
  }
  cout << x << ' ' << y << endl;
}
