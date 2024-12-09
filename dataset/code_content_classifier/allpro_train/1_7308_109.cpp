#include <bits/stdc++.h>
using namespace std;
int inf = 1e9 + 7;
vector<vector<int> > adj;
vector<bool> vis;
vector<int> type;
vector<pair<pair<int, int>, int> > edg;
vector<bool> cvis;
void dfs(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  cvis[type[u]] = 1;
  for (long long i = 0; i < adj[u].size(); i++) dfs(adj[u][i]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k, u, v, w;
  cin >> n >> m >> k;
  vis.resize(n);
  adj.resize(n);
  edg.resize(m);
  type.resize(n);
  cvis.resize(k);
  int d, curr = 0, start[k];
  for (long long i = 0; i < k; i++) {
    start[i] = curr;
    cin >> d;
    for (long long j = 0; j < d; j++) {
      type[curr] = i;
      curr++;
    }
  }
  for (long long i = 0; i < m; i++) {
    cin >> u >> v >> w;
    edg[i] = make_pair(make_pair(u - 1, v - 1), w);
    if (w == 0) {
      adj[u - 1].push_back(v - 1);
      adj[v - 1].push_back(u - 1);
    }
  }
  bool ok = true;
  for (long long i = 0; i < n; i++) {
    if (!vis[i]) {
      for (long long j = 0; j < k; j++) cvis[j] = 0;
      dfs(i);
      for (long long j = 0; j < k; j++) {
        if (cvis[j]) {
          for (int l = start[j]; ok && l < n && type[l] == j; l++) ok = vis[l];
        }
        if (!ok) break;
      }
    }
    if (!ok) break;
  }
  if (!ok)
    cout << "No" << endl;
  else {
    cout << "Yes\n";
    vector<vector<int> > wt(k, vector<int>(k, inf));
    for (long long i = 0; i < k; i++) wt[i][i] = 0;
    for (long long i = 0; i < m; i++) {
      u = edg[i].first.first, v = edg[i].first.second, w = edg[i].second;
      if (type[u] != type[v]) {
        wt[type[u]][type[v]] = min(wt[type[u]][type[v]], w);
        wt[type[v]][type[u]] = min(wt[type[u]][type[v]], w);
      }
    }
    for (long long x = 0; x < k; x++)
      for (long long y = 0; y < k; y++)
        for (long long z = 0; z < k; z++)
          wt[y][z] = min(wt[y][z], wt[y][x] + wt[x][z]);
    for (long long x = 0; x < k; x++) {
      for (long long y = 0; y < k; y++)
        cout << (wt[x][y] == inf ? -1 : wt[x][y]) << " ";
      cout << endl;
    }
  }
}
