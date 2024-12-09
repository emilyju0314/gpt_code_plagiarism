#include <bits/stdc++.h>
template <typename T>
void MACRO_VAR_Scan(T& t) {
  std::cin >> t;
}
template <typename First, typename... Rest>
void MACRO_VAR_Scan(First& first, Rest&... rest) {
  std::cin >> first;
  MACRO_VAR_Scan(rest...);
}
template <typename T>
void MACRO_VEC_ROW_Init(int n, T& t) {
  t.resize(n);
}
template <typename First, typename... Rest>
void MACRO_VEC_ROW_Init(int n, First& first, Rest&... rest) {
  first.resize(n);
  MACRO_VEC_ROW_Init(n, rest...);
}
template <typename T>
void MACRO_VEC_ROW_Scan(int p, T& t) {
  std::cin >> t[p];
}
template <typename First, typename... Rest>
void MACRO_VEC_ROW_Scan(int p, First& first, Rest&... rest) {
  std::cin >> first[p];
  MACRO_VEC_ROW_Scan(p, rest...);
}
template <class T>
inline T CHMAX(T& a, const T b) {
  return a = (a < b) ? b : a;
}
template <class T>
inline T CHMIN(T& a, const T b) {
  return a = (a > b) ? b : a;
}
template <class T>
using V = std::vector<T>;
template <class T>
using VV = V<V<T>>;
template <typename S, typename T>
std::ostream& operator<<(std::ostream& os, std::pair<S, T> p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PAIR = std::pair<ll, ll>;
using PAIRLL = std::pair<ll, ll>;
constexpr ll INFINT = 1 << 30;
constexpr ll INFINT_LIM = (1LL << 31) - 1;
constexpr ll INFLL = 1LL << 60;
constexpr ll INFLL_LIM = (1LL << 62) - 1 + (1LL << 62);
constexpr double EPS = 1e-6;
constexpr ll MOD = 1000000007;
constexpr double PI = 3.141592653589793238462643383279;
template <class T, size_t N>
void FILL(T (&a)[N], const T& val) {
  for (auto& x : a) x = val;
}
template <class ARY, size_t N, size_t M, class T>
void FILL(ARY (&a)[N][M], const T& val) {
  for (auto& b : a) FILL(b, val);
}
template <class T>
void FILL(std::vector<T>& a, const T& val) {
  for (auto& x : a) x = val;
}
template <class ARY, class T>
void FILL(std::vector<std::vector<ARY>>& a, const T& val) {
  for (auto& b : a) FILL(b, val);
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ;
  ll n, m;
  MACRO_VAR_Scan(n, m);
  ;
  std::vector<ll> a, b;
  MACRO_VEC_ROW_Init(m, a, b);
  for (ll w_ = 0; w_ < m; ++w_) {
    MACRO_VEC_ROW_Scan(w_, a, b);
  };
  std::vector<std::vector<ll>> g(n);
  for (ll i = 0; i < ll(m); ++i) {
    --a[i];
    --b[i];
    g[a[i]].emplace_back(b[i]);
  }
  std::vector<ll> min(n, INFLL);
  for (ll i = 0; i < ll(n); ++i) {
    for (ll x : g[i]) {
      ll cost = x - i;
      if (cost <= 0) cost += n;
      CHMIN(min[i], cost);
    }
  }
  for (ll i = 0; i < ll(n); ++i) {
    ll ans = 0;
    for (ll j = 0; j < ll(n); ++j) {
      ll J = (i + j) % n;
      if (g[J].empty()) continue;
      ll len = g[J].size();
      ll sum = (len - 1) * n + j + min[J];
      CHMAX(ans, sum);
    }
    std::cout << (ans);
    std::cout << (i + 1 == n ? '\n' : ' ');
    ;
  }
  return 0;
}
