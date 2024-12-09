#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
vector<int> adj[N];
int nchild[N];
void dfs(int u, int p) {
  nchild[u] = 1;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v != p) {
      dfs(v, u);
      nchild[u] += nchild[v];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (n % 2 == 1) {
    cout << "-1";
    return 0;
  }
  dfs(1, 0);
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    if (nchild[i] % 2 == 0) ans++;
  }
  cout << ans;
  return 0;
}
