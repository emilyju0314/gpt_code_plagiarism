#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, k, a[N], dp[N], cnt[N], root;
vector<int> adj[N];
void dfs(int u, int par, int x, bool &b) {
  int mx[] = {0, 0}, sum = 0;
  cnt[u] = 1;
  for (int v : adj[u])
    if (v != par) {
      dfs(v, u, x, b);
      if (dp[v] == cnt[v])
        sum += dp[v];
      else {
        mx[0] = max(mx[0], dp[v]);
        sort(mx, mx + 2);
      }
      cnt[u] += cnt[v];
    }
  dp[u] = 0;
  if (a[u] < x) return;
  dp[u] = sum + 1 + mx[1];
  if (dp[u] + mx[0] >= k) b = 1;
}
bool check(int x) {
  bool res = 0;
  dfs(root, -1, x, res);
  return res;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }
  root = min_element(a, a + n) - a;
  int l = 0, r = 1e6 + 1;
  while (r - l > 1) {
    int mid = l + r >> 1;
    check(mid) ? l = mid : r = mid;
  }
  cout << l << endl;
}
