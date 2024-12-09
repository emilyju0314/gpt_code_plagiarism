#include <bits/stdc++.h>
using namespace std;
int dis[500005], dp[500005];
void z_function(string s, int len) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  for (int i = 0; i < n; i++) dis[i + len] = max(dis[i + len], min(z[i], i));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, a, b, i, j;
  cin >> n >> a >> b;
  string s, tmp;
  cin >> s;
  int ans = 0;
  for (i = 0; i < n; i++) z_function(s.substr(i), i);
  dp[0] = a;
  for (int i = 1; i < n; i++) {
    dp[i] = dp[i - 1] + a;
    for (int j = 1; j <= i; j++) {
      if (j - 1 + dis[j] >= i) dp[i] = min(dp[i], dp[j - 1] + b);
    }
  }
  cout << dp[n - 1];
  return 0;
}
