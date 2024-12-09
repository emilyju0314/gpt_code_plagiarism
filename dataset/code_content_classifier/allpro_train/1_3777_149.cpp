#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int fi(long long int n) {
  long long int total = 1;
  long long int deg;
  for (long long int p = 2; p * p <= n; p++) {
    if (n % p == 0) {
      deg = p;
      while (n % p == 0) {
        n = n / p;
        deg = deg * p;
      }
      deg = deg / p;
      total = total * (deg - deg / p);
    }
  }
  if (n != 1) total = total * (n - 1);
  return total;
}
int main() {
  long long int n, k;
  scanf("%lld %lld", &n, &k);
  long long int res = n;
  k = (k + 1) / 2;
  while (k > 0) {
    res = fi(res);
    if (res == 1) {
      break;
    }
    k--;
  }
  printf("%lld", res % mod);
  return 0;
}
