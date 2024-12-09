#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int M = 3e5 + 5;
const int LN = 20;
int n, m;
int node = 1, timer = 0, grp = 0;
int u[N], v[N];
int vis[N];
int isBridge[M];
int tin[N], tout[N];
int minAncestor[N];
queue<int> Q[N];
vector<int> adj[N], tree[N];
int nodegrp[N];
void dfs1(int node, int par) {
  vis[node] = 1;
  tin[node] = minAncestor[node] = ++timer;
  for (int i = 0; i < adj[node].size(); i++) {
    int edge = adj[node][i];
    if (par == edge) {
      continue;
    }
    int next = u[edge] ^ v[edge] ^ node;
    if (!vis[next]) {
      dfs1(next, edge);
      minAncestor[node] = min(minAncestor[node], minAncestor[next]);
    } else {
      minAncestor[node] = min(minAncestor[node], tin[next]);
    }
    if (minAncestor[next] > tin[node]) {
      isBridge[edge] = 1;
    }
  }
  tout[node] = timer;
}
void dfs2(int node) {
  int comp = grp;
  Q[comp].push(node);
  vis[node] = 1;
  while (!Q[comp].empty()) {
    int _node = Q[comp].front();
    Q[comp].pop();
    nodegrp[_node] = comp;
    for (int i = 0; i < adj[_node].size(); i++) {
      int edge = adj[_node][i];
      int next = u[edge] ^ v[edge] ^ _node;
      if (vis[next]) continue;
      if (isBridge[edge]) {
        grp++;
        tree[comp].push_back(grp);
        tree[grp].push_back(comp);
        dfs2(next);
      } else {
        Q[comp].push(next);
        vis[next] = 1;
      }
    }
  }
}
int timer1 = 0;
int tin1[N], tout1[N];
int depth[N];
int par[LN][N];
void dfs3(int u, int p) {
  par[0][u] = p;
  vis[u] = 1;
  tin1[u] = ++timer1;
  for (int i = 0; i < tree[u].size(); i++) {
    if (!vis[tree[u][i]]) {
      depth[tree[u][i]] = depth[u] + 1;
      dfs3(tree[u][i], u);
    }
  }
  tout1[u] = ++timer1;
}
int pull(int u, int k) {
  for (int i = 0; i < LN; i++) {
    if ((1LL << i) & k) {
      u = par[i][u];
    }
  }
  return u;
}
int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  int diff = depth[u] - depth[v];
  u = pull(u, diff);
  if (u == v) return u;
  for (int i = LN - 1; i >= 0; i--) {
    if (par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  }
  return par[0][u];
}
bool anc(int u, int v) { return tin1[u] <= tin1[v] && tout1[u] >= tout1[v]; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  clock_t clk;
  clk = clock();
  cin >> n >> m;
  for (int i = (1); i <= (m); ++i) {
    cin >> u[i] >> v[i];
    adj[u[i]].push_back(i);
    adj[v[i]].push_back(i);
  }
  for (int i = (1); i <= (n); ++i)
    if (!vis[i]) dfs1(i, 0);
  memset(vis, 0, sizeof(vis));
  for (int i = (1); i <= (n); ++i)
    if (!vis[i]) {
      ++grp;
      dfs2(i);
    }
  memset(vis, 0, sizeof(vis));
  for (int i = (1); i <= (grp); ++i)
    if (!vis[i]) {
      dfs3(i, 0);
      for (int i = 1; i < LN; i++) {
        for (int j = 1; j <= n; j++) {
          par[i][j] = par[i - 1][par[i - 1][j]];
        }
      }
    }
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    int a, b;
    a = nodegrp[x];
    b = nodegrp[y];
    if (a == b)
      cout << 0 << "\n";
    else {
      if (depth[a] < depth[b]) swap(a, b);
      int l = lca(a, b);
      if (!anc(b, a)) {
        cout << depth[a] - depth[l] + depth[b] - depth[l] << "\n";
      } else {
        cout << depth[a] - depth[b] << "\n";
      }
    }
  }
  clk = clock() - clk;
  cerr << fixed << setprecision(6) << "Time: " << ((double)clk) / CLOCKS_PER_SEC
       << "\n";
  return 0;
}
