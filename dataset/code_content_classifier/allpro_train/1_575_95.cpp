#include <bits/stdc++.h>
inline int readInt() {
  int ans = 0, c, f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') f *= -1;
  do ans = ans * 10 + c - '0';
  while (isdigit(c = getchar()));
  return ans * f;
}
const int N = 55;
struct T {
  long long a;
  int b;
  bool operator<(const T &t) const {
    if (a == t.a) return b < t.b;
    return a > t.a;
  }
} G[N];
int n;
long long V[N], S[N], f[N][N];
inline void chk(long long &a, long long b) { a = std::min(a, b); }
int main() {
  n = readInt();
  for (int i = 0; i < n; ++i) G[i].a = readInt() * 1000LL;
  for (int i = 0; i < n; ++i) G[i].b = readInt();
  std::sort(G, G + n);
  long long l = 1, r = 1000000000000LL;
  while (l < r) {
    long long mid = (l + r) / 2;
    for (int i = n - 1; i >= 0; --i)
      S[i] = S[i + 1] + (V[i] = G[i].a - G[i].b * mid);
    for (int i = 1; i <= n; ++i) f[0][i] = 1000000000000000000LL;
    f[0][0] = 0;
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n && G[j].a == G[i].a) ++j;
      for (int k = 0; k <= n; ++k) f[j][k] = 1000000000000000000LL;
      for (int k = 0; k <= n; ++k)
        for (int t = i; t <= j && t - i <= k; ++t)
          chk(f[j][k - (t - i) + (j - t)], f[i][k] + S[t] - S[j]);
      i = j;
    }
    bool ok = false;
    for (int i = 0; i <= n; ++i)
      if (f[n][i] <= 0) ok = true;
    if (ok)
      r = mid;
    else
      l = mid + 1;
  }
  printf("%I64d\n", l);
  return 0;
}
