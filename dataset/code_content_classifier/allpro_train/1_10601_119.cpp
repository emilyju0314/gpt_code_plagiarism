#include <bits/stdc++.h>
using namespace std;
int dp[5 * 1005][5 * 1005];
vector<int> cols[5 * 1005];
class Solution {
 public:
  void solve(std::istream& in, std::ostream& out) {
    int n, m;
    in >> n >> m;
    string s;
    for (int i = 1; i <= n; i++) {
      in >> s;
      for (int j = 1; j <= m; j++) {
        if (s[j - 1] == '1') dp[i][j] = 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = m; j >= 1; j--) {
        if (dp[i][j] == 1) dp[i][j] += dp[i][j + 1];
        cols[j].push_back(dp[i][j]);
      }
    }
    for (int i = 1; i <= m; i++) sort((cols[i]).begin(), (cols[i]).end());
    int ans = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        ans = max(ans, cols[i][j - 1] * (n - (j - 1)));
      }
    }
    out << ans << '\n';
    return;
  }
};
void solve(std::istream& in, std::ostream& out) {
  out << std::setprecision(12);
  Solution solution;
  solution.solve(in, out);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  istream& in = cin;
  ostream& out = cout;
  solve(in, out);
  return 0;
}
