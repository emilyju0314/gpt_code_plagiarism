#include <bits/stdc++.h>
int main() {
  int n, k, i, j, t;
  while (scanf("%d%d", &n, &k) != EOF) {
    if (k > 1) {
      printf("1");
      for (t = 0, i = 2, j = n; t < k - 1; t++) {
        if (t % 2 == 0) {
          printf(" %d", j);
          j--;
        } else {
          printf(" %d", i);
          i++;
        }
      }
      if (k % 2 == 0) {
        for (; j >= i; j--) {
          printf(" %d", j);
        }
      } else {
        for (; i <= j; i++) {
          printf(" %d", i);
        }
      }
      printf("\n");
    } else {
      for (i = 1; i < n; i++) {
        printf("%d ", i);
      }
      printf("%d\n", n);
    }
  }
  return 0;
}
