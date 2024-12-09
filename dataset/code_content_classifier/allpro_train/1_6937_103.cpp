#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MX = 5e5 + 5;
const long long INF = 1e18;
const long double PI = 4 * atan((long double)1);
template <class T>
bool ckmin(T& a, const T& b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
namespace input {
template <class T>
void re(complex<T>& x);
template <class T1, class T2>
void re(pair<T1, T2>& p);
template <class T>
void re(vector<T>& a);
template <class T, size_t SZ>
void re(array<T, SZ>& a);
template <class T>
void re(T& x) {
  cin >> x;
}
void re(double& x) {
  string t;
  re(t);
  x = stod(t);
}
void re(long double& x) {
  string t;
  re(t);
  x = stold(t);
}
template <class T, class... Ts>
void re(T& t, Ts&... ts) {
  re(t);
  re(ts...);
}
template <class T>
void re(complex<T>& x) {
  T a, b;
  re(a, b);
  x = cd(a, b);
}
template <class T1, class T2>
void re(pair<T1, T2>& p) {
  re(p.first, p.second);
}
template <class T>
void re(vector<T>& a) {
  for (int i = (0); i < ((int)a.size()); ++i) re(a[i]);
}
template <class T, size_t SZ>
void re(array<T, SZ>& a) {
  for (int i = (0); i < (SZ); ++i) re(a[i]);
}
}  // namespace input
using namespace input;
namespace output {
void pr(int x) { cout << x; }
void pr(long x) { cout << x; }
void pr(long long x) { cout << x; }
void pr(unsigned x) { cout << x; }
void pr(unsigned long x) { cout << x; }
void pr(unsigned long long x) { cout << x; }
void pr(float x) { cout << x; }
void pr(double x) { cout << x; }
void pr(long double x) { cout << x; }
void pr(char x) { cout << x; }
void pr(const char* x) { cout << x; }
void pr(const string& x) { cout << x; }
void pr(bool x) { pr(x ? "true" : "false"); }
template <class T>
void pr(const complex<T>& x) {
  cout << x;
}
template <class T1, class T2>
void pr(const pair<T1, T2>& x);
template <class T>
void pr(const T& x);
template <class T, class... Ts>
void pr(const T& t, const Ts&... ts) {
  pr(t);
  pr(ts...);
}
template <class T1, class T2>
void pr(const pair<T1, T2>& x) {
  pr("{", x.first, ", ", x.second, "}");
}
template <class T>
void pr(const T& x) {
  pr("{");
  bool fst = 1;
  for (const auto& a : x) pr(!fst ? ", " : "", a), fst = 0;
  pr("}");
}
void ps() { pr("\n"); }
template <class T, class... Ts>
void ps(const T& t, const Ts&... ts) {
  pr(t);
  if (sizeof...(ts)) pr(" ");
  ps(ts...);
}
void pc() { pr("]\n"); }
template <class T, class... Ts>
void pc(const T& t, const Ts&... ts) {
  pr(t);
  if (sizeof...(ts)) pr(", ");
  pc(ts...);
}
}  // namespace output
using namespace output;
namespace io {
void setIn(string second) { freopen(second.c_str(), "r", stdin); }
void setOut(string second) { freopen(second.c_str(), "w", stdout); }
void setIO(string second = "") {
  cin.sync_with_stdio(0);
  cin.tie(0);
  if ((int)second.size()) {
    setIn(second + ".in"), setOut(second + ".out");
  }
}
}  // namespace io
using namespace io;
typedef decay<decltype(MOD)>::type T;
struct mi {
  T val;
  explicit operator T() const { return val; }
  mi() { val = 0; }
  mi(const long long& v) {
    val = (-MOD <= v && v <= MOD) ? v : v % MOD;
    if (val < 0) val += MOD;
  }
  friend void pr(const mi& a) { pr(a.val); }
  friend void re(mi& a) {
    long long x;
    re(x);
    a = mi(x);
  }
  friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
  friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
  friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
  mi operator-() const { return mi(-val); }
  mi& operator+=(const mi& m) {
    if ((val += m.val) >= MOD) val -= MOD;
    return *this;
  }
  mi& operator-=(const mi& m) {
    if ((val -= m.val) < 0) val += MOD;
    return *this;
  }
  mi& operator*=(const mi& m) {
    val = (long long)val * m.val % MOD;
    return *this;
  }
  friend mi pow(mi a, long long p) {
    mi ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  friend mi inv(const mi& a) {
    assert(a != 0);
    return pow(a, MOD - 2);
  }
  mi& operator/=(const mi& m) { return (*this) *= inv(m); }
  friend mi operator+(mi a, const mi& b) { return a += b; }
  friend mi operator-(mi a, const mi& b) { return a -= b; }
  friend mi operator*(mi a, const mi& b) { return a *= b; }
  friend mi operator/(mi a, const mi& b) { return a /= b; }
};
void check(pair<int, int>& a, int b) {
  if (b > a.first) swap(b, a.first);
  if (b > a.second) swap(b, a.second);
}
int n, cum[MX];
pair<int, int> lst[MX];
long long ans;
void check(int y) {
  long long cnt = 0, res = 0;
  int mx = 1;
  for (; mx * y < MX; ++mx) {
    int num = cum[min((mx + 1) * y, MX) - 1] - cum[mx * y - 1];
    cnt += (long long)num * mx;
  }
  mx--;
  {
    int maxRem = -1;
    long long x = 0;
    for (int i = mx; i >= 0; --i) {
      int lo = i * y;
      ckmax(maxRem, lst[min((i + 1) * y, MX) - 1].first - lo);
      ckmax(x, min(cnt - i - 1, (long long)((i + 1) * y - 1) / 2));
      if (maxRem != -1) ckmax(x, min(cnt - i, (long long)(i * y + maxRem) / 2));
    }
    ckmin(x, (long long)lst[MX - 1].first / 2);
    ckmax(res, x);
  }
  {
    pair<int, int> maxRem = {-1, -1};
    long long x = 0;
    for (int i = mx; i >= 0; --i) {
      int lo = i * y;
      check(maxRem, lst[min((i + 1) * y, MX) - 1].first - lo);
      check(maxRem, lst[min((i + 1) * y, MX) - 1].second - lo);
      ckmax(x, min(cnt - 2 * i - 2, (long long)(i + 1) * y - 1));
      if (maxRem.first != -1)
        ckmax(x, min(cnt - 2 * i - 1, (long long)i * y + maxRem.first));
      if (maxRem.second != -1)
        ckmax(x, min(cnt - 2 * i, (long long)i * y + maxRem.second));
    }
    ckmin(x, (long long)lst[MX - 1].second);
    ckmax(res, x);
  }
  if (res > 1) ckmax(ans, (long long)res * y);
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  re(n);
  for (int i = (0); i < (n); ++i) {
    int a;
    re(a);
    cum[a]++;
    check(lst[a], a);
  }
  for (int i = (1); i < (MX); ++i) {
    cum[i] += cum[i - 1];
    check(lst[i], lst[i - 1].first);
    check(lst[i], lst[i - 1].second);
  }
  for (int y = (2); y < (MX); ++y) check(y);
  ps(ans);
}
