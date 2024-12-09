#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 2e6 + 6;
long long bin_pow(long long x, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = res * x % MOD;
    x = x * x % MOD;
    k >>= 1;
  }
  return res;
}
long long n, m, a;
long long b[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> a;
  long long ans = bin_pow(a, n);
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    long long k = b[i] - b[i - 1];
    long long g = bin_pow(a, k);
    long long inv = bin_pow(g, MOD - 2);
    ans = ans * inv % MOD * inv % MOD;
    ans = ans * g % MOD * (g + 1) % MOD * bin_pow(2, MOD - 2) % MOD;
  }
  cout << ans;
}
