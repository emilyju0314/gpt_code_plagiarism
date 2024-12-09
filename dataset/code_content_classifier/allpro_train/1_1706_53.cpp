#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
long long add(long long x, long long y) {
  x += y;
  if (x >= MOD) return x - MOD;
  return x;
}
long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) return x + MOD;
  return x;
}
long long mult(long long x, long long y) { return (x * y) % MOD; }
const int N = 3030;
long long dp[N][N];
long long rev[N];
vector<int> g[N];
int p[N];
int n;
int main() {
  long long P;
  rev[1] = 1;
  for (long long x = 2; x < N; x++)
    rev[x] = sub(0, mult(MOD / x, rev[MOD % x]));
  scanf("%d%lld", &n, &P);
  for (int i = 1; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= n; j++) dp[i][j] = 1;
  for (int v = n - 1; v >= 0; v--) {
    dp[v][0] = 0;
    for (int i = 1; i <= n; i++) dp[v][i] = add(dp[v][i], dp[v][i - 1]);
    if (v == 0) break;
    for (int i = 0; i <= n; i++) dp[p[v]][i] = mult(dp[p[v]][i], dp[v][i]);
  }
  long long ANS = 0;
  for (int i = 0; i <= n; i++) {
    long long ans = dp[0][i];
    for (int j = 0; j <= n; j++) {
      if (j == i) continue;
      ans = mult(ans, sub(P, j));
      ans = mult(ans, rev[abs(i - j)]);
      if (i < j) ans = sub(0, ans);
    }
    ANS = add(ANS, ans);
  }
  printf("%lld\n", ANS);
  return 0;
}
