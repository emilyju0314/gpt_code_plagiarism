#include <bits/stdc++.h>
const int maxn = 2e5 + 10;
const int maxm = 4e5 + 10;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const double eps = 1e-7;
using namespace std;
long long n, k;
bool check(long long x) {
  long long l = x, r = x + 1LL;
  if (x & 1) r--;
  long long res = 0LL;
  while (l <= n) {
    res += (min(r, n) - l + 1);
    l <<= 1;
    r = (r << 1) + 1LL;
  }
  return res >= k;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  long long l = 1LL, r = n + 1LL, ans = 1LL;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid << 1)) {
      l = mid + 1;
      ans = max(ans, mid << 1);
    } else if (check((mid << 1) - 1)) {
      l = mid + 1;
      ans = max(ans, (mid << 1) - 1);
    } else
      r = mid - 1;
  }
  cout << ans;
  return ~~(0 - 0);
}
