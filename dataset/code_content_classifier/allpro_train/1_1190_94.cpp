#include <bits/stdc++.h>
using namespace std;
const int MX = 3e5 + 10;
vector<int> g[MX];
int curColor = 0;
int color[MX];
int sz[MX];
int degree[MX];
void dfs(int v) {
  color[v] = curColor;
  sz[curColor]++;
  for (int to : g[v])
    if (to > 1) {
      degree[v]++;
      if (!color[to]) {
        dfs(to);
      }
    }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<bool> used(MX, 0);
  vector<int> d(MX, 0);
  vector<int> p(MX, 0);
  queue<int> q;
  q.push(1);
  used[1] = 1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int to : g[v]) {
      if (!used[to]) {
        used[to] = 1;
        d[to] = d[v] + 1;
        p[to] = v;
        q.push(to);
      }
    }
  }
  if (d[n] > 0 && d[n] <= 4) {
    cout << d[n] << '\n';
    vector<int> ans;
    int cur = n;
    while (cur > 0) ans.push_back(cur), cur = p[cur];
    reverse(ans.begin(), ans.end());
    for (int i : ans) cout << i << ' ';
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (d[i] == 2) {
      cout << 4 << '\n';
      vector<int> ans = {n, 1};
      int cur = i;
      while (cur > 0) ans.push_back(cur), cur = p[cur];
      reverse(ans.begin(), ans.end());
      for (int i : ans) cout << i << ' ';
      return 0;
    }
  }
  for (int i : g[1]) {
    if (!color[i]) {
      curColor++;
      dfs(i);
    }
  }
  for (int i : g[1]) {
    if (degree[i] < sz[color[i]] - 1) {
      cout << 5 << '\n';
      fill(used.begin(), used.end(), 0);
      fill(d.begin(), d.end(), 0);
      fill(p.begin(), p.end(), 0);
      q.push(i);
      used[i] = 1;
      while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v])
          if (to > 1) {
            if (!used[to]) {
              used[to] = 1;
              d[to] = d[v] + 1;
              p[to] = v;
              q.push(to);
            }
          }
      }
      for (int to = 1; to <= n; ++to) {
        if (d[to] == 2) {
          vector<int> ans = {n, i};
          int cur = to;
          while (cur) ans.push_back(cur), cur = p[cur];
          ans.push_back(1);
          reverse(ans.begin(), ans.end());
          for (int i : ans) cout << i << ' ';
          return 0;
        }
      }
      assert(0);
    }
  }
  cout << -1;
  return 0;
}
