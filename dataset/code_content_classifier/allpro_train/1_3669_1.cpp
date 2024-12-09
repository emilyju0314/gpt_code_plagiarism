#include <bits/stdc++.h>
using namespace std;
long long a, b, dp[400007];
int k;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long solve(long long a, long long b) {
  memset(dp, 0x3f, sizeof(dp));
  dp[a] = 0;
  for (int i = a; i > b; i--) {
    dp[i - 1] = min(dp[i] + 1, dp[i - 1]);
    for (int j = 2; j <= k; j++) dp[i - i % j] = min(dp[i - i % j], dp[i] + 1);
  }
  return dp[b];
}
int main() {
  scanf("%I64d%I64d%d", &a, &b, &k);
  long long lcm = 2;
  for (int i = 3; i <= k; i++) {
    int d = gcd(i, lcm);
    lcm *= i;
    lcm /= d;
  }
  long long ans;
  if (a / lcm == b / lcm)
    ans = solve(a % lcm, b % lcm);
  else
    ans = solve(a % lcm, 0) + (a / lcm - b / lcm - 1) * solve(lcm, 0) +
          solve(lcm, b % lcm);
  printf("%I64d\n", ans);
}
