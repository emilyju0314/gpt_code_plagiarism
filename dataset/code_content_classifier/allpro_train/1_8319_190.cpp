#include <bits/stdc++.h>
int n, i;
void zz(int x, int y) {
  printf("%d %d\n", x, y);
  if (!--n) exit(0);
}
int main() {
  std::cin >> n;
  zz(0, 0);
  while (++i) {
    zz(i, 0);
    zz(0, i);
    zz(-i, 0);
    zz(0, -i);
  }
}
