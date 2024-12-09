#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pll = pair<i64, i64>;
constexpr int MAX = 200010;
constexpr int MOD = 1000000007;
constexpr int INV = 500000004;
struct Mat2x2 {
  i64 m00, m01, m10, m11;
  Mat2x2() = default;
  Mat2x2(i64 a, i64 b, i64 c, i64 d) : m00{a}, m01{b}, m10{c}, m11{d} {}
  Mat2x2 operator*(const Mat2x2& o) const {
    Mat2x2 ret;
    ret.m00 = (m00 * o.m00 + m01 * o.m10) % MOD;
    ret.m01 = (m00 * o.m01 + m01 * o.m11) % MOD;
    ret.m10 = (m10 * o.m00 + m11 * o.m10) % MOD;
    ret.m11 = (m10 * o.m01 + m11 * o.m11) % MOD;
    return ret;
  }
  Mat2x2 Pow(i64 n) const {
    Mat2x2 ret{1, 0, 0, 1}, a = *this;
    for (; n; n >>= 1) {
      if (n & 1) ret = ret * a;
      a = a * a;
    }
    return ret;
  }
};
i64 ModPow(i64 a, i64 b, i64 p = MOD) {
  i64 ret = 1;
  for (a %= p; b; b >>= 1) {
    if (b & 1) ret = ret * a % p;
    a = a * a % p;
  }
  return ret;
}
i64 a[MAX];
Pll Solve(int n) {
  Mat2x2 m{1, 2, 1, 0};
  i64 q = 2;
  int x = 0;
  for (int i = 0; i < n; ++i) {
    m = m.Pow(a[i]);
    q = ModPow(q, a[i]);
    if (a[i] > 1) x = 1;
  }
  i64 p = m.m11;
  if (!p) {
    q = 1;
  } else if (x) {
    p = p * INV % MOD;
    q = q * INV % MOD;
  }
  return {p, q};
}
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; ++i) {
      scanf("%I64d", &a[i]);
    }
    auto ans = Solve(n);
    cout << ans.first << "/" << ans.second << endl;
  }
  return 0;
}
