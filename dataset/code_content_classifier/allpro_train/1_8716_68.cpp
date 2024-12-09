#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 10;
long long n, t[M], maks, s, v, ans, mod = 1e9 + 7, sum;
long long sp(long long p, long long w) {
  if (w == 1) return p;
  if (w % 2) return (sp(p, w - 1) * p) % mod;
  long long f = sp(p, w / 2);
  return (f * f) % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int a = 1; a <= n; a++) {
    cin >> t[a];
    maks = max(maks, t[a]);
  }
  s = 1;
  for (long long a = 1; a <= n; a++) s = (s * a) % mod;
  sort(t + 1, t + n + 1);
  for (int a = 1; a <= n; a++) {
    if (t[a] == maks) break;
    if (t[a] != t[a - 1]) v = a - 1;
    sum = s * sp(n - v, mod - 2);
    sum %= mod;
    sum *= t[a];
    ans += sum;
    ans %= mod;
  }
  cout << ans << '\n';
  return 0;
}
