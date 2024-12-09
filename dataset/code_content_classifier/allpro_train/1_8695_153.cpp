#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, a, b;
  cin >> k >> a >> b;
  string s;
  cin >> s;
  s = '_' + s;
  int n = s.size();
  bool dp[k][n];
  memset(dp, false, sizeof(dp));
  int pre[k][n];
  memset(pre, -1, sizeof(pre));
  for (int i = a; i <= n and i <= b; i++) {
    dp[0][i] = true;
  }
  for (int i = 1; i < k; i++) {
    for (int j = 1; j < n; j++) {
      if (j >= a) {
        for (int k = a; k <= b; k++) {
          if (j - k > 0) {
            if (dp[i - 1][j - k] == true) {
              pre[i][j] = k;
              dp[i][j] = true;
            }
          }
        }
      }
    }
  }
  if (!dp[k - 1][n - 1]) {
    cout << "No solution";
    return 0;
  }
  vector<int> sol;
  sol.push_back(n - 1);
  int i = k - 1;
  int j = n - 1;
  while (i > 0) {
    sol.push_back(j - pre[i][j]);
    j -= pre[i][j];
    i--;
  }
  reverse(sol.begin(), sol.end());
  int start = 1;
  for (auto end : sol) {
    for (int i = start; i <= end; i++) {
      cout << s[i];
    }
    cout << endl;
    start = end + 1;
  }
  return 0;
}
