#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e12;
const int mod = 998244353;
int k;
pair<int, int> dp[20][1024];
int b[20], w;
int can[1024], p[30];
pair<int, int> dfs(int o, bool isTop, bool pre, int mask) {
  if (o < 0) return make_pair(can[mask], 0);
  if (!isTop && !pre && dp[o][mask].first != -1) return dp[o][mask];
  pair<int, int> ans;
  int tt = isTop ? b[o] : 9;
  for (int i = 0; i <= tt; ++i) {
    int nmask = mask;
    if (i || !pre) {
      nmask |= 1 << i;
    }
    pair<int, int> x = dfs(o - 1, isTop && i == tt, pre && !i, nmask);
    ans.first += x.first;
    if (ans.first >= mod) ans.first -= mod;
    ans.second += x.second;
    if (ans.second >= mod) ans.second -= mod;
    ans.second += 1LL * p[o] * i % mod * x.first % mod;
    if (ans.second >= mod) {
      ans.second -= mod;
    }
  }
  if (!isTop && !pre) {
    dp[o][mask] = ans;
  }
  return ans;
}
int cal(long long x) {
  w = 0;
  do {
    b[w++] = x % 10;
    x /= 10;
  } while (x);
  return dfs(w - 1, 1, 1, 0).second;
}
int main() {
  p[0] = 1;
  for (int i = 1; i < 29; ++i) {
    p[i] = 10LL * p[i - 1] % mod;
  }
  long long l, r;
  memset(dp, -1, sizeof(dp));
  scanf("%lld%lld%d", &l, &r, &k);
  for (int i = 0; i < 1024; ++i) {
    int cnt = 0;
    for (int j = 0; j < 10; ++j) {
      cnt += i >> j & 1;
    }
    can[i] = cnt <= k;
  }
  printf("%d\n", (cal(r) + mod - cal(l - 1)) % mod);
  return 0;
}
