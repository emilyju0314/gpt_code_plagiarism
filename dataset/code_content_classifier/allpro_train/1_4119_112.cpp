#include <bits/stdc++.h>
int odd = 1, even = 2;
int main() {
  int n;
  scanf("%d", &n);
  int i, j, mid = n / 2 + 1;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      int x;
      x = i;
      if (x > mid) x = mid - i + mid;
      if (x == mid) {
        printf("%d ", odd);
        odd += 2;
      } else if (j >= mid - (x - 1) && j < mid + (x)) {
        printf("%d ", odd);
        odd += 2;
      } else {
        printf("%d ", even);
        even += 2;
      }
    }
    printf("\n");
  }
  return 0;
}
