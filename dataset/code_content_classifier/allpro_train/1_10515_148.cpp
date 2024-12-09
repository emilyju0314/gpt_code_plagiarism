#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, m, x, y, z, p, a, b, ta, tb, nn, mm, temp;
  scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &z, &p);
  for (i = 1; i <= p; ++i) {
    scanf("%d%d", &a, &b);
    ta = a, tb = b;
    nn = n, mm = m;
    if (x % 4 == 1) {
      a = tb;
      b = nn + 1 - ta;
      temp = nn;
      nn = mm;
      mm = temp;
    }
    if (x % 4 == 2) {
      a = nn + 1 - ta;
      b = mm + 1 - tb;
    }
    if (x % 4 == 3) {
      b = ta;
      a = mm + 1 - tb;
      temp = nn;
      nn = mm;
      mm = temp;
    }
    ta = a, tb = b;
    if (y % 2 == 1) {
      a = ta;
      b = mm + 1 - tb;
    }
    ta = a;
    tb = b;
    if (z % 4 == 3) {
      a = tb;
      b = nn + 1 - ta;
    }
    if (z % 4 == 2) {
      a = nn + 1 - ta;
      b = mm + 1 - tb;
    }
    if (z % 4 == 1) {
      b = ta;
      a = mm + 1 - tb;
    }
    printf("%d %d\n", a, b);
  }
  return 0;
}
