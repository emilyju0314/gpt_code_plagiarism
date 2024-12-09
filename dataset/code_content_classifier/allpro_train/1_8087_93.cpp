#include <bits/stdc++.h>
using namespace std;
const int N = 210, M = 2100, inf = 1e9;
int n, m, num[N], tmp1[N], tmp2[N], dep[N];
int head[N], ce = 1, vis[N], ans;
struct edge {
  int to, nxt, cap, flow;
} e[M << 1];
void add(int a, int b, int c) {
  e[++ce] = (edge){b, head[a], c, 0}, head[a] = ce;
  e[++ce] = (edge){a, head[b], c, 0}, head[b] = ce;
}
int Head[N], Ce = 1;
struct Edge {
  int to, nxt, w, vis;
} E[N << 1];
void add_edge(int a, int b, int c) {
  E[++Ce] = (Edge){b, Head[a], c, 0}, Head[a] = Ce;
  E[++Ce] = (Edge){a, Head[b], c, 0}, Head[b] = Ce;
}
bool bfs(int S, int T) {
  for (int i = 1; i <= n; ++i) dep[i] = 0;
  dep[S] = 1;
  queue<int> q;
  q.push(S);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (!dep[v] && e[i].flow < e[i].cap) {
        dep[v] = dep[u] + 1;
        if (v == T) return 1;
        q.push(v);
      }
    }
  }
  return 0;
}
int dfs(int u, int T, int lim) {
  if (u == T) return lim;
  int tag = 0;
  for (int i = head[u]; i; i = e[i].nxt)
    if (e[i].flow < e[i].cap && dep[e[i].to] == dep[u] + 1) {
      int d = dfs(e[i].to, T, min(lim - tag, e[i].cap - e[i].flow));
      tag += d, e[i].flow += d, e[i ^ 1].flow -= d;
      if (tag == lim) return tag;
    }
  if (!tag) dep[u] = -1;
  return tag;
}
int Dinic(int S, int T) {
  int maxflow = 0;
  for (int i = 1; i <= ce; ++i) e[i].flow = 0;
  while (bfs(S, T)) maxflow += dfs(S, T, inf);
  return maxflow;
}
void dfs(int u) {
  vis[u] = 1;
  for (int i = head[u]; i; i = e[i].nxt)
    if (!vis[e[i].to] && e[i].cap > e[i].flow) dfs(e[i].to);
}
void build(int l, int r) {
  if (l == r) return;
  int x = num[l], y = num[l + 1], c1 = 0, c2 = 0, cut = Dinic(x, y);
  add_edge(x, y, cut);
  ans += cut;
  for (int i = 1; i <= n; ++i) vis[num[i]] = 0;
  dfs(x);
  for (int i = l; i <= r; ++i)
    if (vis[num[i]])
      tmp1[++c1] = num[i];
    else
      tmp2[++c2] = num[i];
  for (int i = 1; i <= c1; ++i) num[i + l - 1] = tmp1[i];
  for (int i = c1 + 1; i <= c1 + c2; ++i) num[i + l - 1] = tmp2[i - c1];
  build(l, l + c1 - 1);
  build(l + c1, r);
}
int id, st[N], top;
bool find(int u, int lst) {
  bool ret = 0;
  for (int i = Head[u]; i; i = E[i].nxt)
    if (!E[i].vis && E[i].to != lst) {
      ret = 1;
      bool tmp = find(E[i].to, u);
      if (E[i].w < E[id].w || !id) id = i;
    }
  return ret;
}
void get(int u) {
  id = 0;
  if (!find(u, 0)) {
    st[++top] = u;
    return;
  }
  E[id].vis = E[id ^ 1].vis = 1;
  int tp = id;
  get(E[tp].to);
  get(E[tp ^ 1].to);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    add(u, v, w);
  }
  for (int i = 1; i <= n; ++i) num[i] = i;
  build(1, n);
  get(1);
  printf("%d\n", ans);
  for (int i = 1; i <= top; ++i) printf("%d ", st[i]);
  return 0;
}
