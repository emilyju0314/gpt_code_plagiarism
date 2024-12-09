#include <bits/stdc++.h>
using namespace std;
void dfs_visit(vector<int> *v, long long *weight, bool *visited, int n,
               long long *dp) {
  dp[n] = weight[n];
  visited[n] = 1;
  for (auto i : v[n]) {
    if (visited[i] == 0) {
      dfs_visit(v, weight, visited, i, dp);
      if (dp[i] > 0) dp[n] += dp[i];
    }
  }
}
void dfs_visit2(vector<int> *v, long long *weight, bool *visited, int n,
                long long *dp, long long x, long long *k) {
  dp[n] = weight[n];
  visited[n] = 1;
  for (auto i : v[n]) {
    if (visited[i] == 0) {
      dfs_visit2(v, weight, visited, i, dp, x, k);
      if (dp[i] > 0) dp[n] += dp[i];
    }
  }
  if (dp[n] == x) (*k)++, dp[n] = 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, x, y, i, k;
  cin >> n;
  std::vector<int> v[n + 1];
  long long weight[n + 1];
  for (i = 1; i <= n; i++) cin >> weight[i];
  for (i = 0; i < n - 1; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  bool visited[n + 1];
  memset(visited, 0, sizeof(visited));
  long long dp[n + 1];
  dfs_visit(v, weight, visited, 1, dp);
  memset(visited, 0, sizeof(visited));
  x = *max_element(dp + 1, dp + n + 1);
  k = 0;
  dfs_visit2(v, weight, visited, 1, dp, x, &k);
  cout << x * k << " " << k;
  return 0;
}
