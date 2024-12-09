#include <bits/stdc++.h>
using namespace std;
int n, m, k, d[200002], viz[200002], comp, p[200002];
vector<int> G[200002];
vector<vector<pair<int, int> > > edge;
vector<pair<int, int> > ans, meh;
void dfs(int x) {
  viz[x] = 1;
  for (auto it : G[x]) {
    if (viz[it]) continue;
    if (it == 1)
      edge[comp].push_back({1, x});
    else {
      dfs(it);
      meh.push_back({it, x});
    }
  }
}
int find(int x) {
  if (p[x] != x)
    return p[x] = find(p[x]);
  else
    return x;
}
void Union(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) p[x] = y;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    d[x]++;
    d[y]++;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  if (d[1] < k) {
    cout << "NO";
    return 0;
  }
  for (int i = 2; i <= n; i++) {
    if (!viz[i]) {
      edge.push_back({});
      dfs(i);
      comp++;
    }
  }
  if (k < comp) {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i < comp; i++) {
    if (edge[i].size() == 0) {
      cout << "NO";
      return 0;
    }
    ans.push_back(edge[i][0]);
    Union(edge[i][0].first, edge[i][0].second);
  }
  k -= comp;
  for (int i = 0; i < comp; i++) {
    if (edge[i].size() == 0) {
      cout << "NO";
      return 0;
    }
    for (int j = 1; j < edge[i].size(); j++) {
      if (k) {
        ans.push_back(edge[i][j]);
        Union(edge[i][j].first, edge[i][j].second);
        k--;
      }
    }
  }
  for (auto it : meh) {
    if (find(it.first) != find(it.second)) {
      Union(it.first, it.second);
      ans.push_back(it);
    }
  }
  cout << "YES\n";
  for (auto it : ans) cout << it.first << " " << it.second << "\n";
  return 0;
}
