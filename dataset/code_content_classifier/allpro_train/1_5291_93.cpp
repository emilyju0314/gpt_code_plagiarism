#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 3, MX = 20, MOD = 1e9 + 7;
int dp[MAX][MX][3], n, pot2[MX];
void precalc() {
  pot2[0] = 1;
  for (int i = 1; i < MX; i++) pot2[i] = pot2[i - 1] * 2;
}
long long calc(int x, int y) {
  long long tmp = 1ll;
  if (y) tmp = 3;
  return n / tmp / pot2[x];
}
int main() {
  precalc();
  scanf("%d", &n);
  int m = n, log = 0;
  while (m / 2) m /= 2, log++;
  dp[1][log][0] = 1;
  if (pot2[log - 1] * 3ll <= n) dp[1][log - 1][1] = 1;
  for (int k = 2; k <= n; k++) {
    for (int i = log; i >= 0; i--) {
      for (int j = 1; j >= 0; j--) {
        dp[k][i][j] = (dp[k][i][j] +
                       1ll * dp[k - 1][i][j] * max(calc(i, j) - k + 1, 0ll)) %
                      MOD;
        if (i + 1 <= log)
          dp[k][i][j] = (dp[k][i][j] + 1ll * dp[k - 1][i + 1][j] *
                                           (calc(i, j) - calc(i + 1, j))) %
                        MOD;
        if (j + 1 < 2)
          dp[k][i][j] = (dp[k][i][j] + 1ll * dp[k - 1][i][j + 1] *
                                           (calc(i, j) - calc(i, j + 1))) %
                        MOD;
      }
    }
  }
  printf("%d\n", dp[n][0][0]);
  return 0;
}
