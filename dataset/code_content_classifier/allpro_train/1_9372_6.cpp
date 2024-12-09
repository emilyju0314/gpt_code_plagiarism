#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000 + 10;
const int mod = 1000000007;
int k, w;
int fact[MAXN], dfact[MAXN];
int POWER(int base, int p) {
  int ret = 1, now = base;
  while (p) {
    if (p & 1) ret = (long long)ret * now % mod;
    now = (long long)now * now % mod;
    p >>= 1;
  }
  return ret;
}
int getC(int n, int k) {
  if (k < 0 || k > n) return 0;
  return (long long)fact[n] * dfact[k] % mod * (long long)dfact[n - k] % mod;
}
int go(int len, int MAX) {
  int ret = (long long)getC(k, len - MAX) * fact[len - MAX] % mod;
  if (len <= 2 * MAX)
    ret = (long long)ret * ret % mod * (long long)POWER(k, 2 * MAX - len) % mod;
  else
    ret = (long long)ret * getC(k - (len - 2 * MAX), MAX) % mod *
          (long long)fact[MAX] % mod;
  return ret;
}
int main() {
  cin >> k >> w;
  fact[0] = dfact[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fact[i] = (long long)fact[i - 1] * i % mod;
    dfact[i] = POWER(fact[i], mod - 2);
  }
  int ans = 0;
  for (int i = 1; i <= k; i++)
    ans = ((long long)ans + (long long)go(w + i, w) - go(w + i, w - 1) + mod) %
          mod;
  cout << ans << endl;
  return 0;
}
