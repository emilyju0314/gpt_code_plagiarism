#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, j, k, n;
  scanf("%d", &t);
  int s1 = 1023, s2 = 0, d;
  char c;
  while (t--) {
    getchar();
    scanf("%c%d", &c, &d);
    if (c == '|') {
      s1 |= d;
      s2 |= d;
    } else if (c == '&') {
      s1 &= d;
      s2 &= d;
    } else {
      s1 ^= d;
      s2 ^= d;
    }
  }
  int a1 = 0, a2 = 0, cc = 1;
  for (i = 0; i < 10; i++) {
    int x, y;
    x = s1 % 2;
    y = s2 % 2;
    s1 /= 2;
    s2 /= 2;
    if (x == 1 && y == 1) {
      a1 += cc;
    } else if (x == 0 && y == 0) {
      a1 += cc;
      a2 += cc;
    } else if (x == 0 && y == 1) {
      a2 += cc;
    }
    cc *= 2;
  }
  printf("2\n");
  printf("| %d\n", a1);
  printf("^ %d\n", a2);
  return 0;
}
