#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;
int a[MAXN], b[MAXN];
struct node {
  long long aa, bb;
} dp[MAXN];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i);
    dp[0].aa = dp[0].bb = 0;
    for (int i = 1; i <= n; i++) {
      long long aaa = dp[i - 1].aa | a[i];
      long long bbb = dp[i - 1].bb | b[i];
      if (aaa + bbb >= a[i] + b[i]) {
        dp[i].bb = bbb;
        dp[i].aa = aaa;
      } else {
        dp[i].bb = a[i];
        dp[i].aa = b[i];
      }
    }
    long long mx = 0;
    for (int i = 1; i <= n; i++) mx = max(mx, dp[i].aa + dp[i].bb);
    printf("%lld\n", mx);
  }
  return 0;
}
