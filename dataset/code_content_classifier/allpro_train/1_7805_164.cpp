#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
const double pi = acos(-1.0);
const long long mod = 1004535809;
const long long Mod = 1e9 + 7;
const long long g = 3;
struct node {
  long long d, h;
  friend bool operator<(node x, node y) { return x.d - x.h > y.d - y.h; }
};
node a[maxn];
long long dp[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, x;
    cin >> n >> x;
    long long maxs = 0;
    long long res = 0;
    long long gd = 0, gh = 0;
    for (int i = 1; i <= n; i++) {
      long long d, h;
      cin >> d >> h;
      if (res <= d - h) {
        if (res == d - h) {
          if (d > gd) gd = d, gh = h;
        } else {
          res = d - h;
          gd = d;
          gh = h;
        }
      }
      maxs = max(maxs, d);
    }
    if (res <= 0 && x > maxs)
      cout << -1 << endl;
    else if (x <= maxs)
      cout << 1 << endl;
    else {
      int ans = 0;
      int l = 0, r = 1000000005;
      while (l <= r) {
        int mid = (r + l) >> 1;
        if (x - (mid * gd - mid * gh) - maxs <= 0) {
          ans = mid + 1;
          r = mid - 1;
        } else
          l = mid + 1;
      }
      cout << ans << endl;
    }
  }
}
