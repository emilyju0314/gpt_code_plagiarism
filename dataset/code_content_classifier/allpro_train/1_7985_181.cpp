#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    unsigned int a, b, c, d;
    scanf("%u %u %u %u", &a, &b, &c, &d);
    if (a <= b)
      printf("%u\n", b);
    else if (c <= d)
      printf("-1\n");
    else {
      unsigned long long f =
          (a - b) % (c - d) == 0 ? (a - b) / (c - d) : ((a - b) / (c - d) + 1);
      unsigned long long g = b + c * f;
      printf("%llu\n", g);
    }
  }
  return 0;
}
