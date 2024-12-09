#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > ev[200005];
bool cmp(long long a, long long b) { return a > b; }
long long n;
void init() {
  scanf("%lld", &n);
  for (long long turns = 1; turns <= n; ++turns) {
    vector<long long> G[5];
    long long c;
    scanf("%lld", &c);
    while (c--) {
      long long types;
      long long attack;
      scanf("%lld %lld", &types, &attack);
      G[types].push_back(attack);
    }
    for (long long i = 1; i <= 3; ++i) sort(G[i].begin(), G[i].end(), cmp);
    for (long long i = 0; i < min(3LL, (long long)G[1].size()); ++i)
      ev[turns].push_back(make_pair(1, G[1][i]));
    for (long long i = 0; i < min(1LL, (long long)G[2].size()); ++i)
      ev[turns].push_back(make_pair(2, G[2][i]));
    for (long long i = 0; i < min(1LL, (long long)G[3].size()); ++i)
      ev[turns].push_back(make_pair(3, G[3][i]));
  }
}
long long dp[200005][10];
long long cal(long long turns, long long ith) {
  if (turns == 0) {
    if (ith == 0)
      return 0;
    else
      return -0x3f3f3f3f3f3f3f3f;
  }
  if (dp[turns][ith] != -1) return dp[turns][ith];
  long long ret = -0x3f3f3f3f3f3f3f3f;
  long long sz = ev[turns].size();
  for (long long i = 0; i < (1 << sz); ++i) {
    long long fees = 0;
    long long attack = 0;
    long long num = 0;
    long long mx = 0;
    for (long long j = 0; j < sz; ++j) {
      if (i & (1 << j)) {
        ++num;
        fees += ev[turns][j].first;
        attack += ev[turns][j].second;
        mx = max(mx, ev[turns][j].second);
      }
    }
    if (fees > 3) continue;
    if (ith - num < 0) attack += mx;
    ret = max(ret, cal(turns - 1, (ith - num + 10) % 10) + attack);
  }
  dp[turns][ith] = ret;
  return ret;
}
int32_t main() {
  memset(dp, -1, sizeof(dp));
  init();
  long long ans = -0x3f3f3f3f3f3f3f3f;
  for (long long ith = 0; ith < 10; ++ith) ans = max(ans, cal(n, ith));
  printf("%lld\n", ans);
  return 0;
}
