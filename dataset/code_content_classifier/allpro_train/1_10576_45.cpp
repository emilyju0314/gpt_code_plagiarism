#include <bits/stdc++.h>
using namespace std;
const long long Maxn = 200000 + 10;
const long long Maxm = Maxn << 1;
long long f[Maxn], s[Maxn];
long long head[Maxn], d[Maxn];
long long nxt[Maxn << 1], to[Maxn << 1];
long long n, ans, edgecnt;
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}
inline void add(long long x, long long y) {
  ++edgecnt;
  nxt[edgecnt] = head[x];
  to[edgecnt] = y;
  head[x] = edgecnt;
}
void dfs(long long x, long long fa) {
  d[x] = d[fa] + 1;
  s[x] = 1, f[x] = d[x];
  for (long long i = head[x]; i; i = nxt[i]) {
    long long y = to[i];
    if (y == fa) continue;
    dfs(y, x);
    s[x] += s[y];
    f[x] += f[y];
  }
}
void work(long long x, long long fa) {
  ans = max(ans, f[x]);
  for (long long i = head[x]; i; i = nxt[i]) {
    long long y = to[i];
    if (y == fa) continue;
    f[y] = f[x] + n - (s[y] << 1);
    work(y, x);
  }
}
int main() {
  n = read();
  for (long long i = 1; i < n; ++i) {
    long long x = read(), y = read();
    add(x, y), add(y, x);
  }
  dfs(1, 0);
  work(1, 0);
  printf("%lld\n", ans);
  return 0;
}
