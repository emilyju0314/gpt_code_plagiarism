#include <bits/stdc++.h>
inline int read() {
  int x = 0;
  short w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return w ? -x : x;
}
int n;
int main() {
  n = read();
  int ans = 0;
  while (n) {
    if (n % 8 == 1) ++ans;
    n /= 8;
  }
  printf("%d\n", ans);
  return 0;
}
