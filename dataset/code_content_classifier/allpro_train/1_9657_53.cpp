#include <bits/stdc++.h>
int fun(int a, int b) {
  if (a == 1 || b == 1)
    return 1;
  else
    return fun(a - 1, b) + fun(a, b - 1);
}
int main() {
  int n;
  scanf("%d", &n);
  printf("%d", fun(n, n));
}
