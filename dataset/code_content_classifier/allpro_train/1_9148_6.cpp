#include <bits/stdc++.h>
long long n, max, num, ans;
long long div(long long x) {
  for (long long i = 0, sum = 9, bex = 9;; i++, bex *= 10, sum += bex) {
    num = bex / 9;
    if (sum > x) return sum / 10;
  }
}
long long cmd(long long x, long long y) { return (y - x) / 2 + 1; }
long long solve(long long x) {
  if (n + n - 1 < x) return 0;
  if (n >= x - 1) return cmd(1, x - 1);
  return cmd(x - n, n);
}
int main(void) {
  scanf("%lld", &n);
  max = div(n * 2 - 1);
  if (max == 0) {
    for (long long i = 1; i < n; i++) ans += i;
    printf("%lld", ans);
    return 0;
  }
  for (long long i = 0; i < 10; i++) {
    ans += solve(i * num + max);
  }
  printf("%lld", ans);
}
