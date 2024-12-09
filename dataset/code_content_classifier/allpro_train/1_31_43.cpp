#include <bits/stdc++.h>
int main() {
  int a, b, c, d, e, t = 0, r;
  scanf("%d%d", &a, &b);
  r = a;
  while (a >= b) {
    c = a / b;
    r = r + c;
    t = a % b;
    c = c + t;
    a = c;
  }
  printf("%d", r);
}
