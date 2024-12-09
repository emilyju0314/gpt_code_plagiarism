#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
vector<int> vx, vl, vr;
vector<vector<int>> g;
void dfs(int i, int p = -1) {
  for (auto it = g[i].begin(); it != g[i].end(); it++) {
    if (*it != p) {
      dfs(*it, i);
    }
  }
  vl[i] = vx.size();
  vx.push_back(i);
  for (auto it = g[i].rbegin(); it != g[i].rend(); it++) {
    if (*it != p) {
      vr[*it] = vx.size();
      vx.push_back(*it);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int ii, tt, i, j, k, m, n, c = 0, cc = 0, d, x, y, xl, xr, ans;
  cin >> n;
  vl.resize(n);
  vr.resize(n);
  g.resize(n);
  for (i = 1; i < n; i++) {
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(0);
  vr[0] = vx.size();
  vx.push_back(0);
  for (i = 0; i < n; i++) {
    cout << vl[i] + 1 << ' ' << vr[i] + 1 << '\n';
  }
  return 0;
}
