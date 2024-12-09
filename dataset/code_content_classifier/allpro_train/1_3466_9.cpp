#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long gcd(long long a, long long b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
int main() {
  while (cin >> n >> m >> k) {
    long long h, w;
    long long g;
    if ((m * n * 2) % k != 0)
      puts("NO");
    else {
      puts("YES");
      puts("0 0");
      h = m, w = n;
      if (k % 2 == 0) {
        k /= 2;
        g = gcd(k, h);
        h /= g;
        k /= g;
        g = gcd(k, w);
        w /= g;
      } else {
        g = gcd(k, m);
        if (g > 1) {
          k /= g;
          h = h / g * 2;
          g = gcd(k, n);
          w /= g;
        } else {
          g = gcd(k, n);
          w = w / g * 2;
        }
      }
      printf("0 %lld\n", h);
      printf("%lld 0\n", w);
    }
  }
  return 0;
}
