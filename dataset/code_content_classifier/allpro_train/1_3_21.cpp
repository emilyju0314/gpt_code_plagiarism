#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, sgn = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') sgn = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
  return x * sgn;
}
const int N = 2e5 + 10;
int n, k, mod;
long long sum[N], inv[N];
map<int, int> m;
map<int, int>::iterator it, it1;
long long ans;
long long qp(long long x, int t) {
  long long res = 1;
  for (; t; t >>= 1, x = x * x % mod)
    if (t & 1) res = res * x % mod;
  return res;
}
void divide(int l, int r, int k) {
  if (l == r || k <= 1) {
    m[r - l + 1]++;
    return;
  }
  int mid = l + r >> 1;
  divide(l, mid, k - 1);
  divide(mid + 1, r, k - 1);
}
long long calc(int x, int y) {
  long long res = 1ll * x * y % mod;
  for (int i = 1; i <= x; i++)
    res = (res - 2 * sum[i + y] + 2 * sum[i] + mod) % mod;
  return (res + mod) % mod;
}
int main() {
  n = read(), k = read(), mod = read();
  for (int i = 1; i < N; i++) inv[i] = qp(i, mod - 2);
  for (int i = 1; i < N; i++) sum[i] = (sum[i - 1] + inv[i]) % mod;
  divide(1, n, k);
  for (it = m.begin(); it != m.end(); it++) {
    long long x = it->first, s = it->second;
    ans =
        (ans + x * (x - 1) % mod * inv[2] % mod * inv[2] % mod * s % mod) % mod;
    ans = (ans +
           s * (s - 1) % mod * inv[2] % mod * inv[2] % mod * calc(x, x) % mod) %
          mod;
  }
  for (it = m.begin(); it != m.end(); it++)
    for (it1 = m.begin(); it1 != m.end(); it1++) {
      long long x1 = it->first, s1 = it->second, x2 = it1->first,
                s2 = it1->second;
      if (x1 >= x2) continue;
      ans = (ans + s1 * s2 % mod * inv[2] % mod * calc(x1, x2) % mod) % mod;
    }
  printf("%lld\n", ans);
  return 0;
}
