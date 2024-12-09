#include <bits/stdc++.h>
using namespace std;
int n, m, cb;
int cost[105], comp[105], cov[105], ord[105];
long long dp[5 + (1 << 20)], buf[5 + (1 << 20)], ret;
bool cmp(int x, int y) { return comp[x] < comp[y]; }
int main() {
  scanf("%d%d%d", &n, &m, &cb);
  for (int i = (0); i < (n); i++) {
    int t, x;
    scanf("%d%d%d", &cost[i], &comp[i], &t);
    cov[i] = 0;
    while (t--) scanf("%d", &x), cov[i] += (1 << (x - 1));
    ord[i] = i;
  }
  sort(ord, ord + n, cmp);
  for (int j = (0); j < (1 << m); j++) dp[j] = 1LL << 60;
  dp[0] = 0;
  ret = (1LL << 60);
  for (int i = (0); i < (n); i++) {
    int t = ord[i];
    for (int j = (0); j < (1 << m); j++) buf[j] = dp[j];
    for (int j = (0); j < (1 << m); j++)
      buf[j | cov[t]] = min(buf[j | cov[t]], dp[j] + cost[t]);
    for (int j = (0); j < (1 << m); j++) dp[j] = buf[j];
    ret = min(ret, dp[(1 << m) - 1] + comp[t] * 1LL * cb);
  }
  printf("%I64d\n", ret >= (1LL << 60) ? -1 : ret);
  return 0;
}
