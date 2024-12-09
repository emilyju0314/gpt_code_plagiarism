#include <bits/stdc++.h>
using namespace std;
string itosm(long long x) {
  if (x == 0) return "0";
  string ans = "";
  while (x > 0) {
    ans += ((x % 10) + '0');
    x /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
long long stoim(string str) {
  long long ans = 0;
  long long k = 1;
  for (int i = str.length() - 1; i >= 0; i--) {
    ans += (str[i] - '0') * k;
    k *= 10;
  }
  return ans;
}
const long long infll = 1e18 + 3;
const int inf = 1009000999;
const double eps = 1e-6;
const int maxn = 2e5 + 7777;
const int baseint = 1000200013;
const long long basell = 1e18 + 3;
const long double PI = acos(-1.0);
const int mod = 1e9 + 7;
pair<int, int> a[maxn];
int dp[maxn][2];
int main() {
  srand(228228);
  ios_base::sync_with_stdio(0);
  ;
  int n;
  cin >> n;
  for (int i = (0); i < (n); i++) cin >> a[i].first >> a[i].second;
  a[n].first = 2e9 + 1;
  dp[0][0] = 1;
  if (a[0].first + a[0].second < a[1].first) dp[0][1] = 1;
  for (int i = (1); i < (n); i++) {
    if (a[i].first - a[i].second > a[i - 1].first) dp[i][0] = dp[i - 1][0] + 1;
    if (a[i].first - a[i].second - a[i - 1].second > a[i - 1].first)
      dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
    if (a[i].first + a[i].second < a[i + 1].first)
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
    dp[i][0] = max(dp[i][0], dp[i - 1][0]);
    if (a[i].first - a[i - 1].second > a[i - 1].first)
      dp[i][0] = max(dp[i][0], dp[i - 1][1]);
  }
  cout << max(dp[n - 1][0], dp[n - 1][1]);
  return 0;
}
