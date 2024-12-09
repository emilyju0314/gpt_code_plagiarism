#include <bits/stdc++.h>
long long solve(long long a, long long b) {
  if (b - a >= 10) return 0;
  long long res = 1;
  for (long long i = a + 1; i <= b; i++) {
    res *= (i % 10);
    res %= 10;
  }
  return res;
}
int main() {
  long long a, b;
  scanf("%I64d%I64d", &a, &b);
  printf("%I64d\n", solve(a, b));
  return 0;
}
