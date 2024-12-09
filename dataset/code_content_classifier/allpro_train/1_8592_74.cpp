#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void rd(T &x) {
  char ch;
  x = 0;
  bool fl = false;
  while (!isdigit(ch = getchar())) (ch == '-') && (fl = true);
  for (x = (ch ^ '0'); isdigit(ch = getchar()); x = x * 10 + (ch ^ '0'))
    ;
  (fl == true) && (x = -x);
}
template <class T>
inline void output(T x) {
  if (x / 10) output(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
inline void ot(T x) {
  if (x < 0) putchar('-'), x = -x;
  output(x);
  putchar(' ');
}
template <class T>
inline void prt(T a[], int st, int nd) {
  for (register int i = st; i <= nd; ++i) ot(a[i]);
  putchar('\n');
}
namespace Miracle {
const int N = 1e6 + 5;
const int K = 5005;
int len[N], n, m, mod;
int dp[K][K];
int f[2][K];
int bac[N];
int jie[K];
int ad(int x, int y) { return (x + y) >= mod ? x + y - mod : x + y; }
int mul(int x, int y) { return (long long)x * y % mod; }
int A(int n, int m) {
  if (n < m) return 0;
  return bac[n - m + 1];
}
int main() {
  rd(n);
  rd(m);
  rd(mod);
  int mx = 0;
  for (register int i = 1; i <= n; ++i) {
    rd(len[i]);
    mx = max(mx, len[i]);
  }
  dp[0][0] = 1;
  jie[0] = 1;
  for (register int i = 1; i <= mx; ++i) {
    jie[i] = mul(jie[i - 1], i);
    for (register int j = 1; j <= i; ++j) {
      dp[i][j] = ad(dp[i - 1][j - 1], mul(dp[i - 1][j], (j - 1)));
    }
  }
  bac[m + 1] = 1;
  for (register int i = m; i >= 1; --i) {
    bac[i] = mul(bac[i + 1], i);
  }
  long long sum = 1;
  int tmp = 0;
  for (register int i = 1; i <= n; ++i) {
    tmp ^= 1;
    long long now = 0;
    for (register int j = 1; j <= len[i]; ++j) {
      f[tmp][j] = ad(mul(sum, mul(dp[len[i]][j], A(m, j))),
                     mod - mul(f[tmp ^ 1][j], mul(dp[len[i]][j], jie[j])));
      now = ad(now, f[tmp][j]);
    }
    swap(sum, now);
    for (register int j = 1; j <= len[i - 1]; ++j) {
      f[tmp ^ 1][j] = 0;
    }
  }
  long long ans = 0;
  for (register int j = 1; j <= len[n]; ++j) {
    ans = ad(ans, f[tmp][j]);
  }
  ot(ans);
  return 0;
}
}  // namespace Miracle
signed main() {
  Miracle::main();
  return 0;
}
