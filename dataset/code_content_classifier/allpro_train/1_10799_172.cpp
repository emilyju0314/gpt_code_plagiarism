#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N], b[N][N], c[N][N];
int q, L, R, n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n; ++i) b[i][i] = c[i][i] = a[i];
  for (int l = 1; l <= n - 1; ++l)
    for (int i = 1; i <= n - l; ++i)
      b[i][i + l] = b[i][i + l - 1] ^ b[i + 1][i + l],
               c[i][i + l] =
                   max(max(c[i][i + l - 1], c[i + 1][i + l]), b[i][i + l]);
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d", &L, &R);
    printf("%d\n", c[L][R]);
  }
  return 0;
}
