#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m, x, y;
double f[N][N], a[N][N];
inline void gauss() {
  for (int i = 1; i <= m - 1; i++) {
    double r = a[i][i];
    a[i][i] /= r, a[i][i + 1] /= r, a[i][m + 1] /= r;
    double t = a[i + 1][i];
    a[i + 1][i] = 0;
    a[i + 1][i + 1] -= a[i][i + 1] * t;
    a[i + 1][m + 1] -= a[i][m + 1] * t;
  }
  a[m][m + 1] /= a[m][m], a[m][m] = 1;
  for (int i = m; i >= 2; i--)
    a[i - 1][m + 1] -= a[i][m + 1] * a[i - 1][i], a[i - 1][i] = 0;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &x, &y);
  if (m == 1)
    printf("%.4lf", 2.0 * (n - x));
  else {
    for (int i = n - 1; i >= x; i--) {
      a[1][1] = a[m][m] = 2.0 / 3;
      a[1][2] = a[m][m - 1] = -1.0 / 3;
      a[1][m + 1] = 1 + f[i + 1][1] / 3;
      a[m][m + 1] = 1 + f[i + 1][m] / 3;
      for (int j = 2; j <= m - 1; j++) {
        a[j][j - 1] = a[j][j + 1] = -1.0 / 4;
        a[j][j] = 3.0 / 4;
        a[j][m + 1] = 1 + f[i + 1][j] / 4;
      }
      gauss();
      for (int j = 1; j <= m; j++) f[i][j] = a[j][m + 1];
    }
    printf("%.4lf", f[x][y]);
  }
  return 0;
}
