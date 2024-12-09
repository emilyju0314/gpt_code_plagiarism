#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000;
const int mod = 1e9 + 7;
inline int Add(int x) { return x >= mod ? x - mod : x; }
inline void Add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline int Mul(int x, int y) { return (long long)x * y % mod; }
int Pow(int x, int y) {
  int z = 1;
  for (; y; y >>= 1) {
    if (y & 1) z = Mul(z, x);
    x = Mul(x, x);
  }
  return z;
}
int inv[maxn + 1];
int Choose(int n, int m) {
  int ans = 1;
  for (int i = 1; i <= m; ++i) {
    ans = Mul(ans, n - i + 1);
    ans = Mul(ans, inv[i]);
  }
  return ans;
}
int n, k;
int f[maxn + 1][maxn + 1];
int main(void) {
  f[0][0] = 1;
  for (int i = 1; i <= maxn; ++i) {
    for (int j = 1; j <= i; ++j) {
      f[i][j] = Mul(Add(f[i - 1][j] + f[i - 1][j - 1]), j);
    }
  }
  for (int i = 1; i <= maxn; ++i) {
    inv[i] = Pow(i, mod - 2);
  }
  scanf("%d%d", &n, &k);
  int ans = 0;
  for (int t = 1; t <= min(n, k); ++t) {
    Add(ans, Mul(Choose(n, t), Mul(f[k][t], Pow(2, n - t))));
  }
  printf("%d\n", ans);
  return 0;
}
