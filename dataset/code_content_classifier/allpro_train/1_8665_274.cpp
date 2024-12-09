#include <bits/stdc++.h>
int main() {
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  if (((x == n / 2) && (y == n / 2)) || ((x == (n / 2 + 1)) && (y == n / 2)) ||
      ((x == n / 2) && (y == (n / 2 + 1))) ||
      ((x == (n / 2 + 1)) && (y == (n / 2 + 1)))) {
    printf("NO");
  } else {
    printf("YES");
  }
}
