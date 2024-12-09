#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 100;
const int INF = 0x3f3f3f3f;
inline long long fpow(long long a, long long b) {
  long long r = 1, t = a;
  while (b) {
    if (b & 1) r = (r * t) % MOD;
    b >>= 1;
    t = (t * t) % MOD;
  }
  return r;
}
vector<int> G[MAXN << 1];
int w[MAXN], dp[MAXN], rt, n, mx;
int ans[MAXN];
void dfs(int x, int fa) {
  dp[x] = w[x];
  for (auto it : G[x]) {
    if (it == fa) continue;
    dfs(it, x);
    dp[x] = max(dp[x], dp[x] + dp[it]);
  }
}
void DFS(int x, int fa) {
  ans[x] = dp[x];
  for (auto it : G[x]) {
    if (it == fa) continue;
    int tot = dp[x];
    dp[x] -= max(0, dp[it]);
    dp[it] += max(0, dp[x]);
    DFS(it, x);
    dp[x] = tot;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
    if (w[i] == 0) w[i] = -1;
  }
  for (int i = 1; i < n; i++) {
    int ui, vi;
    scanf("%d %d", &ui, &vi);
    G[ui].push_back(vi);
    G[vi].push_back(ui);
  }
  dfs(1, 0);
  DFS(1, 0);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  cout << endl;
  return 0;
}
