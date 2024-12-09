#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long, long long> p1, pair<long long, long long> p2) {
  if (p1.first != p2.first)
    return p1.first > p2.first;
  else
    return p1.second < p2.second;
}
long long n;
vector<pair<long long, long long> > v;
long long vis[51][51];
long double dp[51][51];
long double thres;
pair<long long, long long> path[50][50];
long double rec(long long i, long long j) {
  if (i == n) return 0;
  if (vis[i][j] == 0) {
    vis[i][j] = 1;
    dp[i][j] = -1e18;
    long long k = i;
    for (; k < n; k++) {
      if (v[k].first == v[i].first)
        ;
      else
        break;
    }
    long double sum = 0;
    for (long long f = k - 1; f >= i; f--) {
      if (j >= f - i + 1) {
        dp[i][j] = max(dp[i][j], sum + rec(k, j - (f - i + 1) + k - 1 - f));
      }
      sum += -v[f].first + thres * v[f].second;
    }
    dp[i][j] = max(dp[i][j], sum + rec(k, j + k - i));
    return dp[i][j];
  } else
    return dp[i][j];
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  v.resize(n);
  memset(vis, 0, sizeof(vis));
  for (long long i = 0; i < n; i++) cin >> v[i].first;
  for (long long i = 0; i < n; i++) cin >> v[i].second;
  sort(v.begin(), v.end(), comp);
  long double hi = 10000000000;
  long double lo = 0;
  long long c = 500;
  while (c--) {
    long double mid = (lo + hi) / 2;
    long double ans = -1;
    thres = mid;
    memset(vis, 0, sizeof(vis));
    ans = rec(0, 0);
    if (ans >= 0)
      hi = mid;
    else
      lo = mid;
  }
  long long fans = ceil(1000 * lo);
  cout << fans;
  return 0;
}
