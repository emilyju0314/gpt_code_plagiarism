#include <bits/stdc++.h>
using namespace std;
void dfs(int u, vector<int> &level, vector<int> &child, vector<int> adj[],
         vector<bool> &v) {
  v[u] = true;
  int z = 0;
  for (long long i = 0; i < adj[u].size(); i++) {
    if (!v[adj[u][i]]) {
      level[adj[u][i]] = level[u] + 1;
      dfs(adj[u][i], level, child, adj, v);
      z++;
      z += child[adj[u][i]];
    }
  }
  child[u] = z;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  vector<int> adj[n];
  for (long long i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  vector<int> level(n, 0);
  vector<int> child(n, 0);
  vector<bool> v(n, false);
  dfs(0, level, child, adj, v);
  for (long long i = 0; i < n; i++) {
    child[i] = child[i] - level[i];
  }
  sort(child.begin(), child.end());
  long long sum = 0;
  for (long long i = 0; i < k; i++) sum += child[i];
  cout << -sum << endl;
  return 0;
}
