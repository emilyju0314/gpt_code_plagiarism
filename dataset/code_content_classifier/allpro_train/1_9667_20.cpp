#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long mod = 1e9 + 7;
const int N = 1e5 + 10;
long long arr[200010];
vector<int> edges[200010];
vector<int> tree[200010];
vector<long long> calc[200010];
long long value[200010];
long long maxval[200010];
void maketree(int par, int root) {
  for (int i = 0; i < edges[root].size(); i++) {
    if (edges[root][i] != par) {
      tree[root].push_back(edges[root][i]);
      maketree(root, edges[root][i]);
    }
  }
}
long long inf = (long long)1e10;
long long dfs(int root) {
  if (tree[root].empty()) {
    value[root] = arr[root];
    maxval[root] = arr[root];
    return value[root];
  }
  value[root] = arr[root];
  for (int i = 0; i < tree[root].size(); i++) {
    value[root] += dfs(tree[root][i]);
  }
  maxval[root] = value[root];
  for (int i = 0; i < tree[root].size(); i++) {
    maxval[root] = max(maxval[root], maxval[tree[root][i]]);
  }
  return value[root];
}
long long ans = (-1) * inf;
void func(int root) {
  if (tree[root].empty()) return;
  long long temp = (-1) * inf;
  if (tree[root].size() > 1) {
    for (int i = 0; i < tree[root].size(); i++) {
      calc[root].push_back(maxval[tree[root][i]]);
    }
    sort(calc[root].begin(), calc[root].end());
    reverse(calc[root].begin(), calc[root].end());
    ans = max(ans, calc[root][0] + calc[root][1]);
  }
  for (int i = 0; i < tree[root].size(); i++) {
    func(tree[root][i]);
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  if (n == 1) {
    cout << "Impossible";
    return 0;
  }
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  maketree(0, 1);
  long long a = dfs(1);
  func(1);
  if (ans == (-1) * inf)
    cout << "Impossible";
  else
    cout << ans;
  return 0;
}
