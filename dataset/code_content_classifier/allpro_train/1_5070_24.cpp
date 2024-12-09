#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int n, m;
long long S;
struct edge_1 {
  int x, y, id;
  long long w, c;
  bool operator<(const edge_1 &A) const { return w < A.w; }
} edge1[maxn];
int cnt, head[maxn];
struct edge {
  int to, next, id;
  long long w;
} edge[maxn << 1];
void init() {
  cnt = 0;
  for (int i = 0; i <= n; i++) head[i] = -1;
}
void add_edge(int u, int v, long long w, int id) {
  edge[cnt].to = v;
  edge[cnt].id = id;
  edge[cnt].w = w;
  edge[cnt].next = head[u];
  head[u] = cnt++;
}
void input() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%I64d", &edge1[i].w);
  for (int i = 1; i <= m; i++) scanf("%I64d", &edge1[i].c);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    edge1[i].id = i;
    edge1[i].x = u;
    edge1[i].y = v;
  }
  scanf("%I64d", &S);
}
bool mk[maxn];
int pre[maxn], mat[maxn];
int findx(int x) { return x == pre[x] ? x : pre[x] = findx(pre[x]); }
long long kruskal() {
  int have = 0;
  long long sum = 0;
  sort(edge1 + 1, edge1 + m + 1);
  for (int i = 1; i <= n; i++) pre[i] = i;
  for (int i = 1; i <= m; i++) {
    mk[i] = 0;
    mat[i] = edge1[i].id;
  }
  init();
  for (int i = 1; i <= m; i++) {
    int x = findx(edge1[i].x), y = findx(edge1[i].y);
    if (x != y) {
      pre[x] = y;
      sum += edge1[i].w;
      mk[i] = 1;
      have++;
      add_edge(edge1[i].x, edge1[i].y, edge1[i].w, i);
      add_edge(edge1[i].y, edge1[i].x, edge1[i].w, i);
    }
    if (have >= n - 1) break;
  }
  return sum;
}
int fa[maxn], anc[maxn][20], L[maxn];
long long cost[maxn];
struct node {
  long long w;
  int id;
  node(long long a = 0, int b = 0) : w(a), id(b) {}
} maxcost[maxn][20];
void dfs(int u, int top, int dep) {
  fa[u] = top;
  L[u] = dep;
  for (int k = head[u]; k != -1; k = edge[k].next) {
    int v = edge[k].to;
    if (v == top) continue;
    cost[v] = edge[k].w;
    maxcost[v][0].id = edge[k].id;
    dfs(v, u, dep + 1);
  }
}
void update(node &ret, node x, node y) {
  if (x.w > y.w)
    ret = x;
  else
    ret = y;
}
void pre_process() {
  for (int i = 1; i <= n; i++) {
    anc[i][0] = fa[i];
    maxcost[i][0].w = cost[i];
    for (int j = 1; (1 << j) < n; j++) anc[i][j] = -1;
  }
  for (int j = 1; (1 << j) < n; j++)
    for (int i = 1; i <= n; i++)
      if (anc[i][j - 1] != -1) {
        int a = anc[i][j - 1];
        anc[i][j] = anc[a][j - 1];
        update(maxcost[i][j], maxcost[i][j - 1], maxcost[a][j - 1]);
      }
}
node query(int p, int q) {
  int log;
  if (L[p] < L[q]) swap(p, q);
  for (log = 1; (1 << log) <= L[p]; log++)
    ;
  log--;
  node ans = node(-1, 0);
  for (int i = log; i >= 0; i--)
    if (L[p] - (1 << i) >= L[q]) {
      update(ans, ans, maxcost[p][i]);
      p = anc[p][i];
    }
  if (p == q) return ans;
  for (int i = log; i >= 0; i--)
    if (anc[p][i] != -1 && anc[p][i] != anc[q][i]) {
      update(ans, ans, maxcost[p][i]);
      p = anc[p][i];
      update(ans, ans, maxcost[q][i]);
      q = anc[q][i];
    }
  update(ans, ans, maxcost[p][0]);
  update(ans, ans, maxcost[q][0]);
  return ans;
}
void solve() {
  long long total = kruskal();
  cost[1] = -1;
  maxcost[1][0].id = 0;
  dfs(1, 1, 0);
  pre_process();
  long long ans = 10000000000000000LL;
  int del = -1, add = -1;
  for (int i = 1; i <= m; i++) {
    long long cur = total;
    if (mk[i]) {
      cur -= S / edge1[i].c;
      if (ans > cur) {
        ans = cur;
        del = -1;
        add = i;
      }
    } else {
      int x = edge1[i].x, y = edge1[i].y;
      node tmp = query(x, y);
      cur = cur - tmp.w + edge1[i].w;
      cur -= S / edge1[i].c;
      if (ans > cur) {
        ans = cur;
        del = tmp.id;
        add = i;
      }
    }
  }
  printf("%I64d\n", ans);
  printf("%d %I64d\n", mat[add], edge1[add].w - S / edge1[add].c);
  for (int i = 1; i <= m; i++)
    if (mk[i]) {
      if (del == i || add == i) continue;
      printf("%d %I64d\n", mat[i], edge1[i].w);
    }
}
int main() {
  input();
  solve();
  return 0;
}
