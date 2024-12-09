#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const long long mod = 998244353;
long long dp[maxn][3];
vector<int> v[maxn];
int n;
void dfs(int x, int fa) {
  dp[x][0] = dp[x][1] = dp[x][2] = 1;
  for (int i : v[x]) {
    if (i == fa) continue;
    dfs(i, x);
    dp[x][0] =
        dp[x][0] * ((2 * dp[i][0] + 2 * dp[i][1] - dp[i][2] + mod) % mod) % mod;
    dp[x][1] =
        dp[x][1] * ((2 * dp[i][0] + dp[i][1] - dp[i][2] + mod) % mod) % mod;
    dp[x][2] = dp[x][2] * ((dp[i][0] + dp[i][1] - dp[i][2] + mod) % mod) % mod;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i < n; i++) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1, 0);
  printf("%lld", (dp[1][0] + dp[1][1] - dp[1][2] - 1 + mod) % mod);
  return 0;
}
