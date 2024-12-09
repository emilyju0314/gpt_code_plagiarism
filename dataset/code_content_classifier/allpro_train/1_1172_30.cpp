#include <bits/stdc++.h>
using namespace std;
long long gcd(long long u, long long v) {
  while (v != 0) {
    long long r = u % v;
    u = v;
    v = r;
  }
  return u;
}
int main() {
  int t = 1;
  while (t--) {
    long long l, r;
    scanf("%lld", &l);
    scanf("%lld", &r);
    for (long long i = (l); i < (r + 1); i++) {
      for (long long j = (i + 1); j < (r + 1); j++) {
        for (long long k = (j + 1); k < (r + 1); k++) {
          if ((gcd(i, j) == 1) && (gcd(j, k) == 1) && (gcd(i, k) != 1)) {
            printf("%lld", i);
            printf("%c", ' ');
            printf("%lld", j);
            printf("%c", ' ');
            printf("%lld", k);
            return 0;
          }
        }
      }
    }
    printf("%d", -1);
  }
  return 0;
}
