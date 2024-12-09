#include <bits/stdc++.h>
int main() {
  int a[100005], b[100005], n, m, c, i, j, buff;
  scanf("%d%d%d", &n, &m, &c);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }
  for (i = 1; i < m; i++) {
    b[i] += b[i - 1];
    b[i] %= c;
  }
  buff = n - m + 1;
  for (i = 0; i < n; i++) {
    if (i >= m) {
      a[i] += b[m - 1];
    } else {
      a[i] += b[i];
    }
    j = i - buff;
    a[i] %= c;
    if (j >= 0) {
      a[i] -= b[j];
    }
    a[i] = (a[i] + c) % c;
  }
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  putchar(10);
  return 0;
}
