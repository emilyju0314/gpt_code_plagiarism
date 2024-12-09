#include <bits/stdc++.h>
int main(void) {
  int n = 0, c = 0;
  int minOdd = 0, sum = 0;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &c);
    sum += c;
    if (c % 2 != 0) {
      if (minOdd == 0 || minOdd > c) {
        minOdd = c;
      }
    }
  }
  if (sum % 2 == 0) {
    if (minOdd == 0) {
      sum = 0;
    } else {
      sum -= minOdd;
    }
  }
  printf("%d\n", sum);
  return 0;
}
