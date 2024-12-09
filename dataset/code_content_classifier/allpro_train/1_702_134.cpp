#include <bits/stdc++.h>
using namespace std;
const long long N = 200005;
const long long M = 1e9 + 7;
long long dp[N];
long long cnt[N];
long long ans[N];
vector<pair<long long, long long> > vp;
set<pair<long long, long long> > s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp, 1, sizeof dp);
  long long n;
  cin >> n;
  vp.push_back(make_pair(0LL, 0LL));
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    vp.push_back(make_pair(x, i));
  }
  sort((vp).begin(), (vp).end());
  dp[0] = 0;
  for (long long i = 3; i <= n; i++) {
    s.insert(make_pair(dp[i - 3] - vp[i - 2].first, i - 3));
    auto x = s.begin();
    dp[i] = x->first + vp[i].first;
    cnt[i] = x->second;
  }
  long long idx = n;
  long long c = 0;
  while (1) {
    if (idx == 0) break;
    long long x = cnt[idx];
    c++;
    while (idx > x) {
      ans[vp[idx].second] = c;
      idx--;
    }
    idx = x;
  }
  cout << dp[n] << " " << c << "\n";
  for (long long i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
