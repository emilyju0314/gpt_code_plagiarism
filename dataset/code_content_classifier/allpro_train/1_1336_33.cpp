#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 305;
const int MAX_T = 1e5 + 5;
const int MOD = 1e9 + 7;
int n, q, t;
int in[MAX_N];
int out[MAX_N];
int dp[MAX_T];
int cnt;
int a[MAX_N];
inline int dfs(int u) {
  if (u == 0) {
    return 0;
  }
  cnt++;
  int v = out[u];
  int ret = min(dfs(v), t + 1);
  a[u] += a[v];
  return ret + a[u];
}
int main() {
  scanf("%d %d %d", &n, &q, &t);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    out[v] = u;
    in[u] = v;
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) {
      if (sum < t) {
        sum += dfs(i) - a[i];
      }
    }
  }
  if (cnt != n) {
    printf("0\n");
    return 0;
  }
  if (sum <= t) {
    dp[sum] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = sum; j <= t - a[i]; j++) {
      dp[j + a[i]] = (dp[j] + dp[j + a[i]]) % MOD;
    }
  }
  printf("%d\n", dp[t]);
}
