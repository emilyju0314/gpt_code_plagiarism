#include <bits/stdc++.h>
using namespace std;
const long long inff = 0x3f3f3f3f3f3f3f3f;
const int N = 1008, M = 2008;
int head[N], tot, nn, mm, x, y, a[N], b[N];
int ans[1008][1008];
bool vis[1008][1008];
struct node {
  int next, c, to;
} e[M];
struct max_flow {
  int S, T, n;
  int lev[N], q[N], cur[N], f;
  void init(int _s, int _t) {
    tot = 0;
    S = _s, T = _t, n = T + 1;
    for (int i(0); i <= (n); ++i) head[i] = -1;
  }
  void add(int a, int b, int c) {
    e[tot].next = head[a];
    e[tot].to = b;
    e[tot].c = c;
    head[a] = tot++;
  }
  void Add(int a, int b, int c) {
    add(a, b, c);
    add(b, a, 0);
  }
  int bfs() {
    for (int i(0); i <= (n); ++i) lev[i] = 0;
    lev[S] = 1, f = 0, q[f++] = S;
    for (int i(0); i <= (f - 1); ++i) {
      int u = q[i];
      for (int i = head[u]; i != -1; i = e[i].next)
        if (lev[e[i].to] == 0 && e[i].c > 0) {
          int to = e[i].to;
          lev[to] = lev[u] + 1;
          q[f++] = to;
          if (to == T) return 1;
        }
    }
    return 0;
  }
  int dfs(int u, int f) {
    if (u == T) return f;
    int tag = 0, c;
    for (int &i = cur[u]; i != -1; i = e[i].next) {
      int to = e[i].to;
      if (e[i].c > 0 && lev[to] == lev[u] + 1) {
        c = dfs(to, min(f - tag, e[i].c));
        e[i].c -= c;
        e[i ^ 1].c += c;
        if (u <= nn) {
          ans[u][to - nn] += c;
        } else {
          ans[to][u - nn] -= c;
        }
        tag += c;
        if (tag == f) return tag;
      }
    }
    return tag;
  }
  int slove() {
    int ans = 0;
    while (bfs()) {
      for (int i(0); i <= (n); ++i) cur[i] = head[i];
      ans += dfs(S, int(0x3f3f3f3f));
    }
    return ans;
  }
  int mat[N][N];
} flow;
int main() {
  int s, t;
  int sum = 0, sum2 = 0;
  scanf("%d%d", &nn, &mm);
  s = 2 * nn + 1;
  t = 2 * nn + 2;
  int x, y;
  flow.init(s, t);
  for (int i = 1; i <= nn; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
    flow.Add(s, i, a[i]);
    flow.Add(i, i + nn, a[i]);
    vis[i][i] = 1;
  }
  for (int i = 1; i <= nn; i++) {
    scanf("%d", &b[i]);
    sum2 += b[i];
    flow.Add(i + nn, t, b[i]);
  }
  bool is = 1;
  if (sum != sum2) is = 0;
  for (int i = 1; i <= mm; i++) {
    scanf("%d%d", &x, &y);
    if (!vis[x][y]) {
      flow.Add(x, y + nn, a[x]);
      flow.Add(y, x + nn, a[y]);
    }
    vis[x][y] = vis[y][x] = 1;
  }
  if (flow.slove() != sum) {
    is = 0;
  }
  if (!is) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  for (int i = 1; i <= nn; i++) {
    for (int j = 1; j <= nn; j++) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }
}
