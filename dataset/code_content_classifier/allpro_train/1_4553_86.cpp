#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 5e3 + 5;
const long double pi = 3.14159265359;
const long long INF = (1LL << 60);
deque<pair<long long, long long> > dq;
long long n, m, x[N], dp[N][2], pre[N], sum;
pair<long long, long long> p[N];
void add(long long k, long long id) {
  while ((long long)dq.size() && dq.back().first >= k) dq.pop_back();
  dq.push_back(make_pair(k, id));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) cin >> x[i];
  for (long long j = 1; j <= m; j++)
    cin >> p[j].first >> p[j].second, sum += p[j].second;
  if (sum < n) {
    cout << "-1\n";
    return 0;
  }
  sort(x + 1, x + n + 1);
  sort(p + 1, p + m + 1);
  for (long long i = 1; i <= n; i++) dp[i][0] = INF;
  for (long long j = 1; j <= m; j++) {
    while ((long long)dq.size()) dq.pop_front();
    memset(pre, 0, sizeof(pre));
    for (long long i = 1; i <= n; i++)
      pre[i] = abs(x[i] - p[j].first) + pre[i - 1];
    for (long long i = 0; i < n + 1; i++) {
      add(dp[i][(j - 1) % 2] - pre[i], i);
      dp[i][j % 2] = dq.front().first + pre[i];
      while ((long long)dq.size() && dq.front().second <= i - p[j].second)
        dq.pop_front();
    }
  }
  cout << dp[n][m % 2] << "\n";
  return 0;
}
