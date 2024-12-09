#include <bits/stdc++.h>
using namespace std;
const int N = 13;
int n, m, q, a, b, c, u, v;
int con[N], subset[N];
vector<int> lca[N];
vector<int> g[(1 << N)];
long long dp[N][(1 << N)];
bool cant[N][(1 << N)];
long long solve(int node, int mask) {
  if (dp[node][mask] != -1) return dp[node][mask];
  dp[node][mask] = 0;
  for (int i = 0; i < (int)g[mask].size(); i++) {
    if (cant[node][g[mask][i]]) continue;
    if ((mask ^ g[mask][i]) > g[mask][i]) continue;
    for (int j = 0; j < n; j++) {
      if (((1 << j) & g[mask][i]) != (1 << j)) continue;
      if (((g[mask][i] | (1 << node)) & con[j]) != con[j]) continue;
      if ((g[mask][i] & subset[j]) != subset[j]) continue;
      dp[node][mask] +=
          solve(node, (mask ^ g[mask][i])) * solve(j, (g[mask][i] ^ (1 << j)));
    }
  }
  if (mask == 0) dp[node][mask] = 1;
  return dp[node][mask];
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  subset[0] = (1 << n) - 2;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    u--;
    v--;
    con[u] |= (1 << v);
    con[v] |= (1 << u);
  }
  for (int i = 0; i < q; i++) {
    scanf("%d%d%d", &a, &b, &c);
    a--, b--, c--;
    if (a != c) subset[c] |= (1 << a);
    if (b != c) subset[c] |= (1 << b);
    if (a != c && b != c) {
      a = (1 << a);
      b = (1 << b);
      a |= b;
      lca[c].push_back(a);
    }
  }
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int j = 1; j < (1 << n); j++) {
      if ((mask & j) == j) {
        g[mask].push_back(j);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << n); j++) {
      for (int k = 0; k < (int)lca[i].size(); k++) {
        if ((j & lca[i][k]) == lca[i][k]) {
          cant[i][j] = true;
          break;
        }
      }
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0, (1 << n) - 2) << endl;
  return 0;
}
