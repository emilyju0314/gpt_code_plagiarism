#include <bits/stdc++.h>
using namespace std;
mt19937 mt_rand(time(0));
const int N = 1e5 + 5;
int n;
long long k, sub[N], a[N];
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  sort(a + 1, a + n + 1);
  for (int i = 2; i <= n; i++) {
    sub[i - 1] = (a[i] - a[i - 1]) * (long long)(i - 1);
  }
  for (int i = n - 1; i > 0; i--) {
    sub[n - i] += (a[i + 1] - a[i]) * (long long)(n - i);
  }
  long long ans = a[n] - a[1];
  int wsk = 1;
  while (k) {
    if (sub[wsk] <= k) {
      k -= sub[wsk];
      ans -= sub[wsk] / wsk;
    } else {
      ans -= k / wsk;
      k = 0;
    }
    wsk++;
  }
  ans = max(ans, 0LL);
  printf("%lld", ans);
  return 0;
}
