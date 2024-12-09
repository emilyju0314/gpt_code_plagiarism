#include <bits/stdc++.h>
using namespace std;
const int MOD = 51123987LL;
const int ROWS = 2;
int pnext[1001][3];
int dp[ROWS][150][51][51];
int main() {
  int n;
  scanf("%d", &n);
  char str[1001];
  scanf("%s", str);
  for (int c = 0; c < 3; ++c) pnext[n][c] = n;
  for (int i = n - 1; i >= 0; --i) {
    for (int c = 0; c < 3; ++c) pnext[i][c] = pnext[i + 1][c];
    pnext[i][str[i] - 'a'] = i;
  }
  const int nlow = n / 3, nhigh = (n + 2) / 3;
  memset(dp[n % ROWS], 0, sizeof(dp[n % ROWS]));
  for (int da = 0; da < 2; ++da)
    for (int db = 0; db < 2; ++db)
      for (int dc = 0; dc < 2; ++dc)
        if (nlow * 3 + da + db + dc == n) {
          for (int p = 0; p < n; ++p) dp[n % ROWS][p][nlow + da][nlow + db] = 1;
        }
  for (int i = n - 1; i >= 0; --i) {
    const int me = i % ROWS, old = (i + 1) % ROWS, nnlow = nlow - (n - i);
    memset(dp[me], 0, sizeof(dp[me]));
    for (int p = 0; p < n; ++p)
      for (int na = max(0, nnlow); na <= min(i, nhigh); ++na)
        for (int nb = max(0, nnlow); nb <= min(i, nhigh); ++nb) {
          const int nc = i - na - nb;
          if (max(0, nnlow) <= nc && nc <= min(i, nhigh)) {
            int& count = dp[me][p][na][nb];
            if (pnext[p][0] < n && na < nhigh && nb > nnlow && nc > nnlow)
              count += dp[old][pnext[p][0]][na + 1][nb];
            if (pnext[p][1] < n && nb < nhigh && na > nnlow && nc > nnlow)
              count += dp[old][pnext[p][1]][na][nb + 1];
            if (pnext[p][2] < n && nc < nhigh && na > nnlow && nb > nnlow)
              count += dp[old][pnext[p][2]][na][nb];
            count %= MOD;
          }
        }
  }
  printf("%d\n", dp[0][0][0][0]);
  return 0;
}
