#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
int n, k;
int a[N];
double bef[N][N], dp[N][N];
inline int C(int x) { return x * (x + 1) / 2; }
int main() {
  scanf("%d %d", &n, &k);
  k = k < 1000 ? k : 1000;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) bef[i][j] = 1;
  for (int rem = 1; rem <= k; rem++) {
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        dp[i][j] = bef[i][j] * (C(i - 1) + C(j - i - 1) + C(n - j));
        for (int lr = i + 1; lr <= i + (j - 1); lr++) {
          int x = 1 > lr - (j - 1) ? 1 : lr - (j - 1);
          int y = i < lr - i ? i : lr - i;
          dp[i][j] += bef[lr - i][j] * (y - x + 1);
        }
        for (int lr = (i + 1) + j; lr <= j + n; lr++) {
          int x = i + 1 > lr - n ? i + 1 : lr - n;
          int y = j < lr - j ? j : lr - j;
          dp[i][j] += bef[i][lr - j] * (y - x + 1);
        }
        for (int lr = j + 1; lr <= n + i; lr++) {
          int x = 1 > lr - n ? 1 : lr - n;
          int y = i < lr - j ? i : lr - j;
          dp[i][j] += (1 - bef[lr - j][lr - i]) * (y - x + 1);
        }
        dp[i][j] /= n * (n + 1) / 2;
      }
    }
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) bef[i][j] = dp[i][j];
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i] > a[j])
        ans += dp[i][j];
      else
        ans += 1 - dp[i][j];
    }
  }
  printf("%.12lf\n", ans);
  return 0;
}
