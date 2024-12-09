#include <bits/stdc++.h>
using namespace std;
void oj() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long dp[2005][2005][2];
long long limit[2005];
long long m, d;
long long find(long long x, long long n, long long rem, bool ok) {
  if (x == n) return (rem == 0) ? 1 : 0;
  if (dp[x][rem][ok] != -1) return dp[x][rem][ok];
  long long ans = 0;
  for (long long i = 0; i <= 9; i++) {
    if (x % 2 == 0 && i == d) continue;
    if (x % 2 == 1 && i != d) continue;
    if (!ok || i < limit[x])
      ans = (ans + find(x + 1, n, (10 * rem + i) % m, false)) % 1000000007;
    else if (i == limit[x])
      ans = (ans + find(x + 1, n, (10 * rem + i) % m, true)) % 1000000007;
  }
  return dp[x][rem][ok] = ans;
}
long long check(string s) {
  long long ans = 1;
  for (long long i = 0; i < s.length(); i += 2)
    if (s[i] == d + 48) ans = 0;
  for (long long i = 1; i < s.length(); i += 2)
    if (s[i] != d + 48) ans = 0;
  long long temp = 0;
  for (long long i = 0; i < s.length(); i++) temp = (10 * temp + s[i] - 48) % m;
  if (temp != 0) ans = 0;
  return ans;
}
long long doit(string s) {
  memset(dp, -1, sizeof dp);
  for (long long i = 0; i < s.length(); i++) limit[i] = s[i] - '0';
  long long ans1 = find(0, s.length(), 0, true);
  memset(dp, -1, sizeof dp);
  long long ans2 = find(0, s.length() - 1, 0, false);
  return ans1 + ans2;
}
void solve() {
  cin >> m >> d;
  string s, t;
  cin >> s >> t;
  long long ans1 = 0, ans2 = 0;
  ans1 = doit(t);
  ans2 = doit(s);
  cout << (ans1 - ans2 + check(s) + 1000000007) % 1000000007;
}
signed main() {
  oj();
  solve();
  return 0;
}
