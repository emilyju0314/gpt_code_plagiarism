#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;
template <class T>
T gcd(T a, T b) {
  if (!b) return a;
  return gcd(b, a % b);
}
const int maxn = 1e5 + 10;
long long n, m, a[maxn], sn, sn2, b[maxn];
int vis[maxn];
long long q_pow(long long n, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = (res * n) % m;
    n = (n * n) % m;
    k >>= 1;
  }
  return res;
}
inline long long inverse(long long a) { return q_pow(a, m - 2); }
int check(long long a1, long long d) {
  for (int i = 0; i < n; i++) b[i] = (a1 + i * d) % m;
  sort(b, b + n);
  for (int i = 0; i < n; i++)
    if (a[i] != b[i]) return 0;
  return 1;
}
int main() {
  scanf("%I64d%I64d", &m, &n);
  sn = sn2 = 0;
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &a[i]);
    sn += a[i];
    sn %= m;
    sn2 += a[i] * a[i];
    sn2 %= m;
  }
  if (n == 1) return 0 * printf("%d 0\n", a[0]);
  if (n == m) return 0 * printf("0 1\n");
  sort(a, a + n);
  long long d, a1, k1 = (n * (n - 1) / 2) % m,
                   k2 = (n * (n - 1) * (2 * n - 1) / 6) % m, inv = inverse(n);
  for (int i = 0; i < n; i++) {
    d = (a[i] - a[0] + m) % m;
    a1 = (sn - k1 * d % m + m);
    a1 = a1 * inv % m;
    long long tmp = k2 * d % m * d % m;
    tmp = (tmp + 2 * k1 * d % m * a1 % m) % m;
    tmp = (tmp + n * a1 % m * a1 % m) % m;
    if (tmp != sn2) continue;
    if (check(a1, d)) return 0 * printf("%I64d %I64d\n", a1, d);
  }
  printf("-1\n");
  return 0;
}
