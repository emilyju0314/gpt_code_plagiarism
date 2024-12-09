#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
vector<int> top;
int dp[200001];
void dfs(vector<vector<int> >& v, int i, int parent) {
  int j;
  dp[i] = 1;
  for (j = 0; j < v[i].size(); j++) {
    if (v[i][j] != parent) {
      dfs(v, v[i][j], i);
      dp[i] += dp[v[i][j]];
    }
  }
  top.push_back(i);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, q, x, i;
  cin >> n >> q;
  int a[n + 1];
  vector<vector<int> > v(n + 1);
  for (i = 2; i <= n; i++) {
    cin >> a[i];
  }
  for (i = n; i >= 2; i--) {
    v[a[i]].push_back(i);
    v[i].push_back(a[i]);
  }
  dfs(v, 1, 0);
  reverse(top.begin(), top.end());
  int index[200001];
  for (i = 0; i < top.size(); i++) {
    index[top[i]] = i;
  }
  int u, k;
  while (q--) {
    cin >> u >> k;
    if (k > dp[u]) {
      cout << -1 << "\n";
      continue;
    }
    cout << top[index[u] + k - 1] << "\n";
  }
}
