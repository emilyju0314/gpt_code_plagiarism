#include <bits/stdc++.h>
using namespace std;
long long mem[1010][1010], mod = 1000000007;
int main() {
  for (long long i = 0; i <= 1000; i++) {
    mem[i][0] = 1;
    mem[i][i] = 1;
    for (long long j = 1; j <= i - 1; j++)
      mem[i][j] = (mem[i - 1][j] + mem[i - 1][j - 1]) % mod;
  }
  long long n, m, k;
  scanf("%lld %lld %lld", &n, &m, &k);
  n -= 2, m -= 2;
  k--;
  if (n <= 2 * k || m <= 2 * k) {
    printf("0\n");
    return 0;
  }
  long long x = 0, y = 0, s = k + 1, e = n - k;
  for (long long i = s; i <= e; i++)
    for (long long j = i; j <= e; j++)
      x = (x + (mem[i - 1][k] * mem[n - j][k]) % mod) % mod;
  e = m - k;
  for (long long i = s; i <= e; i++)
    for (long long j = i; j <= e; j++)
      y = (y + (mem[i - 1][k] * mem[m - j][k]) % mod) % mod;
  printf("%lld\n", (x * y) % mod);
  return 0;
}
