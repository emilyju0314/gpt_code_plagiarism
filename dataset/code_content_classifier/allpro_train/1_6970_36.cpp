#include <bits/stdc++.h>
using namespace std;
int A[300005], R[300005][22], gom[300005], n, w, i, j, l, m, r, lg, x, y, mx;
long long asd;
int main() {
  scanf("%d%d", &n, &w);
  for (i = 1; i <= n; i++) {
    scanf("%d", &x);
    A[x] = i;
  }
  for (j = 1; j <= n; j++) {
    R[j][0] = -1000000009;
    gom[j] = log2(j);
  }
  while (w--) {
    scanf("%d%d", &x, &y);
    mx = max(A[x], A[y]);
    R[mx][0] = max(R[mx][0], min(A[x], A[y]));
  }
  for (i = 1; i < 21; i++)
    for (j = 1; j <= n; j++)
      if (j - (1 << (i - 1)) > 0)
        R[j][i] = max(R[j][i - 1], R[max(0, j - (1 << (i - 1)))][i - 1]);
  for (i = 1; i <= n; i++) {
    l = i;
    r = n + 1;
    while (l + 1 < r) {
      m = l + r >> 1;
      lg = gom[m - i + 1];
      if (max(R[m][lg], R[i + (1 << lg) - 1][lg]) >= i)
        r = m;
      else
        l = m;
    }
    if (R[l][0] >= i) l--;
    asd += l - i + 1;
  }
  printf("%lld\n", asd);
  return 0;
}
