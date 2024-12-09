#include <bits/stdc++.h>
using namespace std;
const int MOD = 761238923;
const int maxn = 25;
const int maxm = 300;
const int INF = 1 << 25;
const int logN = 18;
char s[maxn][maxm];
int c[maxn][maxm], sv[maxn][maxm], a[maxn][maxm];
int dp[1111111];
int n, m;
int LB(int x) {
  for (int i = 0; i < n; ++i)
    if ((1 << i) & x) return i;
}
int main(int argc, char const *argv[]) {
  scanf("%d%d", &(n), &(m));
  for (int(i) = 0; i < (int)(n); ++(i)) scanf("%s", (s[i]));
  for (int(i) = 0; i < (int)(n); ++(i))
    for (int(j) = 0; j < (int)(m); ++(j)) scanf("%d", &(a[i][j]));
  for (int(i) = 0; i < (int)(n); ++(i))
    for (int(j) = 0; j < (int)(m); ++(j)) {
      int cv = 0;
      for (int(k) = 0; k < (int)(n); ++(k))
        if (s[i][j] == s[k][j]) {
          sv[i][j] |= (1 << k);
          c[i][j] += a[k][j];
          cv = max(cv, a[k][j]);
        }
      c[i][j] -= cv;
    }
  for (int i = 0; i < (1 << n); ++i) dp[i] = INF;
  dp[0] = 0;
  for (int i = 0; i < (1 << n); ++i) {
    if (i == 0) continue;
    int lb = LB(i);
    for (int j = 0; j < m; ++j) {
      dp[i] = min(dp[i], dp[i ^ (1 << lb)] + a[lb][j]);
      dp[i] = min(dp[i], dp[i & (i ^ sv[lb][j])] + c[lb][j]);
    }
  }
  printf("%d\n", (dp[(1 << n) - 1]));
  return 0;
}
