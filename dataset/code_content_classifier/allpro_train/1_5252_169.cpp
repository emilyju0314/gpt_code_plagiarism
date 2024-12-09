#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n;
long long x, y, ans;
bool comp[N];
vector<long long> primes;
long long add(long long a, long long b) { return (a + b) % MOD; }
long long mul(long long a, long long b) { return (a * b) % MOD; }
long long fastexp(long long a, long long b) {
  if (b == 0) return 1;
  long long x = fastexp(a, b >> 1);
  x = mul(x, x);
  if (b & 1) x = mul(x, a);
  return x;
}
int main() {
  scanf("%lld%lld", &x, &y);
  if (y % x != 0) {
    printf("0\n");
    return 0;
  }
  y /= x;
  comp[1] = 1;
  for (int i = 2; i * i <= N; i++) {
    if (comp[i]) continue;
    for (int j = i * i; j < N; j += i) {
      comp[j] = i;
    }
  }
  long long z = y;
  for (int i = 2; i < N; i++) {
    if (comp[i]) continue;
    if (z % i) continue;
    while (z % i == 0) {
      z /= i;
    }
    primes.push_back(i);
  }
  if (z > 1) primes.push_back(z);
  z = primes.size();
  for (int i = 0; i < (1 << z); i++) {
    long long a = 1, b = 0;
    for (int j = 0; j < z; j++) {
      if ((i >> j) & 1) {
        b++;
        a *= primes[j];
      }
    }
    a = y / a;
    if (b & 1) {
      ans = add(ans, MOD - fastexp(2, a - 1));
    } else {
      ans = add(ans, fastexp(2, a - 1));
    }
  }
  printf("%lld\n", ans);
}
