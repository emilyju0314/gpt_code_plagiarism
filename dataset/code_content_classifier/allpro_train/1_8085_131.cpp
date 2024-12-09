#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 7;
const double eps = 1e-9;
long long n, cnt = 0;
string a, b;
long long ans1, ans2, ans3;
void init() {
  ans1 = ans2 = ans3 = 1;
  cnt = 0;
  for (long long i = 0; i < n; ++i) cnt += (a[i] == '?') + (b[i] == '?');
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y % 2 != 0) res = (res * x) % mod;
    x = (x * x) % mod;
    y /= 2;
  }
  return res;
}
void solve() {
  cin >> n >> a >> b;
  init();
  for (long long i = 0; i < n && ans1; ++i) {
    if (a[i] != '?' && b[i] != '?')
      ans1 = (ans1 * (a[i] <= b[i])) % mod;
    else if (a[i] != '?' && b[i] == '?')
      ans1 = (ans1 * ('9' - a[i] + 1)) % mod;
    else if (b[i] != '?' && a[i] == '?')
      ans1 = (ans1 * (b[i] - '0' + 1)) % mod;
    else
      ans1 = (ans1 * 55) % mod;
  }
  for (long long i = 0; i < n && ans2; ++i) {
    if (b[i] != '?' && a[i] != '?')
      ans2 = (ans2 * (b[i] <= a[i])) % mod;
    else if (b[i] != '?' && a[i] == '?')
      ans2 = (ans2 * ('9' - b[i] + 1)) % mod;
    else if (a[i] != '?' && b[i] == '?')
      ans2 = (ans2 * (a[i] - '0' + 1)) % mod;
    else
      ans2 = (ans2 * 55) % mod;
  }
  for (long long i = 0; i < n && ans3; ++i) {
    if (b[i] != '?' && a[i] != '?')
      ans3 = (ans3 * (b[i] == a[i])) % mod;
    else if (a[i] == '?' && b[i] == '?')
      ans3 = (ans3 * 10) % mod;
  }
  cout << ((power(10, cnt) - (ans1 + ans2 - ans3)) % mod + mod) % mod;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test = 1;
  while (test--) solve();
  return 0;
}
