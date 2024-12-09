#include <bits/stdc++.h>
using namespace std;
vector<int> V[200009];
bool vis[200009];
void dfs(int u) {
  for (int i : V[u]) {
    if (vis[i]) continue;
    vis[i] = true;
    cout << u << " " << i << "\n";
    dfs(i);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    V[u].push_back(v);
    V[v].push_back(u);
  }
  int pos = 0;
  for (int i = 1; i <= n; i++) {
    if (V[i].size() >= V[pos].size()) pos = i;
  }
  vis[pos] = true;
  for (int i : V[pos]) {
    cout << pos << " " << i << "\n";
    vis[i] = true;
  }
  for (int i : V[pos]) {
    dfs(i);
  }
}
