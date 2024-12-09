#include <bits/stdc++.h>
using namespace std;
long long a[100010], b[100010];
int main() {
  long long n;
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    long long x;
    scanf("%lld", &x);
    a[i] = b[i] = x;
  }
  sort(b + 1, b + n + 1);
  for (long long i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    b[i] += b[i - 1];
  }
  long long m;
  scanf("%lld", &m);
  while (m--) {
    long long t, x, y;
    scanf("%lld %lld %lld", &t, &x, &y);
    if (t == 1) {
      printf("%lld\n", a[y] - a[x - 1]);
    } else {
      printf("%lld\n", b[y] - b[x - 1]);
    }
  }
  return 0;
}
