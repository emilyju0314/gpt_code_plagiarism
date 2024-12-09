#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 100 + 1, mod = 1000000007;
int n, m, q;
vector<int> adj[N];
int par[18][N];
vector<int> pe[N];
vector<int> k[18][N];
int dis[N];
void input() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    x--;
    if (int(pe[x].size()) < 10) pe[x].push_back(i);
  }
}
vector<int> merge(vector<int> &v, vector<int> v1, vector<int> &v2) {
  for (int i = 0; i < int(v2.size()); i++) v1.push_back(v2[i]);
  sort(v1.begin(), v1.end());
  v.clear();
  for (int i = 0; int(v.size()) < 10 && i < int(v1.size()); i++)
    if (i == 0 || v1[i] != v1[i - 1]) v.push_back(v1[i]);
  return v;
}
void set_par(int p, int v) {
  par[0][v] = p;
  merge(k[0][v], pe[v], k[0][v]);
  for (int i = 1; i < 18; i++) par[i][v] = par[i - 1][par[i - 1][v]];
  for (int i = 1; i < 18; i++)
    merge(k[i][v], k[i - 1][par[i - 1][v]], k[i - 1][v]);
  for (int i = 0; i < int(adj[v].size()); i++) {
    int u = adj[v][i];
    if (u == p) continue;
    dis[u] = dis[v] + 1;
    set_par(v, u);
  }
}
int get_par(int k, int v) {
  for (int i = 0; i < 18; i++)
    if (k & (1 << i)) v = par[i][v];
  return v;
}
int lca(int u, int v) {
  if (dis[u] > dis[v]) swap(u, v);
  v = get_par(dis[v] - dis[u], v);
  if (u == v) return u;
  for (int i = 17; i >= 0; i--) {
    if (par[i][v] != par[i][u]) {
      v = par[i][v];
      u = par[i][u];
    }
  }
  return par[0][u];
}
vector<int> solve(int u, int v) {
  if (dis[u] > dis[v]) swap(u, v);
  vector<int> ans;
  int K = dis[v] - dis[u];
  for (int i = 17; i >= 0; i--) {
    if (K & (1 << i)) {
      merge(ans, ans, k[i][v]);
      v = par[i][v];
    }
  }
  merge(ans, ans, pe[v]);
  return ans;
}
void print(int a, vector<int> v1, vector<int> v2) {
  vector<int> v;
  merge(v, v1, v2);
  printf("%d ", min(a, int(v.size())));
  for (int i = 0; i < min(a, int(v.size())); i++) printf("%d ", v[i]);
  printf("\n");
}
int main() {
  input();
  set_par(0, 0);
  for (int i = 0; i < q; i++) {
    int u, v, a;
    scanf("%d %d %d", &u, &v, &a);
    u--;
    v--;
    int lc = lca(u, v);
    print(a, solve(lc, u), solve(lc, v));
  }
  return 0;
}
