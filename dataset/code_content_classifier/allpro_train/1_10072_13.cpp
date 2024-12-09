#include <bits/stdc++.h>
int main() {
  int a[1000] = {0}, max, d, i, j, k, n, arr[105][105] = {0}, m;
  char c;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      scanf(" %c", &c);
      arr[i][j] = c - '0';
    }
  for (i = 0; i < m; i++) {
    max = 0;
    for (j = 0; j < n; j++) {
      if (arr[j][i] > max) max = arr[j][i];
    }
    for (j = 0; j < n; j++)
      if (arr[j][i] == max) {
        a[j] = 1;
      }
  }
  int sayac = 0;
  for (i = 0; i < n; i++)
    if (a[i] == 1) {
      sayac++;
    }
  printf("%d", sayac);
  return 0;
}
