#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
template <typename T>
inline istream& operator>>(istream& i, vector<T>& v) {
  for (int j = 0; j < ((int)(v).size()); ++j) i >> v[j];
  return i;
}
template <typename T>
string join(const vector<T>& v) {
  stringstream s;
  for (int i = 0; i < ((int)(v).size()); ++i) s << ' ' << v[i];
  return s.str().substr(1);
}
template <typename T>
inline ostream& operator<<(ostream& o, const vector<T>& v) {
  if ((int)(v).size()) o << join(v);
  return o;
}
template <typename T1, typename T2>
inline istream& operator>>(istream& i, pair<T1, T2>& v) {
  return i >> v.first >> v.second;
}
template <typename T1, typename T2>
inline ostream& operator<<(ostream& o, const pair<T1, T2>& v) {
  return o << v.first << "," << v.second;
}
template <typename T>
inline long long int suma(const vector<T>& a) {
  long long int res(0);
  for (auto&& x : a) res += x;
  return res;
}
const double eps = 1e-10;
const long long int LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MX = 200005;
const int B = 9;
inline long long int ten(int n) { return n ? ten(n - 1) * 10 : 1; }
const int BS = ten(B);
struct bint;
istream& operator>>(istream& i, bint& a);
ostream& operator<<(ostream& o, const bint& a);
struct bint {
  vector<int> d;
  bool sg;
  bint(long long int n = 0) {
    sg = n < 0;
    if (sg) n = -n;
    while (n) {
      d.push_back(n % BS);
      n /= BS;
    }
  }
  bint(const string& s) {
    sg = s[0] == '-';
    int si = sg;
    for (int i = (int)(s).size(); i > si; i -= B) {
      d.push_back(0);
      for (int j = max(si, i - B); j < i; ++j)
        d.back() = d.back() * 10 + (s[j] - '0');
    }
    cut();
  }
  bint(const vector<int>& d, bool sg = false) : d(d), sg(sg) {}
  inline bint& cut() {
    while ((int)(d).size() && !d.back()) d.pop_back();
    sg &= !iszero();
    return *this;
  }
  inline int size() const { return (int)(d).size(); }
  inline int& operator[](int i) { return d[i]; }
  inline const int& operator[](int i) const { return d[i]; }
  inline int len() const {
    if (!(int)(d).size()) return 0;
    int l = ((int)(d).size() - 1) * B;
    int b = d.back();
    while (b) ++l, b /= 10;
    return l;
  }
  bint abs() const {
    bint a(*this);
    a.sg = false;
    return a;
  }
  inline bool iszero() const { return !(int)(d).size(); }
  long long int toLL() const {
    if (bint(INF) < abs()) return sg ? -INF : INF;
    long long int x = 0;
    for (int i = ((int)(d).size()) - 1; i >= 0; --i) x = x * BS + d[i];
    if (sg) x = -x;
    return x;
  }
  bint& _add(const bint& a) {
    if ((int)(d).size() <= (int)(a).size())
      d.resize((int)(a).size() + 1);
    else
      d.push_back(0);
    int i = 0;
    while (i < (int)(a).size()) {
      d[i] += a[i];
      if (d[i] >= BS)
        d[i] -= BS, ++d[++i];
      else
        ++i;
    }
    while (d[i] == BS) d[i] = 0, ++d[++i];
    if (!d.back()) d.pop_back();
    return *this;
  }
  bint& _asub(const bint& a) {
    int i = 0;
    while (i < (int)(a).size()) {
      d[i] -= a[i];
      if (d[i] < 0)
        d[i] += BS, --d[++i];
      else
        ++i;
    }
    if (i < (int)(d).size())
      while (d[i] == -1) d[i] = BS - 1, --d[++i];
    return cut();
  }
  bint& _sub(const bint& a) {
    if (_cmp(a)) {
      bint b(a);
      swap(*this, b);
      return _asub(b);
    }
    return _asub(a);
  }
  bint& operator+=(const bint& a) {
    if (sg == a.sg) return _add(a);
    return _sub(a);
  }
  bint& operator-=(const bint& a) {
    if (sg != a.sg) return _add(a);
    sg ^= 1;
    _sub(a);
    if (!iszero()) sg ^= 1;
    return *this;
  }
  bint& operator*=(long long int a) {
    if (!a) return *this = 0;
    if (a < 0) sg ^= 1, a = -a;
    if (LINF / BS < a) return (*this) *= bint(a);
    long long int x = 0;
    for (int i = 0; i < ((int)(d).size()); ++i) {
      x += a * d[i];
      d[i] = x % BS;
      x /= BS;
    }
    while (x) d.push_back(x % BS), x /= BS;
    return *this;
  }
  bint mult(const bint& a) const {
    if ((int)(a).size() == 1) return bint(*this) *= a[0];
    if (a.iszero()) return 0;
    bint b = (*this) * a.d.back();
    b.sg ^= a.sg;
    for (int i = ((int)(a).size() - 1) - 1; i >= 0; --i) {
      b.d.insert(b.d.begin(), 0);
      b += (*this) * a[i];
    }
    return b;
  }
  long long int operator%(long long int a) const {
    assert(a > 0);
    long long int r = 0;
    for (int i = ((int)(d).size()) - 1; i >= 0; --i) r = (r * BS + d[i]) % a;
    if (sg) r = (a - r) % a;
    return r;
  }
  bint& operator/=(long long int a) {
    assert(a);
    if (a < 0) sg ^= 1, a = -a;
    assert(LINF / BS >= a);
    long long int x = 0;
    for (int i = ((int)(d).size()) - 1; i >= 0; --i) {
      x = x * BS + d[i];
      d[i] = x / a;
      x %= a;
    }
    return cut();
  }
  bint operator+(const bint& a) const { return bint(*this) += a; }
  bint operator-(const bint& a) const { return bint(*this) -= a; }
  bint operator*(long long int a) const { return bint(*this) *= a; }
  bint operator*(const bint& a) const;
  bint& operator*=(const bint& a) { return *this = (*this) * a; }
  bint operator/(long long int a) const { return bint(*this) /= a; }
  bint operator/(const bint& a) const {
    assert(false);
    return bint();
  }
  bint operator%(const bint& a) const {
    assert(false);
    return bint();
  }
  bint square() const;
  bint ex(long long int t) const {
    if (!t) return 1;
    bint a = ex(t >> 1).square();
    if (t & 1) return a * (*this);
    return a;
  }
  bool _cmp(const bint& a) const {
    if ((int)(d).size() != (int)(a).size())
      return (int)(d).size() < (int)(a).size();
    for (int i = ((int)(d).size()) - 1; i >= 0; --i)
      if (d[i] != a[i]) return d[i] < a[i];
    return false;
  }
  bool operator<(const bint& a) const {
    if (sg != a.sg) return sg;
    return sg ? a._cmp(*this) : _cmp(a);
  }
  bool operator<=(const bint& a) const { return !(a < (*this)); }
  bool operator==(const bint& a) const { return sg == a.sg && d == a.d; }
  string str() const {
    if (!(int)(d).size()) return "0";
    ostringstream os;
    if (sg) os << '-';
    os << d.back();
    for (int i = ((int)(d).size() - 1) - 1; i >= 0; --i)
      os << setw(B) << setfill('0') << d[i];
    return os.str();
  }
};
long long int extgcd(long long int a, long long int b, long long int& x,
                     long long int& y) {
  for (long long int u = y = 1, v = x = 0; a;) {
    long long int q = b / a;
    swap(x -= q * u, u);
    swap(y -= q * v, v);
    swap(b -= q * a, a);
  }
  return b;
}
long long int mod_inv(long long int a, long long int m) {
  long long int x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}
