#include <bits/stdc++.h>
int a[200001];
int main() {
  int i, j = 0, n, sum = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  for (i = 1; i <= n; i++) {
    j += a[i];
    if (j * 2 >= sum) {
      printf("%d", i);
      break;
    }
  }
  return 0;
}
