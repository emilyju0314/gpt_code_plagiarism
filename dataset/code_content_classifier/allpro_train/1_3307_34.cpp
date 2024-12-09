#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long cl(long double a) {
  if (a > (long long)a) {
    return (long long)a + 1;
  } else {
    return (long long)a;
  }
}
long long flr(long double a) {
  if (a < 0.0) {
    return (long long)a - 1;
  }
  return (long long)a;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long n, m;
const long long M = 2e5 + 100;
long long a[M], b[M];
long long pw[M];
void solve() {
  cin >> n;
  cin >> m;
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < m; i++) cin >> b[i];
  long long ans = 1;
  long long j = m - 1;
  long long i = n - 1;
  while (i >= 0 && a[i] != b[j]) {
    if (a[i] < b[j]) {
      cout << 0 << "\n";
      return;
    }
    i--;
  }
  if (i < 0) {
    cout << 0 << "\n";
    return;
  }
  long long s = 0;
  while (s < n && a[s] != b[0]) {
    if (a[s] < b[0]) {
      cout << 0 << "\n";
      return;
    }
    s++;
  }
  if (s == n) {
    cout << 0 << "\n";
    return;
  }
  while (j >= 0) {
    bool flag = false;
    if (a[i] < b[j]) {
      ans = 0;
      break;
    }
    long long idx = -1;
    while (i >= 0 && a[i] >= b[j]) {
      if (a[i] == b[j]) {
        flag = true;
        idx = max(idx, i);
      }
      i--;
    }
    long long cnt = idx - i;
    if (!flag) {
      ans = 0;
      break;
    }
    if (j != 0) ans *= cnt;
    ans %= mod;
    j--;
  }
  if (i > s) {
    cout << 0 << "\n";
    return;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) solve();
}
