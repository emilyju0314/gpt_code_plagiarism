#include <bits/stdc++.h>
using namespace std;
int n, m, f[1000005][5][3], t[1000005], tmp, ans;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &tmp), t[tmp]++;
  memset(f, -1, sizeof(f));
  f[0][0][0] = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 0; j <= 4; j++)
      for (int k = 0; k <= 2; k++) {
        if (f[i - 1][j][k] < 0) continue;
        for (int l = 0; l <= min(j, k) && l <= t[i]; l++) {
          int y = t[i] - l, z = y % 3;
          f[i][z][min(j - l, 2)] =
              max(f[i][z][min(j - l, 2)], f[i - 1][j][k] + l + (y - z) / 3);
          if (y >= z + 3)
            f[i][min(z + 3, 4)][min(j - l, 2)] =
                max(f[i][min(z + 3, 4)][min(j - l, 2)],
                    f[i - 1][j][k] + l + (y - z) / 3 - 1);
        }
      }
  for (int i = 0; i <= 4; i++)
    for (int j = 0; j <= 2; j++) ans = max(ans, f[m][i][j]);
  printf("%d", ans);
  return 0;
}
