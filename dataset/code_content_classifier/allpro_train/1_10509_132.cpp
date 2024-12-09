#include <bits/stdc++.h>
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int main() {
  int n, k, i, j, a[100010], sum, t, min;
  while (scanf("%d%d", &n, &k) != EOF) {
    sum = 0;
    t = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(a[0]), cmp);
    i = 0;
    while (k && i < n && a[i] < 0) {
      a[i] = -a[i];
      i++;
      k--;
    }
    for (i = 0, min = a[0]; i < n; i++) {
      sum += a[i];
      if (a[i] < min) min = a[i];
    }
    if (k % 2 == 1)
      printf("%d\n", sum - 2 * min);
    else
      printf("%d\n", sum);
  }
  return 0;
}
