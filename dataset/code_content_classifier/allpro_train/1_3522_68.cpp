#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class t, class u>
void chmax(t& first, u second) {
  if (first < second) first = second;
}
template <class t, class u>
void chmin(t& first, u second) {
  if (second < first) first = second;
}
template <class t>
using vc = vector<t>;
template <class t>
using vvc = vc<vc<t>>;
using pi = pair<ll, ll>;
using vi = vc<ll>;
template <class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << "," << p.second << "}";
}
template <class t>
ostream& operator<<(ostream& os, const vc<t>& v) {
  os << "{";
  for (auto e : v) os << e << ",";
  return os << "}";
}
using uint = unsigned;
using ull = unsigned long long;
template <class t, size_t n>
ostream& operator<<(ostream& os, const array<t, n>& first) {
  return os << vc<t>(first.begin(), first.end());
}
template <ll i, class T>
void print_tuple(ostream&, const T&) {}
template <ll i, class T, class H, class... Args>
void print_tuple(ostream& os, const T& t) {
  if (i) os << ",";
  os << get<i>(t);
  print_tuple<i + 1, T, Args...>(os, t);
}
template <class... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
  os << "{";
  print_tuple<0, tuple<Args...>, Args...>(os, t);
  return os << "}";
}
template <class t>
void print(t x, ll suc = 1) {
  cout << x;
  if (suc == 1) cout << "\n";
  if (suc == 2) cout << " ";
}
ll read() {
  ll i;
  cin >> i;
  return i;
}
vi readvi(ll n, ll off = 0) {
  vi v(n);
  for (ll i = ll(0); i < ll(n); i++) v[i] = read() + off;
  return v;
}
template <class T>
void print(const vector<T>& v, ll suc = 1) {
  for (ll i = ll(0); i < ll(v.size()); i++)
    print(v[i], i == ll(v.size()) - 1 ? suc : 2);
}
string readString() {
  string s;
  cin >> s;
  return s;
}
template <class T>
T sq(const T& t) {
  return t * t;
}
void yes(bool ex = true) {
  cout << "Yes"
       << "\n";
  if (ex) exit(0);
}
void no(bool ex = true) {
  cout << "No"
       << "\n";
  if (ex) exit(0);
}
void possible(bool ex = true) {
  cout << "Possible"
       << "\n";
  if (ex) exit(0);
}
void impossible(bool ex = true) {
  cout << "Impossible"
       << "\n";
  if (ex) exit(0);
}
constexpr ll ten(ll n) { return n == 0 ? 1 : ten(n - 1) * 10; }
const ll infLL = LLONG_MAX / 3;
const ll inf = infLL;
ll topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
ll topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
ll botbit(signed first) { return first == 0 ? 32 : __builtin_ctz(first); }
ll botbit(ll first) { return first == 0 ? 64 : __builtin_ctzll(first); }
ll popcount(signed t) { return __builtin_popcount(t); }
ll popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(ll i) { return i && (i & -i) == i; }
ll mask(ll i) { return (ll(1) << i) - 1; }
bool inc(ll first, ll second, ll c) { return first <= second && second <= c; }
template <class t>
void mkuni(vc<t>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
ll rand_int(ll l, ll r) {
  static random_device rd;
  static mt19937_64 gen(rd());
  return uniform_int_distribution<ll>(l, r)(gen);
}
template <class t>
ll lwb(const vc<t>& v, const t& first) {
  return lower_bound(v.begin(), v.end(), first) - v.begin();
}
template <class T, class F>
struct SegTree {
  vc<T> buf;
  ll s;
  const F f;
  const T g;
  SegTree(F ff, T gg) : f(ff), g(gg) {}
  void init(const vc<T>& d) {
    ll n = d.size();
    s = 1;
    while (s < n) s *= 2;
    buf.resize(s * 2, g);
    for (ll i = ll(0); i < ll(n); i++) buf[i + s] = d[i];
    for (ll i = ll(s) - 1; i >= ll(1); i--) u(i);
  }
  SegTree(const vc<T>& d, F ff, T gg) : f(ff), g(gg) { init(d); }
  void u(ll i) { buf[i] = f(buf[i * 2], buf[i * 2 + 1]); }
  void set(ll i, T t) {
    i += s;
    buf[i] = t;
    while (i >>= 1) u(i);
  }
  void upd(ll i, T t) {
    i += s;
    buf[i] = f(buf[i], t);
    while (i >>= 1) u(i);
  }
  T get(ll second, ll e, ll l, ll r, ll i) {
    if (e <= l || r <= second) return g;
    if (second <= l && r <= e) return buf[i];
    ll m = (l + r) / 2;
    return f(get(second, e, l, m, i * 2), get(second, e, m, r, i * 2 + 1));
  }
  T get(ll second, ll e) {
    assert(second <= e);
    return get(second, e, 0, s, 1);
  }
};
template <class T, class F>
SegTree<T, F> segtree(const vc<T>& d, F f, T g) {
  return SegTree<T, F>(d, f, g);
}
using uint = unsigned;
using ull = unsigned long long;
struct modinfo {
  uint mod, root;
};
template <modinfo const& ref>
struct modular {
  static constexpr uint const& mod = ref.mod;
  static modular root() { return modular(ref.root); }
  uint v;
  modular(ll vv = 0) { s(vv % mod + mod); }
  modular& s(uint vv) {
    v = vv < mod ? vv : vv - mod;
    return *this;
  }
  modular operator-() const { return modular() - *this; }
  modular& operator+=(const modular& rhs) { return s(v + rhs.v); }
  modular& operator-=(const modular& rhs) { return s(v + mod - rhs.v); }
  modular& operator*=(const modular& rhs) {
    v = ull(v) * rhs.v % mod;
    return *this;
  }
  modular& operator/=(const modular& rhs) { return *this *= rhs.inv(); }
  modular operator+(const modular& rhs) const { return modular(*this) += rhs; }
  modular operator-(const modular& rhs) const { return modular(*this) -= rhs; }
  modular operator*(const modular& rhs) const { return modular(*this) *= rhs; }
  modular operator/(const modular& rhs) const { return modular(*this) /= rhs; }
  modular pow(ll n) const {
    modular res(1), x(*this);
    while (n) {
      if (n & 1) res *= x;
      x *= x;
      n >>= 1;
    }
    return res;
  }
  modular inv() const { return pow(mod - 2); }
  friend modular operator+(ll x, const modular& y) { return modular(x) + y; }
  friend modular operator-(ll x, const modular& y) { return modular(x) - y; }
  friend modular operator*(ll x, const modular& y) { return modular(x) * y; }
  friend modular operator/(ll x, const modular& y) { return modular(x) / y; }
  friend ostream& operator<<(ostream& os, const modular& m) {
    return os << m.v;
  }
  friend istream& operator>>(istream& is, modular& m) {
    ll x;
    is >> x;
    m = modular(x);
    return is;
  }
  bool operator<(const modular& r) const { return v < r.v; }
  bool operator==(const modular& r) const { return v == r.v; }
  bool operator!=(const modular& r) const { return v != r.v; }
  explicit operator bool() const { return v; }
};
constexpr modinfo base{1000000007, 0};
using mint = modular<base>;
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  ll L, n, m;
  cin >> L >> n >> m;
  vi pos{-1, L + 1};
  vc<pi> w[2];
  for (ll k = ll(0); k < ll(2); k++) {
    for (ll _ = ll(0); _ < ll((k == 0 ? n : m)); _++) {
      ll l, r;
      cin >> l >> r;
      l--;
      pos.push_back(l);
      pos.push_back(r);
      w[k].emplace_back(l, r);
    }
  }
  mkuni(pos);
  ll s = ll(pos.size());
  const auto madd = [](mint first, mint second) { return first + second; };
  using sss = SegTree<mint, decltype(madd)>;
  vc<sss> segs;
  for (ll k = ll(0); k < ll(2); k++) {
    segs.emplace_back(vc<mint>(s), madd, mint(0));
  }
  segs[0].upd(0, 1);
  vc<array<ll, 2>> mx(s, {-1, -1});
  for (ll k = ll(0); k < ll(2); k++) {
    for (auto lr : w[k]) {
      ll l, r;
      tie(l, r) = lr;
      l = lwb(pos, l);
      r = lwb(pos, r);
      chmax(mx[r][k], l);
    }
  }
  mint ans;
  for (ll i = ll(0); i < ll(s - 1); i++) {
    for (ll k = ll(0); k < ll(2); k++) chmax(mx[i + 1][k], mx[i][k]);
    mint first[2];
    if (pos[i] + 1 < pos[i + 1]) {
      ll d = pos[i + 1] - pos[i] - 1;
      for (ll k = ll(0); k < ll(2); k++)
        first[k ^ 1] = segs[k].get(mx[i][k] + 1, i + 1);
      mint z = (first[0] + first[1]) * (mint(2).pow(d - 1) - 1);
      first[0] += z;
      first[1] += z;
    }
    mint second[2];
    for (ll k = ll(0); k < ll(2); k++)
      second[k ^ 1] = segs[k].get(mx[i + 1][k] + 1, i + 1) + first[k];
    ans = second[0];
    for (ll k = ll(0); k < ll(2); k++) segs[k].upd(i + 1, first[k] + second[k]);
  }
  cout << ans << endl;
}
