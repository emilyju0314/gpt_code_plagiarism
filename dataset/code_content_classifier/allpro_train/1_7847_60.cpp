#include <bits/stdc++.h>
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f * x;
}
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
void umax(long long& a, long long t) {
  if (t > a) a = t;
}
void umin(long long& a, long long t) {
  if (t < a) a = t;
}
const long long INF = 1ll << 50;
struct edge {
  long long v, w, nxt;
} e[200011 << 1 | 1];
long long cnt = 0, last[200011];
void adde(long long u, long long v, long long w) {
  e[++cnt].v = v, e[cnt].w = w;
  e[cnt].nxt = last[u], last[u] = cnt;
}
bool vis[200011], ring[200011], find = 0;
long long a[200011], s[200011], top = 0;
long long maxv = 0, len[200011], d1[200011], d2[200011], cnt_ring = 0;
void dfs1(long long u, long long fa = 0) {
  vis[u] = 1, s[++top] = u;
  for (long long i = last[u]; i; i = e[i].nxt) {
    long long v = e[i].v;
    if (v == fa) continue;
    if (!vis[v])
      dfs1(v, u);
    else {
      while (s[top] != v) ring[s[top]] = 1, a[++cnt_ring] = s[top], --top;
      ring[v] = 1, a[++cnt_ring] = v;
      find = 1;
    }
    if (find) return;
  }
  --top;
}
long long pred[200011], sufd[200011], prelen[200011], suflen[200011];
void dfs2(long long u, long long rt, long long fa) {
  for (long long i = last[u]; i; i = e[i].nxt) {
    long long v = e[i].v;
    if (ring[v] || v == fa) continue;
    dfs2(v, rt, u);
    umax(maxv, len[u] + e[i].w + len[v]);
    umax(len[u], e[i].w + len[v]);
  }
}
int main() {
  long long n = read();
  for (long long i = 1; i <= n; ++i) {
    long long u = read(), v = read(), w = read();
    adde(u, v, w), adde(v, u, w);
  }
  dfs1(1);
  for (long long x = 1; x <= cnt_ring; ++x) dfs2(a[x], a[x], 0);
  pred[1] = prelen[1] = len[a[1]];
  long long d = 0, tmp = len[a[1]];
  for (long long x = 2; x <= cnt_ring; ++x) {
    for (long long i = last[a[x]]; i; i = e[i].nxt)
      if (e[i].v == a[x - 1]) d += e[i].w;
    if (x > 1) prelen[x] = max(prelen[x - 1], d + len[a[x]]);
    pred[x] = max(pred[x - 1], d + len[a[x]] + tmp);
    umax(tmp, len[a[x]] - d);
  }
  sufd[cnt_ring + 1] = suflen[cnt_ring + 1] = -INF;
  tmp = d = 0;
  a[cnt_ring + 1] = a[1];
  for (long long x = cnt_ring; x; --x) {
    for (long long i = last[a[x]]; i; i = e[i].nxt)
      if (e[i].v == a[x + 1]) d += e[i].w;
    suflen[x] = max(suflen[x + 1], d + len[a[x]]);
    sufd[x] = max(sufd[x + 1], d + len[a[x]] + tmp);
    umax(tmp, len[a[x]] - d);
  }
  long long ans = INF;
  for (long long x = 1; x <= cnt_ring; ++x) {
    umin(ans,
         max(maxv, max(prelen[x] + suflen[x + 1], max(pred[x], sufd[x + 1]))));
  }
  printf("%lld", ans);
  return 0;
}
