#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long n, m, l, r;
  cin >> n >> m >> l >> r;
  long long nm = n * m;
  long long s = r - l + 1;
  if (nm & 1)
    cout << qpow(s, nm) << endl;
  else {
    long long ou = s / 2;
    long long ji = (s + 1) / 2;
    long long ans =
        (qpow(s, nm) + qpow((ji - ou), nm)) % mod * qpow(2, mod - 2) % mod;
    cout << ans << endl;
  }
}
int main() {
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
