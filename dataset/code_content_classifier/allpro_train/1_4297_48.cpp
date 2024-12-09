#include <bits/stdc++.h>
using namespace std;
int k;
vector<int> edge[300001];
long long ct[300001];
long long dp[300001];
long long ct1[300001][5];
long long an[5];
long long ans = 0;
void dfs(int v, int p) {
  dp[v] = 0;
  ct[v] = 1;
  for (auto u : edge[v]) {
    if (u != p) {
      dfs(u, v);
      dp[v] += dp[u] + ct[u];
      ct[v] += ct[u];
    }
  }
  for (auto u : edge[v]) {
    if (u != p) ans += (dp[u] + ct[u]) * (ct[v] - ct[u]);
  }
}
void dfs1(int v, int p) {
  ct1[v][0] = 1;
  for (auto u : edge[v]) {
    if (u != p) {
      dfs1(u, v);
      for (int c = 0; c < k; c++) {
        ct1[v][c] += ct1[u][(c + 1) % k];
      }
    }
  }
  for (int c = 0; c < k; c++) {
    an[c] += ct1[v][c] - (c == 0);
  }
  int ct[5] = {0, 0, 0, 0, 0};
  for (auto u : edge[v]) {
    if (u != p) {
      for (int c = 0; c < k; c++)
        for (int d = 0; d < k; d++)
          an[c] += ct1[u][d] * ct[(c - d + k + 2) % k];
      for (int d = 0; d < k; d++) ct[d] += ct1[u][d];
    }
  }
}
int main() {
  int n;
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  dfs(0, 0);
  dfs1(0, 0);
  for (int c = 0; c < k; c++) {
    ans += an[c] * c;
  }
  cout << ans / k;
  return 0;
}
