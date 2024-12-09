#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
struct edge {
  int to, cost;
};
vector<edge> G[N];
int n, k;
long long dp[N][2];
vector<long long> vec;
void dfs(int v, int p) {
  for (auto &e : G[v]) {
    int u = e.to;
    if (u == p) continue;
    dfs(u, v);
  }
  long long sum = 0;
  vec.clear();
  for (auto &e : G[v]) {
    int u = e.to, w = e.cost;
    if (u == p) continue;
    sum += dp[u][0];
    if (dp[u][1] + w > dp[u][0]) vec.push_back(dp[u][1] + w - dp[u][0]);
  }
  sort(vec.begin(), vec.end(), greater<long long>());
  dp[v][0] = dp[v][1] = sum;
  int sz = vec.size();
  for (int i = 0; i < min(k, sz); i++) dp[v][0] += vec[i];
  for (int i = 0; i < min(k - 1, sz); i++) dp[v][1] += vec[i];
}
void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    G[u].push_back((edge){v, w});
    G[v].push_back((edge){u, w});
  }
  dfs(1, 0);
  printf("%lld\n", dp[1][0]);
  for (int i = 1; i <= n; i++) {
    G[i].clear();
    dp[i][0] = dp[i][1] = 0;
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
}
