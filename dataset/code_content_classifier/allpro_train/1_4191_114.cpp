#include <bits/stdc++.h>
using namespace std;
int n, a[100010], dp[100010][2], cum[100010];
int calc(int at, int flag) {
  if (at == n + 1) return 0;
  int &ret = dp[at][flag];
  if (~ret) return ret;
  ret = 0;
  if (flag) {
    ret = max(ret, calc(at + 1, 1) - a[at]);
    ret = max(ret, calc(at + 1, 0) - a[at]);
  } else {
    ret = max(ret, calc(at + 1, 0) + a[at]);
    ret = max(ret, -cum[n] + cum[at - 1]);
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n; ++i) cum[i] = cum[i - 1] + a[i];
  memset(dp, -1, sizeof dp);
  printf("%d", max(calc(1, 0), calc(1, 1)));
  return 0;
}
