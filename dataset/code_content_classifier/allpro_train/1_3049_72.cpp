#include <bits/stdc++.h>
using vi = std::vector<long long int>;
using vvi = std::vector<vi>;
using pii = std::pair<long long int, long long int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
using namespace std;
const long long int N = 2e6 + 10;
const long long int inf = 1e18 + 10;
const long double Pi = 3.14159265;
long long int n, a[N], dp[N];
stack<long long int> s1, s2;
vi l, r;
long long int f(long long int i) {
  if (i == -1) return inf;
  if (i == n - 1) return 0;
  if (dp[i] != inf and i != 0) return dp[i];
  return dp[i] = 1 + min({f(l[i]), f(r[i]), f(i + 1)});
}
void solve() {
  cin >> n;
  l = vi(n, -1), r = vi(n, -1);
  fill(dp + 1, dp + n, inf);
  for (long long int i = 0; i <= n - 1; i++) cin >> a[i];
  s1.push(0), s2.push(0);
  for (long long int i = 1; i <= n - 1; i++) {
    dp[i] = min(dp[i], dp[i - 1] + 1);
    while (!s1.empty() && a[s1.top()] <= a[i]) {
      long long int z = s1.top();
      s1.pop();
      if (a[i] != a[z] and s1.empty() == 0)
        l[s1.top()] = i, dp[i] = min(1 + dp[s1.top()], dp[i]);
    }
    s1.push(i);
    while (!s2.empty() && a[s2.top()] >= a[i]) {
      long long int z = s2.top();
      s2.pop();
      if (a[i] != a[z] and s2.empty() == 0)
        r[s2.top()] = i, dp[i] = min(dp[i], 1 + dp[s2.top()]);
    }
    s2.push(i);
  }
  cout << dp[n - 1];
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
  long long int xx = 0;
  long long int t;
  cin >> t;
  while (t--) {
    ;
    solve();
    cout << endl;
  }
  return 0;
}
