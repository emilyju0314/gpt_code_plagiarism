#include <bits/stdc++.h>
using namespace std;
int n, l;
long long total = 0;
long long mod = 1000000007;
long long dp[103][3003][2];
struct plank {
  int width, length;
} a[1000];
long long func(int plank, int len, int orientation) {
  long long cunt = 0;
  if (len > l) return 0;
  if (plank == n) return 0;
  if (len == l) return 1;
  int i;
  if (dp[plank][len][orientation] != -1) return dp[plank][len][orientation];
  if (orientation == 0) {
    for (i = 0; i < n; i++) {
      if (i == plank) continue;
      if (a[plank].width == a[i].length) cunt += func(i, len + a[i].length, 0);
      if (a[i].length != a[i].width) {
        if (a[plank].width == a[i].width) cunt += func(i, len + a[i].width, 1);
      }
    }
  }
  if (orientation == 1) {
    for (i = 0; i < n; i++) {
      if (i == plank) continue;
      if (a[plank].length == a[i].length) cunt += func(i, len + a[i].length, 0);
      if (a[i].length != a[i].width) {
        if (a[plank].length == a[i].width) cunt += func(i, len + a[i].width, 1);
      }
    }
  }
  return dp[plank][len][orientation] = cunt % mod;
}
int main() {
  int i, j, fl, test;
  scanf("%d %d", &n, &l);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a[i].length, &a[i].width);
  }
  memset(dp, -1, sizeof(dp));
  for (i = 0; i < n; i++) {
    total += func(i, a[i].length, 0);
    total = total % mod;
    if (a[i].length != a[i].width) total += func(i, a[i].width, 1);
    total = total % mod;
  }
  printf("%lld\n", total % mod);
  return 0;
}
