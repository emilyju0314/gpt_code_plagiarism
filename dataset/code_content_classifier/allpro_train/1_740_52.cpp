#include <bits/stdc++.h>
int GCD(int n, int m) {
  int temp;
  if (n < m) {
    temp = m;
    m = n;
    n = temp;
  }
  if (n % m == 0)
    return m;
  else
    return GCD(m, n % m);
}
int main() {
  int n, m, z;
  while (scanf("%d %d %d", &n, &m, &z) != EOF) {
    int x = n / GCD(n, m) * m;
    printf("%d\n", z / x);
  }
  return 0;
}
