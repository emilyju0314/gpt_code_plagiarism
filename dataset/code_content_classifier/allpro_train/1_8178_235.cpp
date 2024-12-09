#include <bits/stdc++.h>
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if (m == 1)
    printf("%.10f\n", (double)1 / n);
  else
    printf("%.10f\n", (double)(2 * n * m - n - m) / ((n * m - 1) * n));
  return 0;
}
