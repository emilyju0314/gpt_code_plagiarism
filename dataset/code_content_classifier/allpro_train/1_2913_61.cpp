#include <bits/stdc++.h>
using namespace std;
long long n, k, A, B;
int main() {
  scanf("%lld%lld%lld%lld", &n, &k, &A, &B);
  long long ans = 0;
  while (n != 1) {
    if (n % k == 0) {
      if (A * (n - n / k) > B) {
        ans += B;
        n = n / k;
      } else {
        ans += A * (n - 1);
        break;
      }
    } else {
      ans += (n % k) * A;
      n -= n % k;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
