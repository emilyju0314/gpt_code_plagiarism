#include <bits/stdc++.h>
int main() {
  int a1, h1, c1;
  int a2, h2;
  long int i = 0, j = 0, e = 0;
  int a[10001] = {0};
  scanf("%d%d%d", &h1, &a1, &c1);
  scanf("%d%d", &h2, &a2);
  while (h2 > 0) {
    if (a2 >= h1 && a1 < h2) {
      h1 = h1 + c1;
      a[e] = 1;
    } else {
      h2 = h2 - a1;
    }
    h1 = h1 - a2;
    e++;
  }
  printf("%ld\n", e);
  for (i = 0; i < e; i++) {
    if (a[i] == 1) {
      printf("HEAL\n");
    } else {
      printf("STRIKE\n");
    }
  }
  return 0;
}
