#include <bits/stdc++.h>
unsigned x1, x2, s;
unsigned F(unsigned p, unsigned d, unsigned k) {
  if (k == 2) return -1;
  if (!p && d == -1u) return F(p, -d, k);
  if (p == s && d == 1) return F(p, -d, k);
  if (k == 1 && p == x2) ++k;
  if (k == 0 && p == x1) ++k;
  return 1 + F(p + d, d, k);
}
int main() {
  unsigned t1, t2, p, d, a, b;
  scanf("%u%u%u%u%u%u%u", &s, &x1, &x2, &t1, &t2, &p, &d);
  a = F(p, d, 0) * t1;
  b = (x1 > x2 ? x1 - x2 : x2 - x1) * t2;
  printf("%u\n", a > b ? b : a);
  return 0;
}
