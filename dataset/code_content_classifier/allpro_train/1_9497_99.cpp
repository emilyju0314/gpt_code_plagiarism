#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 5;
const int mod = 1000000007;
int mat[11][101][101];
int main() {
  int n, q, c, i, j, k;
  scanf("%d", &n);
  scanf("%d", &q);
  scanf("%d", &c);
  c++;
  for (i = 1; i <= n; i++) {
    int x, y, s;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &s);
    mat[s][x][y]++;
  }
  int x, y;
  for (x = 0; x <= c - 1; x++) {
    for (i = 1; i <= 100; i++) {
      for (j = 1; j <= 100; j++) {
        mat[x][i][j] +=
            (mat[x][i][j - 1] + mat[x][i - 1][j] - mat[x][i - 1][j - 1]);
      }
    }
  }
  int t, x2, y2;
  while (q--) {
    scanf("%d", &t);
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &x2);
    scanf("%d", &y2);
    long long ans = 0;
    for (i = 0; i <= c - 1; i++) {
      ans += ((i + t) % c) * (mat[i][x2][y2] + mat[i][x - 1][y - 1] -
                              mat[i][x - 1][y2] - mat[i][x2][y - 1]);
    }
    printf("%lld ", ans);
    printf("\n");
  }
  return 0;
}
