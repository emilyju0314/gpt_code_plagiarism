#include <bits/stdc++.h>
using namespace std;
template <typename T, typename S>
inline bool upmin(T& a, const S& b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T, typename S>
inline bool upmax(T& a, const S& b) {
  return a < b ? a = b, 1 : 0;
}
template <typename N, typename PN>
inline N flo(N a, PN b) {
  return a >= 0 ? a / b : -((-a - 1) / b) - 1;
}
template <typename N, typename PN>
inline N cei(N a, PN b) {
  return a > 0 ? (a - 1) / b + 1 : -(-a / b);
}
template <typename N>
N gcd(N a, N b) {
  return b ? gcd(b, a % b) : a;
}
inline void gn(long long& x) {
  int sg = 1;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  c == '-' ? (sg = -1, x = 0) : (x = c - '0');
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= sg;
}
inline void gn(int& x) {
  long long t;
  gn(t);
  x = t;
}
inline void gn(unsigned long long& x) {
  long long t;
  gn(t);
  x = t;
}
inline void gn(double& x) {
  double t;
  scanf("%lf", &t);
  x = t;
}
inline void gn(long double& x) {
  double t;
  scanf("%lf", &t);
  x = t;
}
inline long long sqr(long long a) { return a * a; }
inline double sqrf(double a) { return a * a; }
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
int mo = 1000000007;
int qp(int a, long long b) {
  int n = 1;
  do {
    if (b & 1) n = 1ll * n * a % mo;
    a = 1ll * a * a % mo;
  } while (b >>= 1);
  return n;
}
int n;
int a[1111111];
int xmi[1111111], xle[1111111], xri[1111111];
int main() {
  gn(n);
  for (int i = (1), _ed = (n + 1); i < _ed; i++) gn(a[i]);
  for (int i = 1; i < n; i++) {
    xri[i + 1] = xle[i] = min(a[i], a[i + 1]) - 1;
    if (i > 1) xmi[i] = min(min(a[i - 1], a[i]), a[i + 1]) - 1;
  }
  int pr = 0;
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    pr = (1ll * pr * xmi[i - 1] + xle[i - 1]) % mo;
    (((ans) = ((ans) + (1ll * pr * xri[i])) % mo) < 0 ? (ans) += mo : (ans));
  }
  for (int i = (1), _ed = (n + 1); i < _ed; i++)
    (((ans) = ((ans) + (a[i] - 1)) % mo) < 0 ? (ans) += mo : (ans));
  printf("%d\n", ans);
  return 0;
}
