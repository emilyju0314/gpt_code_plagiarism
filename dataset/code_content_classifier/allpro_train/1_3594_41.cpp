#include <bits/stdc++.h>
using namespace std;
int n, m, X, s[50000 + 5];
long long k, q[2 * 50000 + 5];
map<long long, int> U;
struct M {
  int a[2][2];
  inline M(const int& A = 0, const int& B = 0, const int& C = 0,
           const int& D = 0) {
    a[0][0] = A, a[0][1] = B, a[1][0] = C, a[1][1] = D;
  }
  inline int* operator[](const int& x) { return a[x]; }
  inline const int* operator[](const int& x) const { return a[x]; }
  inline M operator*(const M& o) const {
    M t;
    t[0][0] = (1LL * a[0][0] * o[0][0] + 1LL * a[0][1] * o[1][0]) % X;
    t[0][1] = (1LL * a[0][0] * o[0][1] + 1LL * a[0][1] * o[1][1]) % X;
    t[1][0] = (1LL * a[1][0] * o[0][0] + 1LL * a[1][1] * o[1][0]) % X;
    t[1][1] = (1LL * a[1][0] * o[0][1] + 1LL * a[1][1] * o[1][1]) % X;
    return t;
  }
  inline M operator^(long long y) const {
    M x = *this, t(1, 0, 0, 1);
    while (y) y & 1 && (t = t * x, 0), x = x * x, y >>= 1;
    return t;
  }
};
class SegmentTree {
 private:
  M V[50000 << 2];

 public:
  inline void Build(const int& l = 0, const int& r = n - 1, const int& rt = 1) {
    if (l == r)
      return (void)(V[rt] = M(0, s[(l - 2 + n) % n], 1, s[(l - 1 + n) % n]));
    register int mid = l + r >> 1;
    Build(l, mid, rt << 1), Build(mid + 1, r, rt << 1 | 1),
        V[rt] = V[rt << 1] * V[rt << 1 | 1];
  }
  inline M Q(const int& L, const int& R, const int& l = 0, const int& r = n - 1,
             const int& rt = 1) {
    if (L > R) return M(1, 0, 0, 1);
    if (L == l && r == R) return V[rt];
    register int mid = l + r >> 1;
    if (R <= mid) return Q(L, R, l, mid, rt << 1);
    if (L > mid) return Q(L, R, mid + 1, r, rt << 1 | 1);
    return Q(L, mid, l, mid, rt << 1) * Q(mid + 1, R, mid + 1, r, rt << 1 | 1);
  }
} S;
int main() {
  register int i;
  if (scanf("%lld%d", &k, &X), !k) return puts("0"), 0;
  if (k == 1) return puts(X ^ 1 ? "1" : "0"), 0;
  for (scanf("%d", &n), i = 0; i ^ n; ++i) scanf("%d", s + i);
  S.Build(0, n - 1);
  long long x, y;
  for (scanf("%d", &m), i = 1; i <= m; ++i)
    scanf("%lld%lld", &x, &y), U[x] = y, q[i] = x + 1, q[m + i] = x + 2;
  q[2 * m + 1] = k, sort(q + 1, q + 2 * m + 2),
            m = unique(q + 1, q + 2 * m + 2) - q - 1;
  while (m && q[m] > k) --m;
  long long nx, ny;
  M t;
  t[1][1] = 1;
  for (x = 0, y = 1, i = 1; i <= m; x = nx, y = ny, ++i)
    nx = q[i] / n, ny = q[i] % n,
    y >= ny && (++x, t = t * S.Q(y + 1, n - 1) * S.Q(0, ny - 1), y = ny - 1),
    t = t * ((S.Q(y + 1, n - 1) * S.Q(0, y)) ^ (nx - x)) * S.Q(y + 1, ny - 1) *
        M(0, (U.count(q[i] - 2) ? U[q[i] - 2] : s[(q[i] - 2) % n]), 1,
          (U.count(q[i] - 1) ? U[q[i] - 1] : s[(q[i] - 1) % n]));
  return printf("%d\n", t[1][1]), 0;
}
