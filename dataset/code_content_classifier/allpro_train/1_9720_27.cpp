#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>>& g, vector<pair<int, int>>& sol, vector<int>& p,
           int s, int t) {
  p[s] = 1;
  int n, i, u, c, flag;
  c = 1;
  flag = 1;
  pair<int, int> sq;
  n = g[s].size();
  sq.first = s;
  sq.second = t;
  sol.push_back(sq);
  for (i = 0; i < n; i++) {
    u = g[s][i];
    if (!p[u]) {
      t++;
      if (flag && t > n) {
        t -= n + 1;
        sq.second = t;
        sol.push_back(sq);
        c++;
        flag = 0;
        t++;
      }
      solve(g, sol, p, u, t);
      sq.second = t;
      sol.push_back(sq);
      c++;
    }
  }
  if (c == n) {
    t -= n;
    sq.second = t;
    sol.push_back(sq);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  int n, i, k, u, v;
  cin >> n;
  vector<vector<int>> g(n + 1);
  vector<int> p(n + 1);
  vector<pair<int, int>> sol;
  for (i = 0; i < n - 1; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  solve(g, sol, p, 1, 0);
  k = sol.size();
  cout << k << '\n';
  for (i = 0; i < k; i++) {
    cout << sol[i].first << ' ' << sol[i].second << '\n';
  }
  return 0;
}
