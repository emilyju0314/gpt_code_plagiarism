#include <bits/stdc++.h>
int n, m, s;
int main() {
  scanf("%d %d %d", &n, &m, &s);
  long long a = ((n - 1) / s) + 1;
  long long b = ((m - 1) / s) + 1;
  long long c = ((n - 1) % s) + 1;
  long long d = ((m - 1) % s) + 1;
  printf("%I64d", a * b * c * d);
  return 0;
}
