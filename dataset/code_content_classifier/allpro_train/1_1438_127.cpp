#include <bits/stdc++.h>
using namespace std;
long long p[3000010];
long long k[3000010];
long long ans = 0;
int main() {
  long long n, m;
  scanf("%I64d", &n);
  for (long long i = 1; i <= 3000000; i++) {
    k[i] = 0;
    p[i] = 0;
  }
  for (long long i = 1; i <= n; i++) {
    long long a;
    scanf("%I64d", &a);
    k[a]++;
  }
  for (long long i = 1; i <= 3000000; i++) {
    if (k[i]) {
      for (long long j = i; j <= 3000000; j += i) {
        long long d = j / i;
        p[j] += k[i] * k[d];
        if (i == d) p[j] -= k[i];
      }
    }
  }
  for (long long i = 2; i <= 3000000; i++) p[i] += p[i - 1];
  scanf("%I64d", &m);
  long long sum = n * (n - 1);
  for (long long i = 1; i <= m; i++) {
    long long t;
    scanf("%I64d", &t);
    long long ans = sum - p[t - 1];
    printf("%I64d\n", ans);
  }
  return 0;
}
