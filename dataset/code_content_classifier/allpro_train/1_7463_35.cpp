#include <bits/stdc++.h>
using namespace std;
bool vis[1000008];
void solve() {
  int a, b, c, i, j, k, n, m, sum = 0, ans = 0, ct = 1;
  int dp[4002];
  for (i = 0; i < 4002; i++) {
    dp[i] = 0;
    vis[i] = 0;
  }
  cin >> n;
  int mx = 2 * n;
  int D[2 * n + 6];
  for (i = 0; i < 2 * n; i++) cin >> D[i];
  vector<int> coin;
  coin.push_back(0);
  for (i = 2 * n - 1; i >= 0; i--) {
    if (D[i] == mx) {
      coin.push_back(ct);
      while (vis[--mx])
        ;
      ct = 1;
    } else {
      ct++;
      vis[D[i]] = 1;
    }
  }
  dp[0] = 1;
  int sz = coin.size();
  for (j = 1; j < sz; j++) {
    for (i = n; i >= 1; i--) {
      if (i >= coin[j] && dp[i - coin[j]]) {
        dp[i] = 1;
      }
    }
  }
  if (dp[n])
    cout << "YES\n";
  else
    cout << "NO\n";
  return;
}
int main() {
  int tt;
  cin >> tt;
  for (int t = 0; t < tt; t++) solve();
  return 0;
}
