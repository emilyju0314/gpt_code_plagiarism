#include <bits/stdc++.h>
using namespace std;
int a[405][405];
int sum1[405][405], sum2[405][405];
int fun(int i, int j, int y) {
  return sum1[j - 1][y] - sum1[i][y] + !a[i][y] + !a[j][y];
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    memset(sum1, 0, sizeof(sum1));
    memset(sum2, 0, sizeof(sum2));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        char c;
        cin >> c;
        if (c == '1') {
          a[i][j] = 1;
        } else {
          a[i][j] = 0;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        sum1[i][j] = sum1[i - 1][j] + a[i][j];
        sum2[i][j] = sum2[i - 1][j] + !a[i][j];
      }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 4; j <= n; j++) {
        int sum = 0x3f3f3f3f;
        for (int k = 3; k < m; k++) {
          sum = min(fun(i, j, k - 1) + fun(i, j, k) + sum2[j - 1][k - 2] -
                        sum2[i][k - 2],
                    sum + sum1[j - 1][k] - sum1[i][k] + !a[j][k] + !a[i][k]);
          ans = min(ans, sum + sum2[j - 1][k + 1] - sum2[i][k + 1]);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
