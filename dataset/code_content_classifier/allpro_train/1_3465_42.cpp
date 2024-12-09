#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - 48;
    ch = getchar();
  }
  return x * f;
}
template <typename T>
inline void Max(T &a, T b) {
  if (a < b) a = b;
}
template <typename T>
inline void Min(T &a, T b) {
  if (a > b) a = b;
}
const int N = 1e5 + 7, Nd = 6e6 + 7;
int n, edc;
int head[N], ndc;
struct edge {
  int lst, to;
  edge() {}
  edge(int lst, int to) : lst(lst), to(to) {}
} e[N << 1];
void Add(int a, int b) {
  e[++edc] = edge(head[a], b), head[a] = edc;
  e[++edc] = edge(head[b], a), head[b] = edc;
}
vector<int> G[Nd];
void lim(int a, int b) { G[a].push_back(b), G[b ^ 1].push_back(a ^ 1); }
int fa[N], in[N], dep[N], top[N], son[N], zson[N], tim;
void dfs1(int u) {
  son[u] = 1;
  for (int(i) = head[(u)], (v) = e[(i)].to; (i);
       (i) = e[(i)].lst, (v) = e[(i)].to)
    if (v ^ fa[u]) {
      dep[v] = dep[u] + 1, fa[v] = u;
      dfs1(v);
      son[u] += son[v];
      if (son[v] > son[zson[u]]) zson[u] = v;
    }
}
void dfs2(int u, int from) {
  top[u] = from, in[u] = ++tim;
  if (zson[u]) dfs2(zson[u], from);
  for (int(i) = head[(u)], (v) = e[(i)].to; (i);
       (i) = e[(i)].lst, (v) = e[(i)].to)
    if (v ^ fa[u] && v ^ zson[u]) dfs2(v, v);
}
vector<int> path[N << 2];
int L[N << 2], R[N << 2];
void modify(int L, int R, int l, int r, int o, int id) {
  if (L <= l && r <= R) {
    path[o].push_back(id);
    return;
  }
  int mid = l + r >> 1;
  if (L <= mid) modify(L, R, l, mid, o << 1, id);
  if (R > mid) modify(L, R, mid + 1, r, o << 1 | 1, id);
}
void build(int l, int r, int o) {
  L[o] = ++ndc, ndc += path[o].size(), R[o] = ndc;
  if (o > 1) {
    lim(L[o] << 1 | 1, R[o >> 1] << 1 | 1);
    if (!path[o].empty()) {
      int x = path[o][0];
      lim(R[o >> 1] << 1, x ^ 1);
    }
  }
  for (int i = 0; i < path[o].size(); ++i) {
    int x = path[o][i];
    lim(L[o] + i << 1 | 1, x ^ 1);
    lim(L[o] + i + 1 << 1 | 1, L[o] + i << 1 | 1);
    if (i ^ 0) lim(L[o] + i - 1 << 1, x ^ 1);
  }
  if (l == r) return;
  int mid = l + r >> 1;
  build(l, mid, o << 1);
  build(mid + 1, r, o << 1 | 1);
}
void ins(int x, int y, int id) {
  for (; top[x] ^ top[y]; y = fa[top[y]]) {
    if (dep[top[x]] > dep[top[y]]) swap(x, y);
    modify(in[top[y]], in[y], 1, n, 1, id);
  }
  if (dep[x] > dep[y]) swap(x, y);
  if (x ^ y) modify(in[x] + 1, in[y], 1, n, 1, id);
}
int low[Nd], pre[Nd], st[Nd], scc[Nd], scc_cnt, tp;
void tarjan(int u) {
  low[u] = pre[u] = ++tim;
  st[++tp] = u;
  for (auto v : G[u]) {
    if (!low[v]) {
      tarjan(v);
      Min(pre[u], pre[v]);
    } else if (!scc[v])
      Min(pre[u], low[v]);
  }
  if (low[u] == pre[u] && ++scc_cnt)
    for (int x = -1; x ^ u;) scc[x = st[tp--]] = scc_cnt;
}
int main() {
  n = gi();
  ndc = n;
  for (int(i) = (1); (i) <= (n - 1); ++(i)) Add(gi(), gi());
  dep[1] = 1, dfs1(1), dfs2(1, 1);
  int m = gi();
  for (int(i) = (1); (i) <= (m); ++(i)) {
    int a = gi(), b = gi(), c = gi(), d = gi();
    ins(a, b, i << 1);
    ins(c, d, i << 1 | 1);
  }
  build(1, n, 1);
  tim = 0;
  for (int i = 1; i <= ndc * 2 + 1; ++i)
    if (!scc[i]) tarjan(i);
  for (int(i) = (1); (i) <= (m); ++(i)) {
    if (scc[i << 1] == scc[i << 1 | 1]) return puts("NO"), 0;
  }
  puts("YES");
  for (int(i) = (1); (i) <= (m); ++(i)) {
    puts(scc[i << 1] < scc[i << 1 | 1] ? "1" : "2");
  }
  return 0;
}
