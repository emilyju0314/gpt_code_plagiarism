#include <bits/stdc++.h>
using namespace std;
int dp[203] = {};
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> vl;
  int a, b;
  int tt_sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    vl.push_back({a, b});
    tt_sum += b;
  }
  for (int i = 0; i < 203; ++i) dp[i] = -tt_sum;
  for (int i = 0; i < n; ++i) {
    for (int j = 201; j >= 0; --j) {
      if (dp[j] != -tt_sum) {
        dp[j + vl[i].first] = max(dp[j + vl[i].first], dp[j] + vl[i].second);
      }
    }
    dp[vl[i].first] = max(dp[vl[i].first], -tt_sum + vl[i].second);
  }
  for (int i = 0; i < 203; ++i) {
    int temp = -dp[i];
    if ((i - temp) >= 0) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
