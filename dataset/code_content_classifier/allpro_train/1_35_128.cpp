#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int M = 5007;
const int inf = 1e9 + 7;
const long long base = 1e18;
const double pi = acos(-1);
const double ep = 1e-9;
int n;
vector<pair<int, int> > adj[N];
long long pa[N][20], f[N], f2[N];
long long L[N], L2[N], child[N];
long long length[N], depth[N];
void DFS(int u) {
  child[u] = 1;
  for (int j = 0; j < adj[u].size(); j++) {
    int v = adj[u][j].first;
    long long c = adj[u][j].second;
    if (pa[v][0] == 0) {
      pa[v][0] = u;
      length[v] = ((long long)length[u] + c) % inf;
      depth[v] = depth[u] + 1;
      for (int i = 1; i < log(depth[v]) / log(2) + 1; i++)
        pa[v][i] = pa[pa[v][i - 1]][i - 1];
      DFS(v);
      child[u] += child[v];
      long long c2 = (long long)c * c % inf;
      f2[u] = ((long long)f2[u] + f2[v] + ((long long)2 * f[v] * c) % inf +
               (child[v] * c2) % inf) %
              inf;
      f[u] = ((long long)f[u] + f[v] + ((long long)child[v] * c) % inf) % inf;
    }
  }
}
int LCA(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  while (depth[v] > depth[u]) {
    int k = log(depth[v] - depth[u]) / log(2);
    v = pa[v][k];
  }
  if (u == v) return u;
  while (pa[u][0] != pa[v][0] && pa[u][0] > 0) {
    int lo = 0, hi = log(depth[u]) / log(2), g, res = -1;
    do {
      g = (lo + hi) >> 1;
      if (pa[u][g] != pa[v][g]) {
        res = g;
        lo = g + 1;
      } else
        hi = g - 1;
    } while (lo <= hi);
    if (res == -1) break;
    u = pa[u][res];
    v = pa[v][res];
  }
  return pa[u][0];
}
int dist(int u, int v) {
  int t = LCA(u, v);
  return ((long long)length[u] - length[t] + length[v] - length[t]) % inf;
}
void duyet(int u) {
  for (int j = 0; j < adj[u].size(); j++) {
    int v = adj[u][j].first;
    long long c = adj[u][j].second;
    if (pa[v][0] == u) {
      long long c2 = (long long)c * c % inf;
      L[v] = (L[u] - (f[v] + c * child[v]) % inf) % inf;
      long long tmp =
          (L2[u] -
           (f2[v] + ((long long)2 * f[v] * c) % inf + child[v] * c2) % inf) %
          inf;
      L2[v] = (tmp + ((long long)2 * L[v] * c) % inf + (n - child[v]) * c2);
      L[v] = (L[v] + ((long long)n - child[v]) * c + f[v]) % inf;
      L2[v] = (L2[v] + f2[v]) % inf;
      duyet(v);
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    adj[u].push_back(make_pair(v, c));
    adj[v].push_back(make_pair(u, c));
  }
  pa[1][0] = -1;
  DFS(1);
  L[1] = f[1];
  L2[1] = f2[1];
  duyet(1);
  int test;
  cin >> test;
  while (test-- > 0) {
    int u, v;
    scanf("%d%d", &u, &v);
    long long res = 0;
    long long c = dist(u, v);
    long long c2 = (long long)c * c % inf;
    if (LCA(u, v) == v) {
      long long tmp =
          (L2[v] - f2[v] + ((long long)2 * c * (L[v] - f[v])) % inf +
           ((long long)n - child[v]) * c2 % inf) %
          inf;
      res = ((long long)L2[u] - tmp - tmp) % inf;
    } else {
      long long tmp =
          (f2[v] + ((long long)2 * c * f[v]) % inf + (long long)child[v] * c2) %
          inf;
      res = (tmp - (L2[u] - tmp)) % inf;
    }
    res = (res + inf) % inf;
    cout << res << endl;
  }
}
