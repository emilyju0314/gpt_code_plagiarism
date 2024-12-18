#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int MAXE = 10005;
struct Edge {
  int v, n;
  Edge() {}
  Edge(int v, int n) : v(v), n(n) {}
};
struct OP {
  int l, r;
  double p;
  bool operator<(const OP& t) const {
    if (l != t.l) return l < t.l;
    return r > t.r;
  }
};
OP op[MAXN];
Edge E[MAXE];
int H[MAXN], cntE;
int S[MAXN], top;
int val[100005];
double dp[MAXN][MAXN];
int maxv[MAXN];
int n, m;
void clear() {
  top = 0;
  cntE = 0;
  memset(H, -1, sizeof H);
  memset(maxv, 0, sizeof maxv);
}
void addedge(int u, int v, int H[]) {
  E[cntE] = Edge(v, H[u]);
  H[u] = cntE++;
}
void dfs(int u) {
  int o = maxv[u];
  for (int i = H[u]; ~i; i = E[i].n) {
    int v = E[i].v;
    dfs(v);
    maxv[u] = max(maxv[u], maxv[v]);
  }
  for (int j = (0); j <= (m); ++j) {
    double p = op[u].p, q = 1 - op[u].p;
    for (int i = H[u]; ~i; i = E[i].n) {
      int v = E[i].v;
      int k = j + maxv[u] - maxv[v];
      if (k <= m) {
        if (k > 0)
          p *= dp[v][k - 1];
        else
          p = 0;
        q *= dp[v][k];
      }
    }
    if (j + maxv[u] - o == 0) p = 0;
    dp[u][j] = p + q;
  }
}
void solve() {
  clear();
  for (int i = (1); i <= (n); ++i) scanf("%d", &val[i]);
  op[0].l = 1;
  op[0].r = n;
  op[0].p = 0;
  for (int i = (1); i <= (m); ++i)
    scanf("%d%d%lf", &op[i].l, &op[i].r, &op[i].p);
  sort(op + 1, op + m + 1);
  S[top++] = 0;
  int j = 1;
  for (int i = (1); i <= (n); ++i) {
    while (j <= m && op[j].l == i) {
      addedge(S[top - 1], j, H);
      S[top++] = j++;
    }
    maxv[S[top - 1]] = max(maxv[S[top - 1]], val[i]);
    while (top > 0 && op[S[top - 1]].r == i) --top;
  }
  dfs(0);
  double res = maxv[0];
  for (int i = (1); i <= (m); ++i) res += i * (dp[0][i] - dp[0][i - 1]);
  printf("%.10f\n", res);
}
int main() {
  while (~scanf("%d%d", &n, &m)) solve();
  return 0;
}
