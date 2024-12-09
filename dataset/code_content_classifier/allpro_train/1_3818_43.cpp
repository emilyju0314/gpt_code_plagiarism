#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
auto& errStream = cerr;
class CerrDummy {
} cerrDummy;
template <class T>
CerrDummy& operator<<(CerrDummy& cd, const T&) {
  return cd;
}
using charTDummy = char;
using traitsDummy = char_traits<charTDummy>;
CerrDummy& operator<<(CerrDummy& cd,
                      basic_ostream<charTDummy, traitsDummy>&(
                          basic_ostream<charTDummy, traitsDummy>&)) {
  return cd;
}
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
using pi = pair<int, int>;
using vi = vector<int>;
using ld = long double;
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  for (int i = int(0); i < int((int)v.size()); i++) {
    if (i) os << ",";
    os << v[i];
  }
  os << "}";
  return os;
}
template <int i, class T>
void print_tuple(ostream&, const T&) {}
template <int i, class T, class H, class... Args>
void print_tuple(ostream& os, const T& t) {
  if (i) os << ",";
  os << get<i>(t);
  print_tuple<i + 1, T, Args...>(os, t);
}
template <class... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
  os << "(";
  print_tuple<0, tuple<Args...>, Args...>(os, t);
  return os << ")";
}
ll read() {
  ll i;
  scanf("%" SCNd64, &i);
  return i;
}
void printSpace() { printf(" "); }
void printEoln() { printf("\n"); }
void print(ll x, int suc = 1) {
  printf("%" PRId64, x);
  if (suc == 1) printEoln();
  if (suc == 2) printSpace();
}
template <class T>
void print(const vector<T>& v) {
  for (int i = int(0); i < int(v.size()); i++)
    print(v[i], i == int(v.size()) - 1 ? 1 : 2);
}
string readString() {
  static char buf[3341000];
  scanf("%s", buf);
  return string(buf);
}
char* readCharArray() {
  static char buf[3341000];
  static int bufUsed = 0;
  char* ret = buf + bufUsed;
  scanf("%s", ret);
  bufUsed += strlen(ret) + 1;
  return ret;
}
template <class T, class U>
void chmax(T& a, U b) {
  if (a < b) a = b;
}
template <class T, class U>
void chmin(T& a, U b) {
  if (b < a) a = b;
}
template <class T>
T Sq(const T& t) {
  return t * t;
}
void Yes(bool ex = true) {
  cout << "YES" << endl;
  if (ex) exit(0);
}
void No(bool ex = true) {
  cout << "NO" << endl;
  if (ex) exit(0);
}
const ll infLL = LLONG_MAX / 3;
const int inf = INT_MAX / 2 - 100;
constexpr ll TEN(int n) { return n == 0 ? 1 : TEN(n - 1) * 10; }
template <class T>
vector<T> Uniqued(const vector<T>& vv) {
  auto v(vv);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  return v;
}
template <class T>
void MakeUniqued(vector<T>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
template <int mod>
struct ModInt {
  static constexpr int base = mod;
  int v;
  ModInt() : v(0) {}
  ModInt(ll vv) {
    v = vv % mod;
    if (v < 0) v += mod;
  }
  explicit operator bool() const { return v; }
  explicit operator int() const { return v; }
  bool operator==(const ModInt& rhs) const { return v == rhs.v; }
  bool operator!=(const ModInt& rhs) const { return v != rhs.v; }
  ModInt operator-() const { return ModInt(0) - *this; }
  ModInt& operator+=(const ModInt& rhs) {
    v += rhs.v;
    if (v >= mod) v -= mod;
    return *this;
  }
  ModInt& operator-=(const ModInt& rhs) {
    v -= rhs.v;
    if (v < 0) v += mod;
    return *this;
  }
  ModInt& operator*=(const ModInt& rhs) {
    v = ll(v) * rhs.v % mod;
    return *this;
  }
  ModInt& operator/=(const ModInt& rhs) {
    operator*=(rhs.inv());
    return *this;
  }
  ModInt operator+(const ModInt& rhs) const { return ModInt(*this) += rhs; }
  ModInt operator-(const ModInt& rhs) const { return ModInt(*this) -= rhs; }
  ModInt operator*(const ModInt& rhs) const { return ModInt(*this) *= rhs; }
  ModInt operator/(const ModInt& rhs) const { return ModInt(*this) /= rhs; }
  friend ModInt operator+(int x, const ModInt& y) { return ModInt(x) + y; }
  friend ModInt operator-(int x, const ModInt& y) { return ModInt(x) - y; }
  friend ModInt operator*(int x, const ModInt& y) { return ModInt(x) * y; }
  friend ModInt operator/(int x, const ModInt& y) { return ModInt(x) / y; }
  ModInt pow(int n) const {
    ModInt res(1), x(*this);
    while (n) {
      if (n & 1) res *= x;
      x *= x;
      n >>= 1;
    }
    return res;
  }
  ModInt inv() const { return pow(mod - 2); }
};
template <int mod>
ostream& operator<<(ostream& os, const ModInt<mod>& m) {
  return os << m.v;
}
template <int mod>
void print(const ModInt<mod>& m, int suc = 1) {
  print(m.v, suc);
}
using mint = ModInt<998244353>;
template <class T>
void inplace_xor_transform(vector<T>& f) {
  int n = f.size();
  for (int b = 1; b <= n / 2; b *= 2) {
    for (int i = 0; i < n; i += b * 2) {
      for (int j = i; j < i + b; j++) {
        tie(f[j], f[j + b]) = make_tuple(f[j] + f[j + b], f[j] - f[j + b]);
      }
    }
  }
}
V<mint> GetPBuf(mint v, int n) {
  V<mint> res{1};
  for (int i = int(0); i < int(n); i++) res.push_back(res.back() * v);
  return res;
}
signed main() {
  bool dbg = false;
  mt19937 rnd(2434);
  int n, k, x, y, z;
  n = read();
  if (n == -1) {
    dbg = true;
    n = TEN(5);
    k = 17;
    x = rnd() % TEN(9);
    y = rnd() % TEN(9);
    z = rnd() % TEN(9);
  } else {
    k = read();
    x = read();
    y = read();
    z = read();
  }
  int off = 0;
  vi b(n), c(n);
  for (int i = int(0); i < int(n); i++) {
    if (dbg) {
      b[i] = rnd() % (1 << k);
      c[i] = rnd() % (1 << k);
    } else {
      int a = read();
      off ^= a;
      b[i] = read() ^ a;
      c[i] = read() ^ a;
    }
  }
  vi p(1 << k), q(1 << k), r(1 << k);
  for (int i = int(0); i < int(n); i++) {
    p[b[i]] += 1;
    q[c[i]] += 1;
    r[b[i] ^ c[i]] += 1;
  }
  inplace_xor_transform(p);
  inplace_xor_transform(q);
  inplace_xor_transform(r);
  V<mint> pBuf[4]{GetPBuf(mint(x) + y + z, n), GetPBuf(mint(x) - y + z, n),
                  GetPBuf(mint(x) + y - z, n), GetPBuf(mint(x) - y - z, n)};
  V<mint> buf;
  for (int bit = int(0); bit < int(1 << k); bit++) {
    int d = int(n - p[bit]) / 2, e = int(n - q[bit]) / 2;
    int f = (d + e - int(n - r[bit]) / 2) / 2;
    d -= f;
    e -= f;
    buf.push_back(pBuf[0][n - (d + e + f)] * pBuf[1][d] * pBuf[2][e] *
                  pBuf[3][f]);
  }
  inplace_xor_transform(buf);
  V<mint> ans(1 << k);
  for (int bit = int(0); bit < int(1 << k); bit++)
    ans[bit ^ off] = buf[bit] / (1 << k);
  print(ans);
}
