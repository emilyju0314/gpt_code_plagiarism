#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005], precal[5005];
long long ara[5005];
int solve(int now, int prv) {
  if (now < 0) return 0;
  int &ret = dp[now][prv];
  if (ret != -1) return ret;
  long long prvval = (ara[prv] >> min(prv - now - 1, precal[prv]));
  ret = 1 + solve(now - 1, prv);
  if (prvval & 1) {
    if (ara[now] % prvval == 0) ret = min(ret, solve(now - 1, now));
  } else if (ara[now] % prvval == (prvval >> 1))
    ret = min(ret, solve(now - 1, now));
  return ret;
}
int main() {
  int i, n;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%I64d", &ara[i]);
    precal[i] = __builtin_ctzll(ara[i]);
  }
  ara[n] = 1;
  precal[n] = 0;
  memset(dp, -1, sizeof(dp));
  cout << solve(n - 1, n) << endl;
  return 0;
}
