#include <bits/stdc++.h>
int main() {
  long long r = 1e18, t;
  scanf("%I64d", &t);
  long long l = t - (9 * ((r * 9) % t)) % t;
  printf("%I64d %I64d\n", l, r + l - 1);
  return 0;
}
