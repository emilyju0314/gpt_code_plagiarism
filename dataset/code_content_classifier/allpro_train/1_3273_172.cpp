#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#define int long long
vector<int> inv, fact, ifact;
const int vmax = 2e5 + 5;
const int mod = 1e9 + 7;

int nCm(int n, int m) { return fact[n] * ifact[m] % mod * ifact[n - m] % mod; }

signed main() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;

  inv.assign(vmax, 1);
  fact.assign(vmax, 1);
  ifact.assign(vmax, 1);

  for (int i = 2; i <= vmax; i++) {
    inv[i] = (mod - (mod / i)) * inv[mod % i] % mod;
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = ifact[i - 1] * inv[i] % mod;
  }

  int ans = 0;
  for (int i = b ; i < w; i++) {
    ans = (ans + nCm((h - a -1) + i, i ) *
                     nCm((a - 1 )+ w - 1-i , w- 1-i) % mod) %
          mod;
  }
  cout << ans << endl;
 // cout << nCm(10, 5) << endl;
}
