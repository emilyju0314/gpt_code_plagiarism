#include <bits/stdc++.h>
using namespace std;
vector<int> G[100010];
int dp[100010];
int ff = 0;
void dfs(int u, int fa) {
  int num = 0;
  int sz = G[u].size();
  for (int i = 0; i < sz; i++) {
    int v = G[u][i];
    if (v == fa) continue;
    dfs(v, u);
    dp[u] += dp[v];
    num++;
  }
  if (!dp[u]) dp[u] = 1;
  if (dp[u] == 2 && num == 1) dp[u]++;
}
void dfs2(int u, int fa, int num) {
  int sz = G[u].size();
  int n = 0;
  if (num > 2) n++;
  for (int i = 0; i < sz; i++) {
    int v = G[u][i];
    if (v == fa) continue;
    int tmp = 1;
    tmp = max(num + dp[u] - dp[v], tmp);
    if (tmp == 2 && num == 2) tmp = 3;
    dfs2(v, u, tmp);
    if (dp[v] > 2) n++;
  }
  if (n > 2) ff = 1;
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(0, -1);
  dfs2(0, -1, 0);
  if (ff)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}
