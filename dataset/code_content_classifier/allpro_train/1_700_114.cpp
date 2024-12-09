#include <bits/stdc++.h>
using namespace std;
const long double PI = acos((long double)-1);
int a[200005];
int dp[200005][2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < (n); ++i) cin >> a[i];
  if (a[0] > 0) dp[0][0] = 1;
  if (a[0] < 0) dp[0][1] = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] > 0) {
      dp[i][0] = dp[i - 1][0] + 1;
      dp[i][1] = dp[i - 1][1];
    } else if (a[i] < 0) {
      dp[i][0] = dp[i - 1][1];
      dp[i][1] = dp[i - 1][0] + 1;
    }
  }
  long long neg = 0;
  long long pos = 0;
  for (int i = 0; i < (n); ++i) {
    pos += dp[i][0];
    neg += dp[i][1];
  }
  cout << neg << " " << pos;
  return 0;
}
