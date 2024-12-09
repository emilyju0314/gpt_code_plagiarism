#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 100005;
const double PI = acos(-1.0);
const double eps = 1e-9;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
int n, k, T, g, ans;
int Pow(int a, int k) {
  if (k == 0) return 1;
  if (k == 1) return a;
  int t = Pow(a, k >> 1);
  t = (long long)t * t % _p;
  if (k & 1)
    return (long long)t * a % _p;
  else
    return t;
}
inline int inv(int x) {
  if (x <= 0) x += _p;
  return Pow(x, _p - 2);
}
int sum1(int q, int n) {
  if (n <= 0) return 0;
  if (q == 1) return n;
  return (long long)inv(q - 1) * (Pow(q, n) - 1) % _p;
}
int sum2(int q, int n) {
  if (n <= 0) return 0;
  if (q == 1) return (long long)n * (n + 1) / 2 % _p;
  int t = inv(q - 1);
  return (-n + (long long)q * (Pow(q, n) - 1) % _p * t % _p) % _p * t % _p;
}
int solve(int n, int k, int a1, int b1, int a2, int b2, int c1, int c2,
          int c0) {
  if (n == k) {
    int x = (long long)b2 * inv(1 - a2) % _p;
    return ((long long)c1 * x % _p + c0) % _p;
  }
  int q = (n - 1) / k, r = (n - 1) % k + 1, a, b, A1, B1, A2, B2, C1, C2, C0;
  a = (long long)a2 * Pow(a1, q - 1) % _p,
  b = (long long)a2 * b1 % _p * sum1(a1, q - 1) % _p + b2, b %= _p;
  A1 = inv(a), B1 = (long long)-b * A1 % _p;
  a = (long long)a2 * Pow(a1, q) % _p,
  b = (long long)a2 * b1 % _p * sum1(a1, q) % _p + b2, b %= _p;
  A2 = inv(a), B2 = (long long)-b * A2 % _p;
  C1 = c1 + (long long)c2 * a1 % _p * sum1(a1, q) % _p, C1 %= _p;
  C2 = c1 + (long long)c2 * a1 % _p * sum1(a1, q - 1) % _p, C2 %= _p;
  C0 = c0 + (long long)c2 * b1 % _p *
                ((long long)r * sum1(a1, q) % _p +
                 (long long)k * sum2(a1, q - 1) % _p) %
                _p,
  C0 %= _p;
  return solve(k, r, A1, B1, A2, B2, C1, C2, C0);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    g = gcd(n, k);
    n /= g, k /= g;
    ans = solve(n, k, 1, 1, (_p + 1) / 2, 1, 1, 1, 0);
    ans = (long long)ans * inv(n) % _p;
    ans = ((long long)ans + _p) % _p;
    printf("%d\n", ans);
  }
  return 0;
}
