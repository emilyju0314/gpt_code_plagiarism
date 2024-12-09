#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007, in2 = 500000004;
inline long long max(long long x, long long y) { return (x > y ? x : y); }
inline long long min(long long x, long long y) { return (x < y ? x : y); }
long long n, id[510], val[510], cnt, s;
inline long long Pow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = 1ll * ans * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return ans;
}
inline long long read() {
  long long x = 0;
  char c = getchar();
  bool y = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') y = 0;
  for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + c - 48;
  if (y) return x;
  return -x;
}
inline void Input() {
  n = read();
  for (register long long i = 1; i <= n; ++i) {
    long long x = read();
    if (~x) {
      if (!id[x]) id[x] = ++cnt;
      ++val[id[x]];
    } else {
      if (!id[i]) id[i] = ++cnt;
      ++val[id[i]];
    }
  }
  return;
}
inline void solve() {
  long long fans = 0;
  for (register long long i = 1; i <= cnt; ++i) {
    fans = (fans - Pow(2, val[i]) + 2) % mod;
    s = (s + val[i]) % (mod - 1);
  }
  fans = (fans + Pow(2, s) - 2) % mod;
  fans = (fans + mod) % mod;
  fans = fans * in2 % mod;
  printf("%lld\n", fans);
  return;
}
signed main() {
  Input();
  solve();
  return 0;
}
