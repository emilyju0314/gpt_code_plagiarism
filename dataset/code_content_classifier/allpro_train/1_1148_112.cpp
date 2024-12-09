#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vull = vector<ull>;
template <ll mod>
struct nu {
  nu(ll val = 0) : v{val} {
    if (v >= mod || v <= -mod) v %= mod;
    if (v < 0) v += mod;
  };
  ll v;
  operator ll() { return v; };
  nu<mod> operator+(const nu<mod>& o) const { return {v + o.v}; };
  nu<mod> operator-(const nu<mod>& o) const { return {v - o.v}; };
  nu<mod> operator*(const nu<mod>& o) const { return {v * o.v}; };
  nu<mod> operator+=(const nu<mod>& o) {
    v = nu<mod>{v + o.v};
    return *this;
  };
  nu<mod> operator-=(const nu<mod>& o) {
    v = nu<mod>{v - o.v};
    return *this;
  };
  nu<mod> operator*=(const nu<mod>& o) {
    v = nu<mod>{v * o.v};
    return *this;
  };
  nu<mod> operator!() const {
    nu<mod> R = 1;
    for (__typeof((ll)v) i = (2); i <= ((ll)v); ++i) R *= nu<mod>{i};
    return R;
  }
  nu<mod> operator^(ll b) const {
    nu<mod> R{1}, a{v};
    while (b > 0) {
      if (b & 1) R *= a;
      a *= a, b /= 2;
    }
    return R;
  }
  nu<mod> operator/(const nu<mod>& o) const {
    return (*this) * (o ^ (mod - 2));
  }
  nu<mod> operator/=(const nu<mod>& o) {
    v = ll((*this) / o);
    return *this;
  }
};
constexpr int INF = 2000000000;
constexpr ll INFl = 2000000000ll;
constexpr ll INFll = 2000000000000000000ll;
constexpr ll mod = 1e9 + 7;
using num = nu<mod>;
template <typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> x) {
  os << x.first << ' ' << x.second;
  return os;
}
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& x) {
  is >> x.first >> x.second;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& x) {
  for (T& i : x) os << i << ' ';
  return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& x) {
  for (T& i : x) is >> i;
  return is;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& A, const pair<T1, T2>& B) {
  return {A.first + B.first, A.second + B.second};
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& A, const pair<T1, T2>& B) {
  return {A.first - B.first, A.second - B.second};
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& A) {
  return {-A.first, -A.second};
}
template <typename T1, typename T2>
bool maxe(T1& A, const T2& B) {
  if (B > A) {
    A = B;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
bool mine(T1& A, const T2& B) {
  if (B < A) {
    A = B;
    return 1;
  }
  return 0;
}
int x;
bool in() {
  cin >> x;
  return true;
}
ll solve() {
  cout << "1 " << x - 1 << '\n';
  return -INF;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int noOfTests = 1;
  cin >> noOfTests;
  while (noOfTests-- > 0) {
    if (!in()) {
      cout << "popsute_wejscie\n";
      continue;
    }
    ll result = solve();
    if (result == ll(-'t'))
      cout << "TAK\n";
    else if (result == ll(-'n'))
      cout << "NIE\n";
    else if (result == ll(-'e'))
      cout << "Popsute\n";
    else if (result != -INF)
      cout << result << '\n';
  }
  return 0;
}
