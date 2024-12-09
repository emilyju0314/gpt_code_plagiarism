#include <bits/stdc++.h>
int main(int argc, char *argv[]) {
  int a1, a2, a3, x;
  scanf("%d%d%d", &a1, &a2, &a3);
  x = a2;
  --a3;
  while (a3--) {
    x = a1 + a2;
    a1 = a2;
    a2 = x;
  }
  printf("%d\n", x);
  return 0;
}
