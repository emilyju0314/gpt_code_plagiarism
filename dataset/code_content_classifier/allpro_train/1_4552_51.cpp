#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long x, y, p, q;
  cin >> x >> y >> p >> q;
  if (p == 0) {
    if (x == 0)
      return 0;
    else
      return -1;
  }
  if (p == q) {
    if (x == y)
      return 0;
    else
      return -1;
  }
  long long lo = 1, hi = 1e18 / max(p, q);
  while (hi > lo) {
    long long mid = (lo + hi) / 2;
    if (p * mid >= x and q * mid >= y and p * mid - x <= q * mid - y)
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo * q - y;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }
}
