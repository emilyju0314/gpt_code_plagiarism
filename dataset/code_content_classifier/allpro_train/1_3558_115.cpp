#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
void err() { std::cout << std::endl; }
template <typename T, typename... Args>
void err(T a, Args... args) {
  std::cout << a << ' ';
  err(args...);
}
using namespace std;
mt19937 rng_32(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9 + 7;
const int seed = 233;
const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const int max_n = 100005;
namespace {
inline int Add(int x, int y) { return (x += y) >= mod ? x - mod : x; }
inline int Sub(int x, int y) { return (x -= y) < 0 ? x + mod : x; }
inline int Mul(int x, int y) { return 1ll * x * y % mod; }
inline int Pow(int x, int y = mod - 2) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return res;
}
}  // namespace
struct mat {
  int n, m;
  int a[105][105];
  mat(int _n = 0, int _m = 0) {
    n = _n, m = _m;
    memset(a, 0, sizeof(a));
  }
  mat operator*(mat b) {
    mat c(n, b.m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < b.m; j++) {
        c.a[i][j] = 0;
        for (int k = 0; k < m; k++) {
          c.a[i][j] = Add(c.a[i][j], Mul(a[i][k], b.a[k][j]));
        }
      }
    }
    return c;
  }
  void unit() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) a[i][j] = (i == j);
    }
  }
};
mat quick_pow(mat a, long long n) {
  mat c(a.n, a.m);
  c.unit();
  while (n) {
    if (n & 1) c = c * a;
    a = a * a;
    n >>= 1;
  }
  return c;
}
int C(int n) { return 1ll * n * (n - 1) / 2 % mod; }
int n, k;
int a[max_n];
int c[2];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", a + i), c[a[i]]++;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0 && i <= c[0]) cnt++;
    if (a[i] == 1 && i > c[0]) cnt++;
  }
  mat s(n + 1, 1);
  s.a[(n - cnt) / 2][0] = 1;
  mat A(n + 1, n + 1);
  for (int i = 0; i <= n; i++) {
    if (i)
      A.a[i][i - 1] =
          1ll * (c[0] + mod - (i - 1)) * (c[1] + mod - (i - 1)) % mod;
    if (i != n) A.a[i][i + 1] = (i + 1) * (i + 1);
    A.a[i][i] = C(n) - i * i - (c[0] - i) * (c[1] - i);
    A.a[i][i] += mod, A.a[i][i] %= mod;
  }
  A = quick_pow(A, k);
  s = A * s;
  long long y = Pow(C(n), k);
  y = Pow(y);
  y = 1ll * y * s.a[0][0] % mod;
  printf("%lld\n", y);
  return 0;
}
