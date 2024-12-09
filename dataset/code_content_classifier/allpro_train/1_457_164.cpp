#include <bits/stdc++.h>
const int N = 101;
int n, p, i, j;
bool f[N][N];
int main() {
  scanf("%d", &n);
  for (p = 3; p * (p - 1) * (p - 2) / 6 <= n; p++)
    ;
  p--;
  n -= p * (p - 1) * (p - 2) / 6;
  for (i = 1; i <= p; i++)
    for (j = 1; j <= p; j++)
      if (i != j) f[i][j] = 1;
  for (i = p; i > 1; i--)
    if (i * (i - 1) / 2 <= n) {
      n -= i * (i - 1) / 2;
      p++;
      for (j = 1; j <= i; j++) f[p][j] = f[j][p] = 1;
      i++;
    }
  printf("%d\n", p);
  for (i = 1; i <= p; i++, puts(""))
    for (j = 1; j <= p; j++) printf("%d", f[i][j]);
}
