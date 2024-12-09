#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, MAX = 1e9;
int n;
long long k, sum[N], a[N];
inline long long min(long long x, long long y) { return x < y ? x : y; }
inline long long max(long long x, long long y) { return x > y ? x : y; }
inline long long proper_floor(long long x, long long y) {
  long long ret = x / y;
  if (ret * y <= x) return ret;
  ret--;
  return ret;
}
inline void work() {
  scanf("%d%lld", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  sort(a, a + n);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i - 1];
  long long ans = 1e16;
  for (int i = 0; i < n; i++) {
    long long x, now = k;
    now -= sum[n - i] - sum[1];
    x = a[0] - proper_floor(now, i + 1);
    ans = min(ans, i + max(0ll, x));
  }
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) work();
  return 0;
}
