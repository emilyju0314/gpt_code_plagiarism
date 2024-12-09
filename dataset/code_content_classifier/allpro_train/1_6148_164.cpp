#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  if (n % 3 == 0) {
    printf("%d 1 1\n", n - 2);
  } else if (n % 3 != 0) {
    if (n % 3 == 1) {
      printf("%d 1 1\n", n - 2);
    } else if (n % 3 == 2) {
      printf("%d 2 1\n", n - 3);
    }
  }
}