long long int mod_pow(long long int a, long long int n, long long int mod) {
  long long int ret = 1;
  long long int p = a % mod;
  while (n) {
    if (n & 1) ret = ret * p % mod;
    p = p * p % mod;
    n >>= 1;
  }
  return ret;
}
template <int mod, int primitive_root>
struct NTT {
  int get_mod() const { return mod; }
  void _ntt(vector<int>& a, int sign) {
    const int n = (int)(a).size();
    int h = mod_pow(primitive_root, (mod - 1) / n, mod);
    if (sign == -1) h = mod_inv(h, mod);
    int i = 0;
    for (int j = 1; j < n - 1; ++j) {
      for (int k = n >> 1; k > (i ^= k); k >>= 1)
        ;
      if (j < i) swap(a[i], a[j]);
    }
    for (int m = 1; m < n; m *= 2) {
      const int m2 = m * 2;
      const long long int base = mod_pow(h, n / m2, mod);
      vector<long long int> w(m);
      w[0] = 1;
      for (int j = 1; j < m; ++j) w[j] = w[j - 1] * base % mod;
      for (int s = 0; s < n; s += m2) {
        for (int x = 0; x < (m); ++x) {
          int j = s + x;
          int d = a[j + m] * w[x] % mod;
          a[j + m] = a[j] - d;
          if (a[j + m] < 0) a[j + m] += mod;
          a[j] -= mod - d;
          if (a[j] < 0) a[j] += mod;
        }
      }
    }
  }
  void ntt(vector<int>& input) { _ntt(input, 1); }
  void intt(vector<int>& input) {
    _ntt(input, -1);
    const int n_inv = mod_inv((int)(input).size(), mod);
    for (auto& x : input) x = (long long int)x * n_inv % mod;
  }
  vector<int> convolution(const vector<int>& a, const vector<int>& b) {
    int ntt_size = 1;
    while (ntt_size < (int)(a).size() + (int)(b).size()) ntt_size *= 2;
    vector<int> _a = a, _b = b;
    _a.resize(ntt_size);
    _b.resize(ntt_size);
    ntt(_a);
    ntt(_b);
    for (int i = 0; i < (ntt_size); ++i)
      _a[i] = (long long int)_a[i] * _b[i] % mod;
    intt(_a);
    _a.resize((int)(a).size() + (int)(b).size());
    return _a;
  }
  vector<int> square(const vector<int>& a) {
    int ntt_size = 1;
    while (ntt_size < (int)(a).size() * 2) ntt_size *= 2;
    vector<int> _a = a;
    _a.resize(ntt_size);
    ntt(_a);
    for (int i = 0; i < (ntt_size); ++i)
      _a[i] = (long long int)_a[i] * _a[i] % mod;
    intt(_a);
    _a.resize((int)(a).size() * 2);
    return _a;
  }
};
const int P1 = 1811939329;
const int P2 = 2013265921;
const int P3 = 2113929217;
const long long int P12 = (long long int)P1 * P2;
const int IP1_2 = mod_inv(P1, P2);
const int IP12_3 = mod_inv(P12, P3);
const long long int P12_R = P12 % BS;
const long long int P12_Q = P12 / BS;
vector<int> _garner(vector<int>& x, vector<int>& y, vector<int>& z) {
  long long int c = 0;
  for (int i = 0; i < ((int)(x).size()); ++i) {
    y[i] = ((long long int)y[i] - x[i] + P2) * IP1_2 % P2;
    long long int s = x[i] + (long long int)y[i] * P1;
    z[i] = (z[i] - s % P3 + P3) * IP12_3 % P3;
    s += c + P12_R * z[i];
    c = P12_Q * z[i] + s / BS;
    x[i] = s % BS;
  }
  return x;
}
bint bint::operator*(const bint& a) const {
  if ((int)(a).size() <= 10) return mult(a);
  NTT<P1, 13> ntt1;
  NTT<P2, 31> ntt2;
  NTT<P3, 5> ntt3;
  vector<int> x = ntt1.convolution(d, a.d);
  vector<int> y = ntt2.convolution(d, a.d);
  vector<int> z = ntt3.convolution(d, a.d);
  return bint(_garner(x, y, z), sg ^ a.sg).cut();
}
bint bint::square() const {
  NTT<P1, 13> ntt1;
  NTT<P2, 31> ntt2;
  NTT<P3, 5> ntt3;
  vector<int> x = ntt1.square(d);
  vector<int> y = ntt2.square(d);
  vector<int> z = ntt3.square(d);
  return bint(_garner(x, y, z), false).cut();
}
istream& operator>>(istream& i, bint& a) {
  string s;
  i >> s;
  a = bint(s);
  return i;
}
ostream& operator<<(ostream& o, const bint& a) { return o << a.str(); }
long long int n;
int cnt;
int f(long long int i, long long int j) {
  i = n - i;
  j = n - j;
  cout << i << " " << j << endl;
  int res;
  cin >> res;
  ++cnt;
  return res;
}
bint area(pair<long long int, long long int> s,
          pair<long long int, long long int> t) {
  return bint(t.first - s.first) * (t.second - s.second);
}
int main() {
  cin >> n;
  pair<long long int, long long int> s(0, 0);
  pair<long long int, long long int> t(n, n);
  pair<long long int, long long int> x(0, 0);
  while (1) {
    bint a = (area(s, t) - area(s, x)) / 3 + 1;
    long long int i, j;
    {
      long long int l = x.first, r = t.first;
      while (l + 1 < r) {
        long long int c = (l + r) >> 1;
        if (area(pair<long long int, long long int>(c, s.second), t) < a)
          r = c;
        else
          l = c;
      }
      i = l;
    }
    {
      long long int l = x.second, r = t.second;
      while (l + 1 < r) {
        long long int c = (l + r) >> 1;
        if (area(pair<long long int, long long int>(s.first, c), t) < a)
          r = c;
        else
          l = c;
      }
      j = l;
    }
    int res = f(i, j);
    if (!res) break;
    if (res == 1) {
      t.first = i;
    } else if (res == 2) {
      t.second = j;
    } else {
      x = pair<long long int, long long int>(i + 1, j + 1);
    }
    if (x.first >= t.first) s.second = x.second, x = s;
    if (x.second >= t.second) s.first = x.first, x = s;
  }
  return 0;
}
