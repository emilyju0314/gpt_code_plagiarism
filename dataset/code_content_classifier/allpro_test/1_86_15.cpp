#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 9, mod = 998244353;
template <const int32_t MOD>
struct modint {
  int32_t value;
  modint() = default;
  modint(int32_t value_) : value(value_) {}
  inline modint<MOD> operator+(modint<MOD> other) const {
    int32_t c = this->value + other.value;
    return modint<MOD>(c >= MOD ? c - MOD : c);
  }
  inline modint<MOD> operator-(modint<MOD> other) const {
    int32_t c = this->value - other.value;
    return modint<MOD>(c < 0 ? c + MOD : c);
  }
  inline modint<MOD> operator*(modint<MOD> other) const {
    int32_t c = (int64_t)this->value * other.value % MOD;
    return modint<MOD>(c < 0 ? c + MOD : c);
  }
  inline modint<MOD> &operator+=(modint<MOD> other) {
    this->value += other.value;
    if (this->value >= MOD) this->value -= MOD;
    return *this;
  }
  inline modint<MOD> &operator-=(modint<MOD> other) {
    this->value -= other.value;
    if (this->value < 0) this->value += MOD;
    return *this;
  }
  inline modint<MOD> &operator*=(modint<MOD> other) {
    this->value = (int64_t)this->value * other.value % MOD;
    if (this->value < 0) this->value += MOD;
    return *this;
  }
  inline modint<MOD> operator-() const {
    return modint<MOD>(this->value ? MOD - this->value : 0);
  }
  modint<MOD> pow(uint64_t k) const {
    modint<MOD> x = *this, y = 1;
    for (; k; k >>= 1) {
      if (k & 1) y *= x;
      x *= x;
    }
    return y;
  }
  modint<MOD> inv() const { return pow(MOD - 2); }
  inline modint<MOD> operator/(modint<MOD> other) const {
    return *this * other.inv();
  }
  inline modint<MOD> operator/=(modint<MOD> other) {
    return *this *= other.inv();
  }
  inline bool operator==(modint<MOD> other) const {
    return value == other.value;
  }
  inline bool operator!=(modint<MOD> other) const {
    return value != other.value;
  }
  inline bool operator<(modint<MOD> other) const { return value < other.value; }
  inline bool operator>(modint<MOD> other) const { return value > other.value; }
};
template <int32_t MOD>
modint<MOD> operator*(int64_t value, modint<MOD> n) {
  return modint<MOD>(value) * n;
}
template <int32_t MOD>
modint<MOD> operator*(int32_t value, modint<MOD> n) {
  return modint<MOD>(value % MOD) * n;
}
template <int32_t MOD>
istream &operator>>(istream &in, modint<MOD> &n) {
  return in >> n.value;
}
template <int32_t MOD>
ostream &operator<<(ostream &out, modint<MOD> n) {
  return out << n.value;
}
using mint = modint<mod>;
mint pw[N];
mint genius(int n, int k) {
  if (k == 0) return 1;
  vector<mint> c(k, 0), d(k + 1, 0);
  d[k] = 1;
  for (int i = k - 1; i >= 0; i--) {
    c[i] = pw[i] * d[i + 1];
    d[i] = (pw[i] - 1) * d[i + 1];
  }
  mint ans = 0, pwn = mint(2).pow(n), cur = 1;
  for (int i = 0; i < k; i++) {
    ans += ((k - 1 - i) & 1 ? mod - 1 : 1) * c[i] * cur;
    cur *= pwn;
  }
  return ans;
}
mint f(int n, int k) {
  if (k == 0 or n > k) return 0;
  mint ans = 1;
  for (int i = 0; i < n; i++) {
    ans *= pw[k] - pw[i];
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pw[0] = 1;
  for (int i = 1; i < N; i++) {
    pw[i] = pw[i - 1] * 2;
  }
  int t;
  cin >> t;
  while (t--) {
    int n, k, x;
    cin >> n >> k >> x;
    if (x) {
      cout << genius(n, k) << '\n';
    } else {
      cout << f(n, k) << '\n';
    }
  }
  return 0;
}
