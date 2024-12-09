#include <bits/stdc++.h>
const long long mod = 1000000007ll;
const long long N = 200005;
using namespace std;
long long dp[3][N];
vector<long long> d[3];
long long e, s, n, m;
long long calc(long long a, long long b) {
  long long current = lower_bound(d[a].begin(), d[a].end(), b) - d[a].begin();
  return dp[a][current] + max(d[a][current] - b - s, 0ll);
}
int main() {
  cin.sync_with_stdio(0);
  cin >> e >> s >> n >> m;
  long long t1, t2;
  for (long long i = (1); i <= (n); i++) {
    cin >> t1 >> t2;
    if (t2 >= e) continue;
    for (long long j = 0; j < (t1); j++) {
      d[j].push_back(t2);
    }
  }
  for (long long i = 0; i < (3); i++) {
    d[i].push_back(e);
    sort(d[i].begin(), d[i].end());
    for (long long j = ((long long)(d[i]).size()) - 2ll; j >= (0ll); --j) {
      dp[i][j] = dp[i][j + 1] + max(d[i][j + 1] - d[i][j] - s, 0ll);
    }
  }
  for (long long i = (1ll); i <= (m); i++) {
    long long sd;
    cin >> sd;
    if (calc(0ll, sd)) {
      cout << "-1 -1\n";
    } else {
      cout << calc(1, sd) << " " << calc(2, sd) - calc(1, sd) << "\n";
    }
  }
  return 0;
}
