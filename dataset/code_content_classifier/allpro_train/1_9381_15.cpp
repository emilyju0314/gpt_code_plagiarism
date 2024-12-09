#include <bits/stdc++.h>
int dizi[100015];
int main() {
  int i, m, n, fark, k, j;
  scanf("%d %d %d %d", &m, &n, &k, &j);
  for (i = 1;; i++) {
    j = (j * m + n) % k;
    if (dizi[j]) {
      printf("%d", i - dizi[j]);
      break;
    }
    dizi[j] = i;
  }
  return 0;
}
