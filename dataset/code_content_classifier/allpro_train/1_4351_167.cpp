#include <bits/stdc++.h>
int main() {
  int n, a, b;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a, &b);
    int j = a % b;
    if (j == 0)
      printf("0\n");
    else
      printf("%d\n", b - j);
  }
  return 0;
}
