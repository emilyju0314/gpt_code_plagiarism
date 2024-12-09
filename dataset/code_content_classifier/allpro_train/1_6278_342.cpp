#include <bits/stdc++.h>
using namespace std;
vector<int> S, t;
vector<pair<int, int> > g[1 << 17];
int n, m, a, b, akt, dist[1 << 17], visit[1 << 17], l, mid, p, mx, xd;
void dfs(int v) {
  S.push_back(v);
  visit[v] = xd;
  for (auto u : g[v])
    if (visit[u.first] != xd && u.second <= mid) dfs(u.first);
  t.push_back(S.back());
  S.pop_back();
}
bool check() {
  xd++;
  mx = 1;
  for (int i = 1; i <= n; i++) {
    if (visit[i] != xd) dfs(i);
    dist[i] = -1;
  }
  int v;
  while (!t.empty()) {
    v = t.back();
    t.pop_back();
    for (auto u : g[v])
      if (u.second <= mid)
        dist[u.first] = min(dist[u.first], dist[v] - 1),
        mx = max(mx, -dist[u.first]);
  }
  return mx < n;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    g[a].push_back({b, i});
  }
  l = 1, p = m;
  mid = m;
  while (l < p) {
    if (check())
      l = mid + 1;
    else
      p = mid;
    mid = (l + p) / 2;
  }
  if (check())
    cout << -1;
  else
    cout << mid;
}
