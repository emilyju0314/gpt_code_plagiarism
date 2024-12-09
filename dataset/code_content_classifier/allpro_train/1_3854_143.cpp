#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, p, x, y, ans = 0, i, s = 0, t, pt = 0;
  cin >> n >> k >> p >> x >> y;
  for (i = 0; i < k; i++) {
    cin >> t;
    if (t >= y) pt++;
    s += t;
  }
  pt = max(0, ((n + 1) / 2 - pt));
  if (s > x || y > x || n - k < pt)
    cout << "-1";
  else if (pt * y + s + (n - k - pt) > x)
    cout << "-1";
  else {
    for (i = 0; i < pt; i++) cout << y << " ";
    for (i = 0; i < (n - k - pt); i++) cout << 1 << " ";
  }
  return 0;
}
