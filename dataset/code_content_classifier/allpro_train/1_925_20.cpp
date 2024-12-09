#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c = getchar();
  long long x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
const long long maxn = 2007, maxm = 4007, inf = 0x3f3f3f3f3f3f3f3f;
long long n, m, s, t, maxflow;
long long dep[maxn], cur[maxn], de[maxn];
long long tot = 1, head[maxn];
struct edge {
  long long to, nxt, w;
} e[maxm << 1];
inline void adde(long long u, long long v, long long w) {
  e[++tot] = (edge){v, head[u], w};
  head[u] = tot;
}
inline void add(long long u, long long v, long long w) {
  adde(u, v, w);
  adde(v, u, 0);
}
inline void ins(long long u, long long v, long long l, long long r) {
  add(u, v, r - l), de[u] -= l, de[v] += l;
}
bool bfs(long long s, long long t) {
  queue<long long> q;
  memcpy(cur, head, sizeof cur);
  memset(dep, 63, sizeof dep);
  dep[s] = 0;
  q.push(s);
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    for (long long i = head[u]; i; i = e[i].nxt) {
      long long v = e[i].to;
      if (dep[v] == inf && e[i].w) {
        dep[v] = dep[u] + 1;
        q.push(v);
      }
    }
  }
  return dep[t] < inf;
}
long long dfs(long long u, long long t, long long minn) {
  if (!minn || u == t) return minn;
  long long res = 0;
  for (long long i = cur[u]; i; i = e[i].nxt) {
    long long v = e[i].to;
    cur[u] = i;
    if (dep[v] != dep[u] + 1) continue;
    long long flow = dfs(v, t, min(minn, e[i].w));
    if (!flow) continue;
    res += flow, minn -= flow;
    e[i].w -= flow, e[i ^ 1].w += flow;
    if (!minn) break;
  }
  if (!res) dep[u] = 0;
  return res;
}
inline long long dinic(long long s, long long t) {
  long long maxflow = 0;
  while (bfs(s, t)) maxflow += dfs(s, t, inf);
  return maxflow;
}
long long a[maxn], b[maxn], c[maxn], d[maxn], uu[maxn], vv[maxn],
    lim = 100000000;
map<long long, long long> mp;
long long func(long long v) {
  if (mp.count(v)) return mp[v];
  for (register long long i = (1); i <= (n + 2); ++i) head[i] = de[i] = 0;
  s = n + 1, t = n + 2;
  tot = 1;
  for (register long long i = (1); i <= (m); ++i) {
    long long l = a[i] * v + b[i] * lim, r = c[i] * v + d[i] * lim;
    ins(uu[i], vv[i], l, r);
  }
  long long res = 0;
  for (register long long i = (1); i <= (n); ++i)
    if (de[i] > 0)
      add(s, i, de[i]), res += de[i];
    else
      add(i, t, -de[i]);
  return mp[v] = res - dinic(s, t);
}
signed main() {
  n = read(), m = read();
  for (register long long i = (1); i <= (m); ++i) {
    uu[i] = read(), vv[i] = read();
    a[i] = read(), b[i] = read(), c[i] = read(), d[i] = read();
  }
  func(75000004);
  long long l = 0, r = lim;
  while (r - l >= 5) {
    long long m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
    if (func(m1) < func(m2))
      r = m2;
    else
      l = m1;
  }
  pair<long long, long long> mg = make_pair(inf, inf);
  for (register long long i = (l); i <= (r); ++i)
    mg = min(mg, make_pair(func(i), i));
  if (mg.first) {
    puts("0");
    return 0;
  }
  l = mg.second + 1, r = lim;
  long long resl = mg.second, resr = mg.second;
  while (l <= r) {
    long long mid = l + r >> 1;
    if (!func(mid))
      resr = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  l = 0, r = mg.second - 1;
  while (l <= r) {
    long long mid = l + r >> 1;
    if (!func(mid))
      resl = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%.8lf", 1.0 * (resr - resl) / lim);
  return 0;
}
