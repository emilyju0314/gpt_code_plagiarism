#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
long long dp[505][505];
int in[505];
long long dfs(int s, int e) {
  if (dp[s][e] != -1) return dp[s][e];
  long long ans = 0;
  for (int i = s + 1; i <= e; i++) {
    if (i == e || in[i + 1] > in[s + 1])
      ans += (dfs(s + 1, i) * dfs(i, e)) % Mod;
    ans %= Mod;
  }
  dp[s][e] = ans;
  return ans;
}
void init() {
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i < 505; i++) dp[i][i] = 1;
}
int main() {
  int n;
  cin >> n;
  init();
  for (int i = 1; i <= n; i++) {
    cin >> in[i];
  }
  long long ans = dfs(1, n);
  printf("%I64d\n", ans);
}
