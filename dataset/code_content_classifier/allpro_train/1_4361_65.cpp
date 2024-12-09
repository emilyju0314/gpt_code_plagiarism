#include <bits/stdc++.h>
using namespace std;
struct pt {
  int x, y;
} pn[200000], m[3000000];
pt symmetric(pt l, pt m) {
  pt m1;
  m1.x = 2 * l.x - m.x;
  m1.y = 2 * l.y - m.y;
  return m1;
}
int main() {
  long long int i, j, n;
  scanf("%I64d%I64d", &n, &j);
  scanf("%d%d", &m[0].x, &m[0].y);
  for (i = 0; i < n; i++) scanf("%d%d", &pn[i].x, &pn[i].y);
  for (i = 1; i < 2 * n; i++) {
    m[i] = symmetric(pn[(i - 1) % n], m[i - 1]);
  }
  printf("%d %d\n", m[j % (2 * n)].x, m[j % (2 * n)].y);
}
