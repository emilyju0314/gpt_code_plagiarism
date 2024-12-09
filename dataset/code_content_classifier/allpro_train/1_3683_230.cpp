#include <bits/stdc++.h>
using namespace std;
const int MAX = 100100, LG = 18;
int n, head[MAX], to[MAX * 2], nxt[MAX * 2], Ecnt, par[MAX][LG], dpth[MAX];
class Node {
 public:
  int A[11], sz;
  Node() {
    memset(A, 100, sizeof A);
    sz = 0;
  }
  void insert(int v) {
    if (v > MAX || binary_search(A, A + 11, v)) return;
    A[10] = v;
    sort(A, A + 11);
    sz++;
  }
  void print(int c) {
    c = min(c, sz);
    printf("%d", c);
    for (int i = 0; i < c; i++) printf(" %d", A[i]);
    puts("");
  }
} sparse[MAX][LG];
Node merge(Node v, Node u) {
  for (int i = 0; i < 10; i++) v.insert(u.A[i]);
  return v;
}
void addedge(int a, int b) {
  nxt[Ecnt] = head[a];
  head[a] = Ecnt;
  to[Ecnt++] = b;
}
void ini() {
  Ecnt = 0;
  memset(head, -1, (n + 1) * sizeof head[0]);
}
void dfs(int v, int p, int d) {
  dpth[v] = d;
  par[v][0] = p;
  for (int j = 1; j < LG; j++) {
    par[v][j] = par[par[v][j - 1]][j - 1];
    sparse[v][j] = merge(sparse[v][j - 1], sparse[par[v][j - 1]][j - 1]);
  }
  for (int i = head[v]; i != -1; i = nxt[i])
    if (to[i] != p) dfs(to[i], v, d + 1);
}
int lca(int v, int u) {
  if (dpth[v] > dpth[u]) swap(v, u);
  int d = dpth[u] - dpth[v];
  for (int i = 0; i < LG; i++)
    if (d & (1 << i)) {
      u = par[u][i];
      d -= 1 << i;
    }
  for (int i = LG - 1; i >= 0; i--)
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  if (u != v) u = par[u][0];
  return u;
}
Node getIDs(int v, int p) {
  Node ret;
  int d = dpth[v] - dpth[p];
  for (int i = 0; i < LG; i++)
    if (d & (1 << i)) {
      ret = merge(ret, sparse[v][i]);
      v = par[v][i];
      d -= 1 << i;
    }
  return merge(ret, sparse[v][d]);
  ;
}
int main() {
  int q, a, b, k, m;
  scanf("%d%d%d", &n, &m, &q);
  ini();
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &a, &b);
    addedge(a, b);
    addedge(b, a);
  }
  for (int i = 1; i <= m; i++) {
    int c;
    scanf("%d", &c);
    sparse[c][0].insert(i);
  }
  dfs(1, 0, 1);
  while (q--) {
    scanf("%d%d%d", &a, &b, &k);
    int l = lca(a, b);
    merge(getIDs(a, l), getIDs(b, l)).print(k);
  }
  return 0;
}
