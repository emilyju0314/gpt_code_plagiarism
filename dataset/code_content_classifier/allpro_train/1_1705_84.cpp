#include <bits/stdc++.h>
using namespace std;
const int nmax = 100000;
const int INF = 0x3f3f3f3f;
long long n, m, k;
int main() {
  while (scanf("%I64d %I64d %I64d", &n, &m, &k) != EOF) {
    k %= n * m;
    if (k <= (n - 1))
      printf("%I64d 1\n", k + 1);
    else {
      k -= (n - 1);
      long long which = ((k - 1) / (m - 1)) % 2;
      long long f = (k - 1) / (m - 1);
      long long remain = (k - 1) % (m - 1);
      if (which == 0) {
        printf("%I64d %I64d\n", n - f, 1 + remain + 1);
      } else {
        printf("%I64d %I64d\n", n - f, m - 1 - remain + 1);
      }
    }
  }
  return 0;
}
