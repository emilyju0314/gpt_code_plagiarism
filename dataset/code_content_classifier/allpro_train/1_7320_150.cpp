#include <bits/stdc++.h>
using namespace std;
long long a, s, d[400003], fact[400003], f, g, h, j, k, l, i, n, m,
    mod = 1000000007;
pair<int, int> p[400002];
long long xar(long long a, long long b) {
  int res = 1;
  while (b) {
    if (b % 2) res = (res * a) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return res;
}
long long cee(int n, int m) {
  return (fact[n] * xar((fact[m] * fact[n - m]) % mod, mod - 2)) % mod;
}
int main() {
  cin >> n >> m;
  fact[0] = 1;
  for (i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &p[2 * i].first);
    p[2 * i].second = i;
    scanf("%d", &p[2 * i + 1].first);
    p[2 * i + 1].first++;
    p[2 * i + 1].second = i;
  }
  sort(p, p + 2 * n);
  k = p[0].first;
  d[p[0].second] = 1;
  l++;
  for (i = 1; i < 2 * n; i++) {
    if (l >= m)
      j = cee(l, m);
    else
      j = 0;
    f = (f + j * (p[i].first - k) % mod) % mod;
    if (d[p[i].second])
      l--;
    else
      l++;
    d[p[i].second] = 1;
    k = p[i].first;
  }
  cout << f;
}
