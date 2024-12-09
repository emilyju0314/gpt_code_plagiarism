#include <bits/stdc++.h>
int main() {
  int i, n, a, count = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a);
    if (a == 1) count++;
  }
  if (count >= 1) {
    printf("HARD\n");
  } else
    printf("EASY\n");
  return 0;
}
