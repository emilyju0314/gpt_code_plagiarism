#include <bits/stdc++.h>
using namespace std;

template <class T> T power(T a, long long n) {
  assert(n >= 0);
  T res = 1;
  while (n) {
    if (n & 1) res *= a;
    if (n >>= 1) a *= a;
  }
  return res;
}

template <unsigned M> struct modular {
  using m = modular;
  unsigned v;
  modular(long long a = 0) : v((a %= M) < 0 ? a + M : a) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m r) { if ((v += r.v) >= M) v -= M; return *this; }
  m& operator-=(m r) { if (v < r.v) v += M; v -= r.v; return *this; }
  m& operator*=(m r) { v = (uint64_t)v * r.v % M; return *this; }
  m& operator/=(m r) { return *this *= power(r, M - 2); }
  friend m operator+(m l, m r) { return l += r; }
  friend m operator-(m l, m r) { return l -= r; }
  friend m operator*(m l, m r) { return l *= r; }
  friend m operator/(m l, m r) { return l /= r; }
  friend bool operator==(m l, m r) { return l.v == r.v; }
};

constexpr long long mod = 1e9 + 7;
using mint = modular<mod>;

vector<mint> fact, inv_fact, minv;
void prepare(int n) {
  fact.resize(n + 1), inv_fact.resize(n + 1), minv.resize(n + 1);
  for (int i = 0; i <= n; ++i) fact[i] = i ? i * fact[i - 1] : 1;
  inv_fact[n] = power(fact[n], mod - 2);
  for (int i = n; i; --i) inv_fact[i - 1] = i * inv_fact[i];
  for (int i = 1; i <= n; ++i) minv[i] = inv_fact[i] * fact[i - 1];
}
mint binom(int n, int k) {
  if (k < 0 or k > n) return 0;
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}
template<> mint& mint::operator/=(mint r) {
  return *this *= r.v < minv.size() ? minv[r.v] : power(r, mod - 2);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int a, b, c, s, t;
  prepare(5e6);
  auto fn = [](int n, int k) -> mint {
    if (k == 0) return n == 0;
    return binom(n + k - 1, n);
  };
  while (cin >> a >> b >> c >> s >> t, a + b + c) {
    mint res;
    for (int x = 0; x <= min(s, t); ++x) {
      int p = s - x - a, q = t - x - b;
      if (p < 0 or q < 0) {
        continue;
      }
      res += fn(p, a) * fn(q, b) * fn(x, a + b + c);
    }
    res *= fact[a + b + c] * inv_fact[a] * inv_fact[b] * inv_fact[c];
    cout << res.v << '\n';
  }
}

