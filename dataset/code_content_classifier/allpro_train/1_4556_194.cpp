#include <bits/stdc++.h>
int a[101];
int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int main() {
  int n, k;
  scanf("%d", &n);
  for (k = 0; k < n; k++) {
    scanf("%d", &a[k]);
  }
  qsort(a, n, sizeof(n), compare);
  if (a[0] == a[n / 2 - 1] && a[n / 2] == a[n - 1] && a[0] != a[n / 2]) {
    printf("yes\n");
    printf("%d %d", a[0], a[n / 2]);
  } else {
    printf("no");
  }
}
