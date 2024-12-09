#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, m, ans;
  while (cin >> x >> y >> m) {
    ans = 0;
    long long da, xi;
    da = max(x, y);
    xi = min(x, y);
    if (da >= m) {
      cout << ans << endl;
      continue;
    } else if (x + y <= xi) {
      ans = -1;
      cout << ans << endl;
      continue;
    } else
      while (da < m) {
        xi = min(x, y);
        if (xi < 0) {
          ans = abs(xi) / da + 1;
          xi = ans * da + xi;
        }
        ans++;
        x = da;
        y = x + xi;
        da = max(x, y);
      }
    cout << ans << endl;
  }
  return 0;
}
