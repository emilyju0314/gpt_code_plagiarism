#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e6, OO = 1e17, M = 1e9 + 7;
pair<long long, long long> p[N];
long long dp[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p + n);
  for (int i = 0; i < n; i++) {
    int t = lower_bound(p, p + n,
                        make_pair(p[i].first - p[i].second, (long long)0)) -
            p - 1;
    if (t < 0)
      dp[i] = 1;
    else
      dp[i] = dp[t] + 1;
  }
  cout << n - *max_element(dp, dp + n);
  return 0;
}
