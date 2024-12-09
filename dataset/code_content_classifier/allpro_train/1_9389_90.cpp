#include <bits/stdc++.h>
int a[300020];
int l[300020];
int main() {
  int n;
  int all = 0, i, j, len = -1;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  i = 0;
  while (i < n) {
    int ll = i - 1, rr = i + 1;
    while (ll >= 0) {
      if (a[ll] % a[i] == 0) {
        ll--;
      } else
        break;
    }
    while (rr < n && a[rr] % a[i] == 0) rr++;
    rr--;
    ll++;
    if (rr - ll > len) {
      len = rr - ll;
      all = 1;
      l[0] = ll + 1;
    } else if (rr - ll == len) {
      l[all] = ll + 1;
      all++;
    }
    i = rr + 1;
  }
  printf("%d %d\n", all, len);
  for (i = 0; i < all; i++) {
    if (i > 0) printf(" ");
    printf("%d", l[i]);
  }
  printf("\n");
  return 0;
}
