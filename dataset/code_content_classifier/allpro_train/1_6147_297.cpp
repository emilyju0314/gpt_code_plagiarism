#include <bits/stdc++.h>
long long n, b[200000 + 5], a[200000 + 5], pos = 1, flag = true, mks;
void clean() {}
int solve() {
  clean();
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &b[i]);
    if (b[pos] < b[i]) pos = i;
    if (i != 1 && b[i] != b[i - 1]) flag = false;
  }
  if (flag && b[1] > 0) return printf("NO\n"), 0;
  mks = b[pos];
  for (long long i = 1; i <= n; i++) {
    long long now;
    if (i - 1 <= 0)
      now = n;
    else
      now = i - 1;
    if (b[i] != b[now] && b[i] == mks) {
      pos = i;
      break;
    }
  }
  a[pos] = b[pos];
  if (a[pos] == 0) {
    printf("YES\n");
    for (long long i = 1; i <= n; i++) printf("%lld ", 19260817ll);
    return 0;
  }
  long long cnt = 1, f = 0;
  while (cnt <= n - 1) {
    long long now;
    if (pos - 1 <= 0)
      now = n;
    else
      now = pos - 1;
    a[now] = a[pos] + b[now];
    long long gg;
    if (now - 1 <= 0)
      gg = n;
    else
      gg = now - 1;
    if (b[now] == 0 && b[gg] == mks && !f) a[now] *= 2ll, f = 1;
    cnt++, pos = now;
  }
  printf("YES\n");
  for (long long i = 1; i <= n; i++) printf("%lld ", a[i]);
  return 0;
}
int main() {
  scanf("%lld", &n), solve();
  return 0;
}
