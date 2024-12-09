#include <bits/stdc++.h>
int main() {
  int k2, k3, k5, k6, min, max;
  scanf("%d %d %d %d", &k2, &k3, &k5, &k6);
  if (k2 < k5) {
    if (k2 < k6) {
      min = k2;
    } else
      min = k6;
  } else if (k5 < k6) {
    min = k5;
  } else
    min = k6;
  k2 = k2 - min;
  if (k2 < k3) {
    max = k2;
  } else
    max = k3;
  printf("%d", min * 256 + max * 32);
  return 0;
}
