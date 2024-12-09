#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int dp[4][N];
string str2[N], str3[N];
set<string> ans;
int n;
int cal(int len, int idx) {
  if (dp[len][idx] != -1) return dp[len][idx];
  if (idx == n - 1) return dp[len][idx] = 1;
  ;
  int x = 0;
  if (idx + 2 < n) {
    if (len == 2 && str2[idx] == str2[idx + 2]) {
    } else
      x |= cal(2, idx + 2);
  }
  if (idx + 3 < n) {
    if (len == 3 && str3[idx] == str3[idx + 3]) {
    } else
      x |= cal(3, idx + 3);
  }
  x = x ? 1 : 0;
  return dp[len][idx] = x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s;
  cin >> s;
  n = s.length();
  for (int i = 0; i < n - 1; ++i) {
    str2[i + 1] = s.substr(i, 2);
    if (i + 2 < n) str3[i + 2] = s.substr(i, 3);
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j <= n; ++j) dp[i][j] = -1;
  }
  for (int i = 6; i < n; ++i) {
    if (dp[2][i] == -1) cal(2, i);
    if (i > 6 && dp[3][i] == -1) cal(3, i);
  }
  for (int i = 5; i < n; ++i) {
    if (dp[2][i] > 0) ans.insert(str2[i]);
    if (dp[3][i] > 0) ans.insert(str3[i]);
  }
  cout << ans.size() << endl;
  for (auto I : ans) cout << I << endl;
}
