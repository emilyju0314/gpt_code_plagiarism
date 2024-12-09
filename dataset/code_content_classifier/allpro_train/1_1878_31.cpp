#include <bits/stdc++.h>
using namespace std;
long long a[200005], b[200005];
long long f[200005];
long long n, q;
long long fun(long long x) {
  int l = 0, r = n;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (f[mid] == x)
      return mid;
    else if (f[mid] > x)
      r = mid - 1;
    else
      l = mid + 1;
  }
  if (f[l] > x) return l - 1;
  return l;
}
int main() {
  scanf("%lld%lld", &n, &q);
  long long sum = 0;
  f[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    f[i + 1] = sum;
  }
  long long pre = 0;
  long long ans = 0;
  for (int i = 0; i < q; i++) {
    cin >> b[i];
    pre += b[i];
    if (pre >= sum) {
      printf("%lld\n", n);
      pre = 0;
    } else
      printf("%lld\n", n - fun(pre));
  }
  return 0;
}
