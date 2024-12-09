#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 5e5 + 5;
int n, k, dp[N][27];
string s;
int solve(int idx, int last) {
  if (idx >= s.size()) return 0;
  if (dp[idx][last] != -1) return dp[idx][last];
  int ans = 1e9;
  if (s[idx] - 'A' != last) ans = solve(idx + 1, s[idx] - 'A');
  for (int i = 0; i < min(k, 7); i++) {
    if (i == last || i == s[idx] - 'A') continue;
    ans = min(ans, solve(idx + 1, i) + 1);
  }
  return dp[idx][last] = ans;
}
void print(int idx, int last) {
  if (idx >= s.size()) return;
  if (s[idx] - 'A' != last && solve(idx + 1, s[idx] - 'A') == dp[idx][last]) {
    cout << s[idx];
    print(idx + 1, s[idx] - 'A');
    return;
  }
  for (int i = 0; i < min(k, 7); i++) {
    if (i == last || i == s[idx] - 'A') continue;
    if (solve(idx + 1, i) + (i == (s[idx] - 'A') ? 0 : 1) == dp[idx][last]) {
      cout << char('A' + i);
      print(idx + 1, i);
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> s;
  memset(dp, -1, sizeof dp);
  cout << solve(0, k) << '\n';
  print(0, k);
  return 0;
}
