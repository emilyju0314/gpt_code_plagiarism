#include <bits/stdc++.h>
long long n, ans;
int main() {
  scanf("%I64d", &n);
  while (n % 3 == 0) {
    n = n / 3;
  }
  ans = 1 + (n / 3);
  printf("%I64d", ans);
}
