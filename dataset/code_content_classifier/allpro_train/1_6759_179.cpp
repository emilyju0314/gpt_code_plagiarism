#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    a--;
    printf("%lld\n", 9 * a + b);
  }
  return 0;
}
