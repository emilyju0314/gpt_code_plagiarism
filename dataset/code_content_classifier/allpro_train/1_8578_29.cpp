#include <bits/stdc++.h>
using namespace std;
using ll = long long;
set<int> vis;
void dfs(vector<vector<int> > &g, int curr, queue<int> &dance) {
  dance.push(curr);
  vis.insert(curr);
  int n0 = g[curr][0];
  int n1 = g[curr][1];
  if (vis.find(n0) == vis.end() && (g[n0][0] == n1 || g[n0][1] == n1)) {
    dfs(g, n0, dance);
  }
  if (vis.find(n1) == vis.end() && (g[n1][0] == n0 || g[n1][1] == n0)) {
    dfs(g, n1, dance);
  }
}
void solve() {
  int n;
  cin >> n;
  vector<vector<int> > g(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[i].push_back(a - 1);
    g[i].push_back(b - 1);
    sort(begin(g[i]), end(g[i]));
  }
  queue<int> dance;
  dfs(g, 0, dance);
  while (!dance.empty()) {
    cout << dance.front() + 1 << " ";
    dance.pop();
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
