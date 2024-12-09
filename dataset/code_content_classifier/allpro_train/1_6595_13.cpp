#include <bits/stdc++.h>
using namespace std;
int n, c[105];
double f[105][10005], C[105][105], x;
int main() {
  scanf("%d%lf", &n, &x);
  int sm = 0;
  f[0][0] = 1;
  for (int i = (1), LIM = (n); i <= LIM; i++) {
    scanf("%d", &c[i]);
    sm += c[i];
    for (int j = (i), LIM = (1); j >= LIM; j--)
      for (int k = (sm), LIM = (c[i]); k >= LIM; k--)
        f[j][k] = (f[j][k] + f[j - 1][k - c[i]]);
  }
  double ans = 0;
  for (int i = (C[0][0] = 1), LIM = (n); i <= LIM; i++)
    for (int j = (C[i][0] = 1), LIM = (i); j <= LIM; j++)
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  for (int i = (0), LIM = (n - 1); i <= LIM; i++)
    for (int k = (0), LIM = (sm); k <= LIM; k++)
      ans += f[i][k] / C[n][i] *
             min((sm - k) * 1.0 / (n - i), (1.0 * n / (n - i) + 1) * x / 2);
  printf("%.10lf\n", ans);
}
