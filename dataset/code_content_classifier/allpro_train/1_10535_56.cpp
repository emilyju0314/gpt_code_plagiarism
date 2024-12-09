#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n, m;
map<int, vector<int> > g;
void create(int v) {
  for (; v > 1; v /= 2) {
    if (!count(g[v].begin(), g[v].end(), v / 2)) {
      g[v / 2].push_back(v);
      g[v].push_back(v / 2);
    }
  }
}
int subtree(int v) {
  int mydepth = 0, totaldepth = 0;
  while ((1 << mydepth) - 1 < v) mydepth++;
  while ((1 << totaldepth) - 1 < n) totaldepth++;
  int all = (1 << (totaldepth - mydepth + 1)) - 1;
  int myl = v, myr = v;
  for (; mydepth < totaldepth; myl *= 2, myr = myr * 2 + 1, mydepth++)
    ;
  if (myl > n)
    all -= myr - myl + 1;
  else if (myr > n)
    all -= myr - n;
  return all;
}
map<int, int> s;
void dfssize(int v, int p = -1) {
  for (int i : g[v]) {
    if (i == p) continue;
    s[v] -= s[i];
    dfssize(i, v);
  }
}
set<int> vis;
long long dfspaths(int v) {
  vis.insert(v);
  long long paths = s[v];
  for (int i : g[v]) {
    if (vis.count(i)) continue;
    paths += dfspaths(i);
    paths %= mod;
  }
  vis.erase(v);
  return paths;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  g[1];
  vector<pair<int, int> > e(m);
  for (int i = 0; i < m; i++) {
    cin >> e[i].first >> e[i].second;
    create(e[i].first);
    create(e[i].second);
  }
  for (const auto& i : g) s[i.first] = subtree(i.first);
  dfssize(1);
  for (int i = 0; i < m; i++) {
    g[e[i].first].push_back(e[i].second);
    g[e[i].second].push_back(e[i].first);
  }
  long long ans = 0;
  for (const auto& i : g) {
    vis.clear();
    ans += (s[i.first] * dfspaths(i.first)) % mod;
    ans %= mod;
  }
  cout << ans << "\n";
  return 0;
}
