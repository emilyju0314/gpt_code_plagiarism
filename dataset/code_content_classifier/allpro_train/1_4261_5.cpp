#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, i, d;
    scanf("%d %d", &n, &d);
    int A[n];
    for (i = 0; i < n; i++) {
      scanf("%d", &A[i]);
    }
    while (d--) {
      for (i = 1; i < n; i++) {
        if (A[i] > 0) {
          A[i - 1]++;
          A[i]--;
          break;
        }
      }
    }
    printf("%d\n", A[0]);
  }
  return 0;
}
