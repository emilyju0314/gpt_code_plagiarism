#include <bits/stdc++.h>
using namespace std;
const int N = 185, INF = 1e9;
int n, K, cost[N], dist[N][N], dp[N][N], opt[N], belong[N];
vector<int> T[N];
inline void Min(int &a, int b) {
  if (b < a) a = b;
}
void Floyd() {
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) Min(dist[i][j], dist[i][k] + dist[k][j]);
}
void DP(int cur, int par) {
  for (int i = 1; i <= n; ++i) dp[cur][i] = cost[dist[cur][i]];
  for (int i = 0; i < (int)T[cur].size(); ++i) {
    int son = T[cur][i];
    if (son == par) continue;
    DP(son, cur);
    for (int i = 1; i <= n; ++i)
      dp[cur][i] += min(dp[son][i], dp[son][opt[son]] + K);
  }
  opt[cur] = -1;
  for (int i = 1; i <= n; ++i)
    if (opt[cur] == -1 || dp[cur][i] < dp[cur][opt[cur]]) opt[cur] = i;
}
void assign(int cur, int par, int tar) {
  belong[cur] = tar;
  for (int i = 0; i < (int)T[cur].size(); ++i) {
    int son = T[cur][i];
    if (son == par) continue;
    assign(son, cur, dp[son][opt[son]] + K < dp[son][tar] ? opt[son] : tar);
  }
}
int main() {
  scanf("%d%d", &n, &K);
  for (int i = 1; i <= n; ++i) T[i].clear();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) dist[i][j] = (i != j) * INF;
  cost[0] = 0;
  for (int i = 1; i < n; ++i) scanf("%d", &cost[i]);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    dist[u][v] = dist[v][u] = 1;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  Floyd();
  DP(1, 0);
  assign(1, 0, opt[1]);
  printf("%d\n", dp[1][opt[1]] + K);
  for (int i = 1; i <= n; ++i) printf("%d%c", belong[i], i == n ? '\n' : ' ');
  return 0;
}
