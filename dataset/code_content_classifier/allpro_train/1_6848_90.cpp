#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int C[101];
int dp[101][10001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> C[i];
    sum += C[i];
  }
  for (int i = 0; i <= 100; i++) {
    for (int j = 1; j <= 10000; j++) {
      dp[i][j] = -1;
    }
  }
  dp[1][C[1]] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= 10000; j++) {
      if (dp[i - 1][j] != -1) dp[i][j] = j;
      if (dp[i][j] == -1 && j - C[i] >= 0 && dp[i - 1][j - C[i]] != -1 &&
          C[1] >= C[i] * 2) {
        dp[i][j] = j - C[i];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 10000; j++) {
      if (j * 2 > sum && dp[i][j] != -1) {
        vector<int> ans;
        for (int k = i; k > 0; k--) {
          if (dp[k][j] != j) ans.push_back(k);
          j = dp[k][j];
        }
        cout << ans.size() << '\n';
        reverse(ans.begin(), ans.end());
        for (int i : ans) cout << i << ' ';
        return 0;
      }
    }
  }
  cout << 0;
  return 0;
}
