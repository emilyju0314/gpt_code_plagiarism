#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
int n, m;
char s[MAXN];
void load() {
  scanf("%d%d", &n, &m);
  scanf("%s", s);
}
const int K = 20;
int a[K][K];
long long dp[1 << K];
long long precomp[1 << K][K];
long long precomp1[1 << K];
const long long inf = 4e18;
void solve() {
  for (int i = 0; i < n - 1; i++) {
    int x = s[i] - 'a';
    int y = s[i + 1] - 'a';
    a[x][y]++;
    a[y][x]++;
  }
  for (int mask = 0; mask < (1 << m); mask++) {
    int tko = -1;
    for (int i = 0; i < m; i++)
      if (mask & (1 << i)) {
        tko = i;
        break;
      }
    long long sum = 0;
    for (int i = 0; i < m; i++)
      if (!(mask & (1 << i))) {
        if (!mask)
          precomp[mask][i] = 0;
        else {
          precomp[mask][i] = precomp[mask ^ (1 << tko)][i] + a[i][tko];
        }
        sum += precomp[mask][i];
      }
    precomp1[mask] = sum;
  }
  fill(dp, dp + (1 << m), inf);
  dp[0] = 0;
  for (int mask = 0; mask < (1 << m); mask++) {
    for (int i = 0; i < m; i++) {
      if (mask & (1 << i)) continue;
      dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask] + precomp1[mask]);
    }
  }
  printf("%lld\n", dp[(1 << m) - 1]);
}
int main() {
  load();
  solve();
  return 0;
}
