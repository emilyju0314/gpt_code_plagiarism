#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1e18;
const long long int mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  long long int n, x, p, res, k, r, d, l;
  cin >> n >> k;
  if (n == k || k == 0)
    cout << 0 << " " << 0 << endl;
  else {
    p = n / k;
    if (p >= 3)
      res = k * 2;
    else {
      r = n % 3;
      d = n / 3;
      l = k - d;
      if (l < r)
        res = 2 * d + 1;
      else if (l == r)
        res = 2 * d;
      else {
        res = 2 * d - (l - r);
      }
    }
    cout << 1 << " " << res << endl;
  }
}
