#include <bits/stdc++.h>
using namespace std;
long long n, m, K, a[200005], sum, k;
double p;
signed main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  for (long long i = 1; i <= m; i++) scanf("%lld", &a[i]), sum += a[i];
  if (sum < n) {
    puts("-1");
    return 0;
  }
  p = 1.0;
  for (long long i = 1; sum - n + i <= sum - 1; i++) p /= 1.0 * (sum - n + i);
  for (long long i = 2; sum - a[k] - n + i <= sum - a[k]; i++)
    p *= 1.0 * (sum - a[k] - n + i);
  p = 1.0 - p;
  printf("%.8lf\n", p);
  return 0;
}
