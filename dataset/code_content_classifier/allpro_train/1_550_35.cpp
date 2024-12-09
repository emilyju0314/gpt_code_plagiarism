#include <bits/stdc++.h>
using namespace std;
int prime[100005];
long long mu[100005], cnt = 0, n, m, l, r, mod;
bool isprime[100005];
void init() {
  mu[1] = mu[0] = 1;
  for (int i = 2; i <= 100002; i++) {
    if (!isprime[i]) {
      mu[i] = -1;
      prime[++cnt] = i;
    }
    for (int p = 1; p <= cnt && i * prime[p] <= 100002; p++) {
      isprime[i * prime[p]] = 1;
      if (i % prime[p] == 0) {
        mu[i * prime[p]] = 0;
        break;
      }
      mu[i * prime[p]] = -mu[i];
    }
  }
}
long long solve(long long k, long long s) {
  if (s <= 0) return 0;
  long long o = sqrt(k), sum = 0, q;
  s = min(s, m);
  for (long long i = 1; i <= o; i++) {
    if (k % i == 0) {
      sum += mu[i] * (m * (s / i) - (s / i * i + i) * (s / i) / 2);
      sum %= mod;
      if (k / i != i) {
        q = k / i;
        sum += mu[q] * (m * (s / q) - (s / q * q + q) * (s / q) / 2);
        sum %= mod;
      }
    }
  }
  return sum;
}
int main() {
  init();
  scanf("%lld%lld%lld%lld%lld", &n, &m, &l, &r, &mod);
  n++;
  m++;
  long long ans = 0;
  if (l == 1) ans = ((m - 1) * n + (n - 1) * m) % mod;
  for (long long i = 1; i < n && i <= r; i++) {
    long long L, R;
    if (l * l >= i * i)
      L = sqrt(l * l - i * i);
    else
      L = 0;
    if (L * L == l * l - i * i) L--;
    R = sqrt(r * r - i * i);
    ans += (n - i) * (solve(i, R) - solve(i, L)) * 2, ans %= mod;
  }
  printf("%lld", (ans + mod) % mod);
  return 0;
}
