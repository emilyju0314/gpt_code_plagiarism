#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, a, b, c, num = 0;
  scanf("%d%d", &x, &y);
  a = b = c = y;
  while (a < x || b < x || c < x) {
    if (a <= b && a <= c)
      a = b + c - 1;
    else if (b <= a && b <= c)
      b = a + c - 1;
    else
      c = a + b - 1;
    num++;
  }
  printf("%d", num);
}
