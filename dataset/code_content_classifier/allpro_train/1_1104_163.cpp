#include <bits/stdc++.h>
using namespace std;
int gcf(int a, int b) {
  if (a == 0) return b;
  return gcf(b % a, a);
}
int main() {
  int y, w, d;
  scanf("%d%d", &y, &w);
  d = 7 - max(y, w);
  printf("%d/%d", d / gcf(d, 6), 6 / gcf(d, 6));
  return 0;
}
