#include <bits/stdc++.h>
using namespace std;
long long dp[150007][2];
long long a[150007], b[150007], t[150007];
deque<pair<long long, long long> > dq;
void operation1(int baad, int i, int j) {
  while (dq.size() and dq.front().first < baad) dq.pop_front();
  while (dq.size() and dq.back().second < dp[i][j]) dq.pop_back();
  dq.push_back({i, dp[i][j]});
}
void operation2(int baad, int i, int j) {
  while (dq.size() and dq.front().first > baad) dq.pop_front();
  while (dq.size() and dq.back().second < dp[i][j]) dq.pop_back();
  dq.push_back({i, dp[i][j]});
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, d;
  cin >> n >> m >> d;
  for (int i = 1; i <= m; i++) cin >> a[i] >> b[i] >> t[i];
  int now = 0;
  for (int i = 1; i <= m; i++) {
    long long k = min(n, (t[i] - t[i - 1]) * d);
    dq.clear();
    for (int j = 1; j <= n; j++) {
      operation1(j - k, j, now ^ 1);
      dp[j][now] = dq.front().second;
      dp[j][now] += b[i] - abs(a[i] - j);
    }
    dq.clear();
    for (int j = n; j >= 1; j--) {
      operation2(j + k, j, now ^ 1);
      dp[j][now] = max(dp[j][now], dq.front().second + b[i] - abs(a[i] - j));
    }
    now ^= 1;
  }
  long long ans = -1000000000000000LL;
  for (int i = 1; i <= n; i++) ans = max(ans, dp[i][now ^ 1]);
  cout << ans << "\n";
}
