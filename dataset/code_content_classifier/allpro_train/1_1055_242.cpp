#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[100100], m, n, ans;
  a[1] = 1, a[2] = 2;
  for (int i = 3; i <= 100000; i++) a[i] = (a[i - 2] + a[i - 1]) % (1000000007);
  scanf("%lld%lld", &n, &m);
  ans = (a[m] * 2 + a[n] * 2 - 2) % 1000000007;
  ans %= 1000000007;
  printf("%lld\n", ans);
  return 0;
}
