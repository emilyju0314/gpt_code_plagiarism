#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
vector<int> g[N], gt[N];
int n, m;
vector<int> topo;
int vis[N];
int cnt[N];
int alm[N];
int deg[N], in[N];
int fine[N];
void dfs(int u) {
  vis[u] = 1;
  for (int v : g[u])
    if (!vis[v]) dfs(v);
  topo.push_back(u);
}
set<int> s;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0, a, b; i < m; i++) {
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    gt[b].push_back(a);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs(i);
  reverse(topo.begin(), topo.end());
  for (int i = 0; i < n; i++) {
    int u = topo[i];
    for (int v : gt[u]) {
      deg[v]++;
      if (s.count(v)) {
        s.erase(v);
      }
      if (deg[v] == 2) {
        for (int k : g[v]) fine[k]++;
      }
    }
    if ((int)s.size() == 1) {
      alm[u] = 1;
      if ((int)gt[*s.begin()].size() > fine[*s.begin()]) alm[u] = 0;
    } else if (s.empty())
      cnt[u] = 1;
    s.insert(u);
  }
  memset(deg, 0, sizeof deg);
  memset(fine, 0, sizeof fine);
  reverse(topo.begin(), topo.end());
  s.clear();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int u = topo[i];
    for (int v : g[u]) {
      deg[v]++;
      if (s.count(v)) {
        s.erase(v);
      }
      if (deg[v] == 2) {
        for (int k : gt[v]) fine[k]++;
      }
    }
    bool tmp;
    if ((int)s.size() == 1) {
      tmp = 1;
      if ((int)g[*s.begin()].size() > fine[*s.begin()]) tmp = 0;
      if (tmp && cnt[u]) ans++;
    } else if (s.empty() && (cnt[u] + alm[u]))
      ans++;
    s.insert(u);
  }
  printf("%d\n", ans);
}
