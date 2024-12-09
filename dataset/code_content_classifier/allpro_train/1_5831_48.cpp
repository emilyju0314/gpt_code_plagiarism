#include <bits/stdc++.h>
using namespace std;
inline void cmax(int &a, int b) { a = max(a, b); }
inline void cmin(int &a, int b) { a = min(a, b); }
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct edge {
  int to, cap, rev;
  edge(int x, int y, int z) { to = x, cap = y, rev = z; }
};
struct Max_flow {
  int Siz;
  int src, snk;
  vector<vector<edge> > G;
  vector<int> dist, seen;
  Max_flow() {
    Siz = 0;
    src = -1;
    snk = -1;
    G.clear();
    dist.clear();
    seen.clear();
  }
  void Set(int x, int y) { src = x, snk = y; }
  void resize(int s) {
    Siz = s;
    G.resize(s + 1);
    dist.resize(s + 1);
    seen.resize(s + 1);
  }
  void add_edge(int u, int v, int c) {
    edge t1(v, c, G[v].size()), t2(u, 0, G[u].size());
    G[u].push_back(t1);
    G[v].push_back(t2);
  }
  void bfs(int s) {
    for (int i = 0; i < dist.size(); i++) dist[i] = -1;
    queue<int> Q;
    dist[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      for (int i = 0; i < G[x].size(); i++) {
        int v = G[x][i].to;
        if (G[x][i].cap && dist[v] == -1) {
          dist[v] = dist[x] + 1;
          Q.push(v);
        }
      }
    }
  }
  int dfs(int x, int dest, int flow) {
    if (x == dest) return flow;
    for (int &i = seen[x]; i < G[x].size(); i++) {
      edge &e = G[x][i];
      if (e.cap && dist[e.to] == dist[x] + 1) {
        int ff = dfs(e.to, dest, min(flow, e.cap));
        if (ff) {
          e.cap -= ff;
          G[e.to][e.rev].cap += ff;
          return ff;
        }
      }
    }
    return 0;
  }
  int dinic(int u, int v) {
    int ans = 0;
    while (1) {
      for (int i = 0; i < seen.size(); i++) seen[i] = 0;
      bfs(u);
      if (dist[v] == -1) break;
      int f;
      while (f = dfs(u, v, 2147483647)) {
        ans += f;
      }
    }
    return ans;
  }
  int Maxflow() { return dinic(src, snk); }
};
const long long mod = 95542721;
const int Maxn = 100005;
long long a[Maxn];
void cube(long long &x) {
  long long y = x * x % mod * x % mod;
  x = y;
}
struct node {
  long long val[55];
  int tag;
  node() {
    tag = 0;
    for (int i = 0; i < 55; i++) {
      val[i] = 0LL;
    }
  }
} tree[Maxn * 4];
inline void Merge(node &a, node &b, node &push) {
  for (int i = 0; i < 48; i++) {
    push.val[i] = a.val[i] + b.val[i];
    if (push.val[i] >= mod) push.val[i] -= mod;
  }
}
inline void build(int push, int l, int r) {
  if (l == r) {
    long long tmp = a[l];
    for (int i = 0; i < 48; i++) {
      tree[push].val[i] = tmp;
      cube(tmp);
    }
    return;
  }
  int mid = l + r >> 1;
  build(push * 2, l, mid);
  build(push * 2 + 1, mid + 1, r);
  Merge(tree[push * 2], tree[push * 2 + 1], tree[push]);
}
long long tmp[233], st;
inline void rshift(node &push, int val = -1) {
  push.tag %= 48;
  if (val == -1) val = push.tag;
  val %= 48;
  st = 0;
  for (int i = val; i < 48; i++) {
    tmp[st++] = push.val[i];
  }
  for (int i = 0; i < val; i++) {
    tmp[st++] = push.val[i];
  }
  for (int i = 0; i < 48; i++) {
    push.val[i] = tmp[i];
  }
}
inline void Push(int push) {
  if (tree[push].tag) {
    rshift(tree[push * 2], tree[push].tag);
    rshift(tree[push * 2 + 1], tree[push].tag);
    tree[push * 2].tag += tree[push].tag;
    tree[push * 2 + 1].tag += tree[push].tag;
    tree[push].tag = 0;
  }
}
void modify(int push, int l, int r, int lo, int hi) {
  if (lo <= l && r <= hi) {
    tree[push].tag++;
    rshift(tree[push], 1);
    return;
  }
  Push(push);
  int mid = l + r >> 1;
  if (lo <= mid) {
    modify(push * 2, l, mid, lo, min(hi, mid));
  }
  if (hi > mid) {
    modify(push * 2 + 1, mid + 1, r, max(lo, mid + 1), hi);
  }
  Merge(tree[push * 2], tree[push * 2 + 1], tree[push]);
}
long long query(int push, int l, int r, int lo, int hi) {
  if (lo <= l && r <= hi) {
    return tree[push].val[0];
  }
  Push(push);
  int mid = l + r >> 1;
  long long ans = 0;
  if (lo <= mid) {
    ans += query(push * 2, l, mid, lo, min(hi, mid));
  }
  if (hi > mid) {
    ans += query(push * 2 + 1, mid + 1, r, max(lo, mid + 1), hi);
  }
  Merge(tree[push * 2], tree[push * 2 + 1], tree[push]);
  if (ans >= mod) ans -= mod;
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    a[i] %= mod;
  }
  build(1, 1, n);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int tp;
    scanf("%d", &tp);
    if (tp == 2) {
      int l, r;
      l = read();
      r = read();
      modify(1, 1, n, l, r);
    } else {
      int l, r;
      l = read();
      r = read();
      printf("%I64d\n", query(1, 1, n, l, r));
    }
  }
  return 0;
}
