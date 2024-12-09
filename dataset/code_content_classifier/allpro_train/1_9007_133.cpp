#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long a[1000005], b[1000005];
int main() {
  int n;
  scanf("%d", &n);
  b[0] = 1;
  for (int i = 1; i <= n; i++) {
    b[i] = b[i - 1] * 2 % mod;
    scanf("%lld", &a[i]);
  }
  long long sum = a[n];
  for (int i = 1; i < n; i++) {
    long long tmp = b[i - 1] * (i + 2) % mod;
    sum += tmp * a[n - i] % mod;
  }
  printf("%lld\n", sum % mod);
  return 0;
}
