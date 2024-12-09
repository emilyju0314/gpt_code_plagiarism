#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline void read(T &x) {
  char ch = getchar();
  int f = 1;
  x = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args) {
  read(x), read(args...);
}
int n, p, k, a[300005];
long long ans = 0;
map<int, int> cnt;
int main() {
  read(n, p, k);
  for (register int i = 1; i <= n; ++i) {
    read(a[i]);
    long long b =
        (1ll * a[i] * a[i] % p * a[i] % p * a[i] % p - 1ll * k * a[i] % p + p) %
        p;
    ans += cnt[b];
    cnt[b]++;
  }
  cout << ans;
  return 0;
}
