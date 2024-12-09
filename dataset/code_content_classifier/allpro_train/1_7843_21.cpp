#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
int a[200200], b[200200], col[200200];
bool vis[200200], flag;
vector<vector<int> > adj(200200);
void dfs(int u, int c) {
  vis[u] = true;
  for (int i = 0; i < adj[u].size(); i++) {
    int cur = adj[u][i];
    if (col[cur] == col[u]) {
      flag = false;
      return;
    }
    col[cur] = c;
    if (!vis[cur]) dfs(cur, !c);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < 2 * n; i += 2) {
    adj[i].push_back(i + 1);
    adj[i + 1].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    adj[a[i]].push_back(b[i]), adj[b[i]].push_back(a[i]);
  }
  bool ans = true;
  memset(col, -1, sizeof(col));
  for (int i = 1; i <= 2 * n; i++) {
    if (!vis[i]) {
      flag = true;
      col[i] = 0;
      dfs(i, 1);
      ans &= flag;
      if (!ans) break;
    }
  }
  if (!ans) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cout << col[a[i]] + 1 << " " << col[b[i]] + 1 << "\n";
  }
  return 0;
}
