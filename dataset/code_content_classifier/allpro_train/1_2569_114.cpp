#include <bits/stdc++.h>
using namespace std;
vector<int> g[100003];
bool visited[100003];
long c[100000], mina;
long dfs(int u) {
  visited[u] = true;
  for (int i = 0; i < g[u].size(); i++) {
    if (!visited[g[u][i]]) {
      mina = min(mina, c[g[u][i]]);
      dfs(g[u][i]);
    }
  }
  return mina;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    visited[i] = false;
  }
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      mina = c[i];
      ans += dfs(i);
    }
  }
  cout << ans << endl;
  return 0;
}
