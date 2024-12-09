#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20000007;
long long a[107];
long long seg[MAXN];
int ceil(long long n, long long r) { return (n + r - 1) / r; }
int main() {
  int n, sz = 0;
  long long k, C = 0;
  while (scanf("%lld %lld", &n, &k) != EOF) {
    C = k;
    for (int i = 0; i < n; ++i) {
      scanf("%lld", a + i);
      for (long long j = 1; j * j <= a[i]; ++j)
        seg[sz++] = j, seg[sz++] = ceil(a[i], j);
      C += a[i];
    }
    sort(seg, seg + sz);
    sz = unique(seg, seg + sz) - seg;
    long long ans = 0;
    for (int i = 0; i < sz; ++i) {
      long long sum = 0;
      long long l = seg[i];
      for (int j = 0; j < n; ++j) {
        sum += ceil(a[j], l);
      }
      long long d = C / sum;
      if (d >= l && d > ans) ans = d;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
