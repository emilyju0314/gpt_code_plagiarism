#include <bits/stdc++.h>
using namespace std;
namespace Fread {
const long long MAXN = 1 << 20;
char buf[MAXN], *S, *T;
inline char getchar() {
  if (S == T) {
    T = (S = buf) + fread(buf, 1, MAXN, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}
}  // namespace Fread
inline long long read() {
  long long x(0), neg(1);
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') neg = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch - '0');
    ch = getchar();
  }
  return x * neg;
}
const long long mod = 1e9 + 7;
const long long MAXN = 1e5;
const long long MAXM = 200;
long long sz[MAXN + 5];
long long f[MAXM * 2 + 5];
long long dp[MAXN + 5][MAXM + 5];
long long head[MAXN + 5];
struct node {
  long long to, next;
} edge[MAXN * 2 + 5];
long long cnt;
inline void add(long long u, long long v) {
  edge[++cnt] = (node){v, head[u]};
  head[u] = cnt;
}
long long n, k;
long long ans[MAXN + 5];
inline void dfs(long long u, long long fa) {
  sz[u] = 1;
  dp[u][0] = 2;
  for (long long p = head[u]; p; p = edge[p].next) {
    long long v = edge[p].to;
    if (v == fa) continue;
    dfs(v, u);
    for (long long i = 0; i <= k; ++i) f[i] = 0;
    for (long long i = 0; i <= min(sz[u], k); ++i) {
      for (long long j = 0; j <= min(k - i, sz[v]); ++j) {
        f[i + j] = (f[i + j] + dp[u][i] * dp[v][j] % mod) % mod;
      }
    }
    for (long long i = 0; i <= k; ++i) dp[u][i] = f[i];
    sz[u] += sz[v];
    for (long long i = 0; i <= k; ++i) ans[i] = (ans[i] - dp[v][i] + mod) % mod;
  }
  for (long long i = 0; i <= k; ++i) ans[i] = (ans[i] + dp[u][i]) % mod;
  for (long long i = k; i >= 1; --i) dp[u][i] = (dp[u][i] + dp[u][i - 1]) % mod;
  dp[u][1] = (dp[u][1] - 1 + mod) % mod;
}
long long S[MAXM + 5][MAXM + 5];
signed main() {
  n = read(), k = read();
  S[0][0] = 1;
  for (long long i = 1; i <= k; ++i)
    for (long long j = 1; j <= k; ++j) {
      S[i][j] = (j * S[i - 1][j] + S[i - 1][j - 1]) % mod;
    }
  for (long long i = 1; i < n; ++i) {
    long long u(read()), v(read());
    add(u, v), add(v, u);
  }
  dfs(1, 0);
  long long fac = 1ll, res = 0;
  for (long long i = 1; i <= k; ++i) {
    fac = fac * i % mod;
    res = (res + fac * S[k][i] % mod * ans[i] % mod) % mod;
  }
  printf("%lld\n", res);
  return 0;
}
