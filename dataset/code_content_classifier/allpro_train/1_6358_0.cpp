#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 10;
int n, col, h[N], mn[N], cnt[N], dp[N];
vector<int> adj[N], adj_c[N];
bool e[N][N], mark[N];
bitset<N> B;
void dfs(int u = 0, int l = 0) {
  mn[u] = h[u] = l, mark[u] = true;
  for (auto v : adj[u])
    if (!mark[v])
      dfs(v, l + 1), mn[u] = min(mn[u], mn[v]);
    else if (h[v] != h[u] - 1)
      mn[u] = min(mn[u], h[v]);
}
void dfs_cnt(int u = 0, int c = 0) {
  cnt[c]++, mark[u] = true;
  for (auto v : adj[u])
    if (!mark[v])
      if (mn[v] <= h[u])
        dfs_cnt(v, c);
      else {
        adj_c[c].push_back(col + 1);
        adj_c[col + 1].push_back(c);
        dfs_cnt(v, ++col);
      }
}
int dfs_c(int u, int par = -1) {
  int ans = dp[u] = 0;
  for (auto v : adj_c[u])
    if (v != par) ans += dfs_c(v, u), dp[u] += dp[v];
  ans += (dp[u] += cnt[u]) * cnt[u];
  return ans;
}
int calc(int u) {
  int ans = dfs_c(u);
  B.reset(), B[0] = true;
  for (auto v : adj_c[u]) B |= B << dp[v];
  for (int i = (n - cnt[u]) / 2; ~i; i--)
    if (B[i]) return ans + i * (n - cnt[u] - i);
}
void readInput() {
  int m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}
void solve() {
  int ans = 0;
  for (int i = 0; i <= col; i++) ans = max(ans, calc(i));
  cout << ans << endl;
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  readInput(), dfs(), memset(mark, false, sizeof mark), dfs_cnt(), solve();
  return 0;
}
