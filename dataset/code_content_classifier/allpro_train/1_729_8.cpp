#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const int MAX = 555;
int in[MAX], out[MAX], v[MAX], s[MAX], w[MAX], n;
int pd[MAX][1010], ind[MAX];
bool cmp(int a, int b) {
  if (in[a] != in[b]) return in[a] < in[b];
  return out[a] > out[b];
}
int solve(int x, int S, int u, vector<int>& dp);
int go(int id, int max_w) {
  if (id == n) return 0;
  if (~pd[id][max_w]) return pd[id][max_w];
  int ret = 0, u = ind[id];
  int n_max = min(s[u], max_w - w[u]);
  vector<int> dp(n, -1);
  for (int i = id + 1; i < n; ++i) {
    int v = ind[i];
    if (out[v] <= out[u] && w[v] <= n_max) {
      ret = max(ret, solve(i, n_max, u, dp));
    }
  }
  ret = ret + v[u];
  return pd[id][max_w] = ret;
}
int solve(int x, int S, int u, vector<int>& dp) {
  if (~dp[x]) return dp[x];
  dp[x] = 0;
  for (int i = x + 1; i < n; ++i)
    if (in[ind[i]] >= out[ind[x]] && out[ind[i]] <= out[u] && w[ind[i]] <= S) {
      dp[x] = max(dp[x], solve(i, S, u, dp));
    }
  return dp[x] = dp[x] + go(x, S);
}
int main() {
  int S;
  scanf("%d %d", &n, &S);
  for (int(i) = (0); (i) < (n); ++(i))
    scanf("%d %d %d %d %d", &in[i], &out[i], &w[i], &s[i], &v[i]);
  for (int(i) = (0); (i) < (n); ++(i)) ind[i] = i;
  sort(ind, ind + n, cmp);
  memset((pd), (-1), sizeof(pd));
  vector<int> dp(n, -1);
  int rsp = 0;
  out[n] = 2 * n + 1;
  for (int(i) = (0); (i) < (n); ++(i)) {
    if (w[ind[i]] <= S) rsp = max(rsp, solve(i, S, n, dp));
  }
  printf("%d\n", rsp);
  return 0;
}
