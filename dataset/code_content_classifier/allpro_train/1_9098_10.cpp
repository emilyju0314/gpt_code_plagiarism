#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, k;
multiset<pair<int, int> > st[N], en[N], events;
int maxval[N];
int nextpos[N];
long long int dp[N][205];
long long int solve(int t, int rem) {
  if (rem < 0) {
    return 1e18;
  }
  if (t > n) {
    return 0;
  }
  if (dp[t][rem] != -1) {
    return dp[t][rem];
  }
  long long int ans =
      min(solve(nextpos[t], rem) + maxval[t], solve(t + 1, rem - 1));
  return dp[t][rem] = ans;
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    int s, t, d, w;
    scanf("%d %d %d %d", &s, &t, &d, &w);
    st[s].insert({w, d});
    en[t + 1].insert({w, d});
  }
  for (int i = 1; i <= n; i++) {
    for (auto it : st[i]) {
      events.insert({it.first, it.second});
    }
    for (auto it : en[i]) {
      events.erase(events.find({it.first, it.second}));
    }
    if (events.empty()) {
      maxval[i] = 0;
      nextpos[i] = i + 1;
    } else {
      auto it = events.end();
      it--;
      maxval[i] = (*it).first;
      nextpos[i] = (*it).second + 1;
    }
  }
  memset(dp, -1, sizeof(dp));
  printf("%lld", solve(1, m));
  return 0;
}
