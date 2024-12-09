#include <bits/stdc++.h>
using namespace std;
template <typename Tp>
inline void read(Tp &x) {
  x = 0;
  long long fh = 1;
  char ch = 1;
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') fh = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= fh;
}
template <typename Tp>
inline void biread(Tp &x) {
  x = 0;
  long long fh = 1;
  char ch = 1;
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') fh = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 2 + ch - '0', ch = getchar();
  x *= fh;
}
const long long maxn = 100000 + 7;
const long long maxm = 200000 + 7;
long long n, a[maxn], rt;
long long Head[maxn], to[maxm], Next[maxm], tot;
void add(long long x, long long y) {
  to[++tot] = y, Next[tot] = Head[x], Head[x] = tot;
}
inline void Init(void) {
  read(n);
  for (long long i = 1; i <= n; i++) read(a[i]);
  for (long long i = 1, x, y; i < n; i++) {
    read(x);
    read(y);
    add(x, y);
    add(y, x);
  }
  read(rt);
}
pair<long long, long long> dfs(long long x, long long f) {
  bool son = false;
  long long sum = 0;
  vector<long long> v;
  for (long long i = Head[x]; i; i = Next[i]) {
    long long y = to[i];
    if (y == f) continue;
    son = true;
    pair<long long, long long> p = dfs(y, x);
    sum += p.second;
    v.push_back(p.first);
  }
  if (!son) return make_pair(0, a[x] - 1);
  long long res = 0, oq = a[x];
  if (x != rt) oq--;
  sort(v.begin(), v.end());
  for (long long i = v.size() - 1; i >= 0 && oq; i--, oq--) {
    res += v[i];
    res += 2;
  }
  res += 2 * min(oq, sum);
  oq -= min(oq, sum);
  return make_pair(res, oq);
}
inline void Work(void) {
  pair<long long, long long> ans = dfs(rt, 0);
  printf("%lld\n", ans.first);
}
signed main(void) {
  Init();
  Work();
  return 0;
}
