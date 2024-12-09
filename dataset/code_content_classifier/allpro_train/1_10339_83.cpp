#include <bits/stdc++.h>
using namespace std;
long double dist(long double x1, long double y1, long double x2,
                 long double y2) {
  long double D = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
  return sqrt(D);
}
int main() {
  const int inf = 1e9;
  int n;
  cin >> n;
  vector<pair<int, pair<pair<int, int>, long double>>> v;
  for (int i = 0; i < n; i++) {
    int x, y, t;
    long double p;
    cin >> x >> y >> t >> p;
    v.push_back({t, {{x, y}, p}});
  }
  sort(v.begin(), v.end());
  long double ans = 0.0;
  vector<long double> dp(n + 1, 0.0);
  for (int i = 1; i <= n; i++) dp[i] = v[i - 1].second.second;
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      long double x1 = (v[i].second.first.first),
                  x2 = (v[j].second.first.first);
      long double y1 = v[i].second.first.second, y2 = v[j].second.first.second;
      if (dist(x1, y1, x2, y2) <= (long double)(v[i].first - v[j].first)) {
        dp[i + 1] = max(dp[i + 1], dp[j + 1] + v[i].second.second);
      }
    }
    ans = max(ans, dp[i + 1]);
  }
  cout << setprecision(14) << ans << "\n";
}
