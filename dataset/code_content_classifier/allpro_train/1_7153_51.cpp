#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<pair<int, int>> g[101000];
vector<pair<int, int>> prs;
int dp[101000][2];
void dfs(int u, int p) {
  for (auto pr : g[u]) {
    int v = pr.first;
    if (v == p) continue;
    dfs(v, u);
  }
  prs.clear();
  for (auto pr : g[u]) {
    int v = pr.first;
    int c = pr.second;
    if (v == p) continue;
    prs.push_back({dp[v][0] + c, dp[v][1] + c});
  }
  int n = prs.size();
  sort(prs.begin(), prs.end());
  reverse(prs.begin(), prs.end());
  int sum = 0;
  for (int i = 0; i < min(k - 1, n); i++) sum += prs[i].first;
  dp[u][0] = sum;
  if (k - 1 < n) sum += prs[k - 1].first;
  for (int i = 0; i < min(k, n); i++) {
    sum -= prs[i].first;
    sum += prs[i].second;
    if (sum > dp[u][1]) dp[u][1] = sum;
    sum -= prs[i].second;
    sum += prs[i].first;
  }
  if (k - 1 < n) sum -= prs[k - 1].first;
  for (int i = k; i < n; i++) {
    sum += prs[i].second;
    if (sum > dp[u][1]) dp[u][1] = sum;
    sum -= prs[i].second;
  }
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n - 1; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    g[u].push_back({v, c});
    g[v].push_back({u, c});
  }
  dfs(0, -1);
  printf("%d\n", dp[0][1]);
  return 0;
}
