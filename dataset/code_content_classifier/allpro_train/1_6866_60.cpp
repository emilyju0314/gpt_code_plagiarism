#include <bits/stdc++.h>
using namespace std;
const int inf = 1e7;
map<int, map<int, int> > rev;
int dfs(int v, vector<vector<int> >& g, vector<int>& used) {
  used[v] = 1;
  int r = 0;
  for (int to : g[v]) {
    if (used[to]) continue;
    if (rev[v][to]) r++;
    r += dfs(to, g, used);
  }
  return r;
}
void gfs(int v, vector<vector<int> >& g, vector<int>& used, vector<int>& dp) {
  used[v] = 1;
  for (int to : g[v]) {
    if (used[to]) continue;
    dp[to] = dp[v];
    if (rev[v][to])
      dp[to]--;
    else
      dp[to]++;
    gfs(to, g, used, dp);
  }
}
int main() {
  int n;
  cin >> n;
  vector<vector<int> > g(n + 1, vector<int>());
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    rev[b][a] = 1;
    g[a].push_back(b), g[b].push_back(a);
  }
  vector<int> used(n + 1, 0), dp(n + 1, 0);
  dp[1] = dfs(1, g, used);
  used.assign(n + 1, 0);
  gfs(1, g, used, dp);
  int mn = n + 4;
  for (int i = 1; i <= n; ++i) {
    mn = min(mn, dp[i]);
  }
  vector<int> ans;
  for (int v = 1; v <= n; ++v) {
    if (dp[v] == mn) ans.push_back(v);
  }
  cout << mn << "\n";
  for (int x : ans) cout << x << " ";
  return 0;
}
