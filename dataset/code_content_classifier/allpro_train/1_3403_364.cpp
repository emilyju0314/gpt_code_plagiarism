#include <bits/stdc++.h>
using namespace std;
string s, ans;
int dp[2000000];
int main() {
  cin >> s;
  int n = (int)s.length();
  for (int i = n - 1; i >= 0; --i) dp[i] = max(dp[i + 1], (int)s[i]);
  for (int i = 0; i < n; ++i)
    if (s[i] == dp[i]) ans += s[i];
  cout << ans;
}
