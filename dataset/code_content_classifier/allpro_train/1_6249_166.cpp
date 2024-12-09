#include <bits/stdc++.h>
using namespace std;
const int maxN = 200005;
vector<long long> adj[maxN];
long long a[maxN], b[maxN], c[maxN], vis[maxN];
struct node {
  long long cost, eval_zero, eval_one;
};
node dfs(long long curr_cost, long long u) {
  if (vis[u] == 1) {
    node ffs;
    ffs.eval_zero = 0;
    ffs.eval_one = 0;
    ffs.cost = 0;
    return ffs;
  }
  vis[u] = 1;
  curr_cost = min(curr_cost, a[u]);
  long long temp = 0, e0 = 0, e1 = 0;
  for (auto v : adj[u]) {
    node curr = dfs(curr_cost, v);
    temp += curr.cost;
    e0 += curr.eval_zero;
    e1 += curr.eval_one;
  }
  e0 += (c[u] < b[u]);
  e1 += (c[u] > b[u]);
  node pls;
  pls.eval_zero = e0 - min(e0, e1), pls.eval_one = e1 - min(e0, e1);
  temp += ((curr_cost * min(e0, e1) * 2));
  pls.cost = temp;
  return pls;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(vis, 0, sizeof(vis));
  node res = dfs(a[1], 1);
  if (res.eval_one == 0 && res.eval_zero == 0) {
    cout << res.cost << "\n";
  } else
    cout << -1 << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
