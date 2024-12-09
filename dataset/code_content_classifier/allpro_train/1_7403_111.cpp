#include <bits/stdc++.h>
int main() {
  int value, coun = 0, v, i, a, b, number[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  scanf("%d%d", &a, &b);
  v = a;
  do {
    coun += number[v % 10];
    v /= 10;
  } while (v > 0);
  value = coun;
  for (i = a + 1; i <= b; i++) {
    if (i % 10 != 0)
      value = value - number[(i - 1) % 10] + number[i % 10];
    else {
      v = i;
      while (v % 10 == 0) {
        value += number[0] - number[9];
        v /= 10;
      }
      value += number[v % 10] - (v - 1 > 0 ? number[(v - 1) % 10] : 0);
    }
    coun += value;
  }
  printf("%d", coun);
  return 0;
}
