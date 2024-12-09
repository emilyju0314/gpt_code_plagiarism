#include <bits/stdc++.h>
using namespace std;
int n, k;
int f[200005];
int mod;
int saberi(int a, int b) { return (a + b) % mod; }
int oduzmi(int a, int b) { return saberi(a, mod - b); }
int mnozi(int a, int b) { return (a * 1LL * b) % mod; }
int stepenuj(int x, int y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  int xx = stepenuj(x, y / 2);
  if (y % 2 == 1) return mnozi(xx, mnozi(xx, x));
  return mnozi(xx, xx);
}
int inv(int x) { return stepenuj(x, mod - 2); }
int komb(int nn, int kk) { return mnozi(f[nn], inv(mnozi(f[kk], f[nn - kk]))); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cin >> n >> k;
  mod = 998244353;
  if (k > n - 1) {
    cout << 0;
    return 0;
  }
  f[0] = 1;
  for (int i = 1; i <= n; i++) f[i] = mnozi(f[i - 1], i);
  int ans = 0;
  int c = n - k;
  for (int i = c; i >= 0; i--) {
    if (i % 2 == c % 2) {
      ans = saberi(ans, mnozi(stepenuj(i, n), komb(c, i)));
    } else {
      ans = oduzmi(ans, mnozi(stepenuj(i, n), komb(c, i)));
    }
  }
  ans = mnozi(ans, komb(n, c));
  if (k != 0) ans = mnozi(ans, 2);
  cout << ans;
  return 0;
}
