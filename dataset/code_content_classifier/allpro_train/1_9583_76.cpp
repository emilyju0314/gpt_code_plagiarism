#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int P = 1e5 + 7;
const int BASE = 1e9 + 7;
struct Edge {
  int u, v;
  Edge() {}
  Edge(int u, int v) : u(u), v(v) {}
  friend void Read(Edge &A) { scanf("%d%d", &A.u, &A.v); }
} E[N];
int n, m;
int ans[N];
long long H[N];
vector<int> adj[N];
set<int> g[N];
namespace DSU {
int p[N];
void Init() { memset(p, -1, sizeof p); }
int Root(int u) { return p[u] < 0 ? u : p[u] = Root(p[u]); }
void Union(int u, int v) {
  u = Root(u);
  v = Root(v);
  if (u == v) return;
  if (p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}
}  // namespace DSU
void DFS(int u, int par, int d) {
  ans[u] = d;
  for (set<int>::iterator it = g[u].begin(); it != g[u].end(); ++it) {
    int v = *it;
    if (v == par) continue;
    DFS(v, u, d + 1);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    Read(E[i]);
    adj[E[i].u].push_back(E[i].v);
    adj[E[i].v].push_back(E[i].u);
  }
  for (int i = 1; i <= n; ++i) {
    adj[i].push_back(i);
    sort(adj[i].begin(), adj[i].end());
    for (int k = 0; k < adj[i].size(); ++k) {
      int v = adj[i][k];
      H[i] = (H[i] * P + v) % BASE;
    }
  }
  DSU::Init();
  for (int i = 1; i <= m; ++i) {
    int u = E[i].u, v = E[i].v;
    if (H[u] == H[v]) DSU::Union(u, v);
  }
  for (int i = 1; i <= m; ++i) {
    int u = E[i].u, v = E[i].v;
    int Ru = DSU::Root(u), Rv = DSU::Root(v);
    if (Ru != Rv && *g[Ru].lower_bound(Rv) != Rv) {
      g[Ru].insert(Rv);
      g[Rv].insert(Ru);
    }
  }
  int degOnes = 0, s = -1, cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (g[i].size()) cnt++;
    if (g[i].size() > 2) {
      puts("NO");
      return 0;
    } else if (g[i].size() == 1) {
      s = i;
      degOnes++;
    }
  }
  if (cnt == 0) {
    puts("YES");
    for (int i = 1; i <= n; ++i) printf("%d ", 1);
    return 0;
  }
  if (degOnes == 2) {
    DFS(s, -1, 1);
    for (int i = 1; i <= n; ++i) ans[i] = ans[DSU::Root(i)];
    puts("YES");
    for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  } else
    puts("NO");
  return 0;
}
