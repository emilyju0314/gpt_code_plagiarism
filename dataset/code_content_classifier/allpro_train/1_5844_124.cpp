#include <bits/stdc++.h>
int main() {
  int n, i, j;
  int a[101];
  long long int parts = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i]) {
      parts = 1;
    }
  }
  for (i = 0; i < n; ++i) {
    if (a[i]) {
      for (j = i + 1; j < n; ++j) {
        if (a[j]) {
          parts *= j - i;
          i = j - 1;
          break;
        }
      }
    }
  }
  printf("%lld\n", parts);
  return 0;
}
