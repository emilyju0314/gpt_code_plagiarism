#include <bits/stdc++.h>
using namespace std;
vector<long long int> t[2005];
vector<long long int> c(2005);
vector<long long int> a[2005];
vector<long long int> sz(2005);
long long int n;
bool dfs(long long int v) {
  sz[v] = 1;
  for (long long int i : t[v]) {
    if (!dfs(i)) return 0;
    for (long long int j : a[i]) a[v].push_back(j);
    sz[v] += sz[i];
  }
  if (c[v] > sz[v] - 1) return 0;
  a[v].insert(a[v].begin() + c[v], v);
  return 1;
}
void solve() {
  cin >> n;
  for (long long int i = 1; i <= n; i++) {
    long long int p;
    cin >> p >> c[i];
    t[p].push_back(i);
  }
  long long int root = t[0][0];
  if (!dfs(root)) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  vector<long long int> ans(n + 1);
  for (long long int i = 0; i < a[root].size(); i++) ans[a[root][i]] = i;
  for (long long int i = 1; i <= n; i++) cout << ans[i] + 1 << " ";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int T = 1;
  for (long long int TT = 1; TT <= T; TT++) {
    solve();
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
}
