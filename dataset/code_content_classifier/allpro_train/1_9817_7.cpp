#include <bits/stdc++.h>
void sort(int c, int A[], int B[]) {
  int i = 0, j = 0, t, t2;
  for (i = 1; i < c; i++) {
    j = i;
    t = A[j];
    t2 = B[j];
    while (t < A[j - 1] && j > 0) {
      B[j] = B[j - 1];
      A[j] = A[j - 1];
      --j;
    }
    A[j] = t;
    B[j] = t2;
  }
}
int main() {
  int n, t, x[1000], a[1000];
  int c = 2;
  scanf("%d %d", &n, &t);
  int k = 0;
  while (k < n) {
    scanf("%d %d", &x[k], &a[k]);
    k++;
  }
  sort(n, x, a);
  k = 0;
  while (k < n - 1) {
    if (t < ((x[k + 1] - x[k]) - (a[k] + a[k + 1]) / 2.0))
      c += 2;
    else if (t == ((x[k + 1] - x[k]) - (a[k] + a[k + 1]) / 2.0))
      ++c;
    k++;
  }
  printf("%d", c);
  return 0;
}
