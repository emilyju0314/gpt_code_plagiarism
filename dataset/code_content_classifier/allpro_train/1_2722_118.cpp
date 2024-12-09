#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 2e5 + 50;
const int inf = 1e9;
int prime[17] = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                 29, 31, 37, 39, 41, 43, 47, 53};
int dp[105][1 << 17], pre[105][1 << 17], num[105][1 << 17];
int sta[70];
int a[150];
void dfs(int pos, int st) {
  if (pos == 1) {
    cout << pre[pos][st] << " ";
    return;
  }
  dfs(pos - 1, st ^ (sta[pre[pos][st]]));
  cout << pre[pos][st] << " ";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 2; i < 60; i++) {
    for (int j = 0; j < 17; j++) {
      if (i % prime[j] == 0) sta[i] |= (1 << j);
    }
  }
  for (int i = 0; i < 105; i++) {
    for (int j = 0; j < (1 << 17); j++) dp[i][j] = inf;
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << 17); j++) {
      if (dp[i][j] == inf) continue;
      for (int k = 1; k < 60; k++) {
        if (j & sta[k]) continue;
        int now = j | sta[k];
        if (dp[i + 1][now] > dp[i][j] + abs(a[i] - k)) {
          dp[i + 1][now] = dp[i][j] + abs(a[i] - k);
          pre[i + 1][now] = k;
        }
      }
    }
  }
  int st;
  int mx = inf;
  for (int i = 0; i < (1 << 17); i++) {
    if (dp[n][i] < mx) {
      mx = dp[n][i];
      st = i;
    }
  }
  dfs(n, st);
  return 0;
}
