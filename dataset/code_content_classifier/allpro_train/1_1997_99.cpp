#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, h[N], dist[N], MAXH, p1, p2, p3, p4, k, ch[N], mxPath[N];
vector<int> adj[N];
bool vis[N];
set<pair<int, int> > s;
void dfs(int x) {
  vis[x] = true;
  multiset<int> q;
  for (auto v : adj[x])
    if (!vis[v]) {
      h[v] = h[x] + 1;
      dfs(v);
      q.insert(-ch[v] - 1), ch[x] += ch[v] + 1;
    }
  if (adj[x].size() == 1)
    ch[x] = 0;
  else if (adj[x].size() > 2) {
    mxPath[x] = -*q.begin();
    q.erase(q.begin());
    mxPath[x] += -*q.begin();
  }
  if (h[x] > h[MAXH] && adj[x].size() > 2)
    MAXH = x;
  else if (h[x] == h[MAXH] && adj[x].size() > 2 && mxPath[x] > mxPath[MAXH])
    MAXH = x;
}
void bfs(int strt) {
  dist[strt] = 0;
  queue<int> q;
  q.push(strt);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : adj[u])
      if (dist[v] > dist[u] + 1) q.push(v), dist[v] = dist[u] + 1;
  }
}
void find(int x) {
  vis[x] = true;
  if (adj[x].size() == 1) s.insert({-dist[x], x});
  for (auto v : adj[x])
    if (!vis[v] && dist[v] > dist[x]) find(v);
}
void findTWO(int x) {
  vis[x] = true;
  if (adj[x].size() == 1) s.insert({-dist[x], x});
  for (auto v : adj[x])
    if (!vis[v] && h[v] > h[x]) findTWO(v);
}
void readInput() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }
}
void solve() {
  dfs(0);
  memset(dist, 63, sizeof dist);
  bfs(MAXH);
  k = MAXH;
  for (int i = 0; i < n; i++) {
    if (adj[i].size() > 2 && dist[i] > dist[k])
      k = i;
    else if (adj[i].size() > 2 && dist[i] == dist[k] && mxPath[i] > mxPath[k])
      k = i;
  }
  memset(vis, false, sizeof vis);
  find(k);
  p1 = s.begin()->second;
  s.erase(s.begin());
  p2 = s.begin()->second;
  s.clear();
  findTWO(MAXH);
  p4 = s.begin()->second;
  s.erase(s.begin());
  p3 = s.begin()->second;
  cout << p1 + 1 << ' ' << p3 + 1 << '\n' << p2 + 1 << ' ' << p4 + 1 << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  readInput(), solve();
  return 0;
}
