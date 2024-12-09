#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const long long INF = 1e18;
const long double PI = acos((long double)-1);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
int pct(int x) { return __builtin_popcount(x); }
int bit(int x) { return 31 - __builtin_clz(x); }
int cdiv(int a, int b) { return a / b + !(a < 0 || a % b == 0); }
template <class A>
void re(complex<A>& c);
template <class A, class B>
void re(pair<A, B>& p);
template <class A>
void re(vector<A>& v);
template <class A, size_t SZ>
void re(array<A, SZ>& a);
template <class T>
void re(T& x) {
  cin >> x;
}
void re(double& d) {
  string t;
  re(t);
  d = stod(t);
}
void re(long double& d) {
  string t;
  re(t);
  d = stold(t);
}
template <class H, class... T>
void re(H& h, T&... t) {
  re(h);
  re(t...);
}
template <class A>
void re(complex<A>& c) {
  A a, b;
  re(a, b);
  c = {a, b};
}
template <class A, class B>
void re(pair<A, B>& p) {
  re(p.first, p.second);
}
template <class A>
void re(vector<A>& x) {
  for (auto& a : x) re(a);
}
template <class A, size_t SZ>
void re(array<A, SZ>& x) {
  for (auto& a : x) re(a);
}
template <class A, class B>
string to_string(pair<A, B> p);
template <class A>
string to_string(complex<A> c) {
  return to_string(make_pair(c.real(), c.imag()));
}
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(char c) {
  string second = "";
  second += c;
  return second;
}
string to_string(string second) { return second; }
string to_string(const char* second) { return (string)second; }
string to_string(vector<bool> v) {
  bool fst = 1;
  string res = "{";
  for (int i = (0); i < ((int)v.size()); ++i) {
    if (!fst) res += ", ";
    fst = 0;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t SZ>
string to_string(bitset<SZ> b) {
  string res = "";
  for (int i = (0); i < (SZ); ++i) res += char('0' + b[i]);
  return res;
}
template <class T>
string to_string(T v) {
  bool fst = 1;
  string res = "{";
  for (const auto& x : v) {
    if (!fst) res += ", ";
    fst = 0;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <class A, class B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class A>
void pr(A x) {
  cout << to_string(x);
}
template <class H, class... T>
void pr(const H& h, const T&... t) {
  pr(h);
  pr(t...);
}
void ps() { pr("\n"); }
template <class H, class... T>
void ps(const H& h, const T&... t) {
  pr(h);
  if (sizeof...(t)) pr(" ");
  ps(t...);
}
void DBG() { cerr << "]" << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
void setIn(string second) { freopen(second.c_str(), "r", stdin); }
void setOut(string second) { freopen(second.c_str(), "w", stdout); }
void unsyncIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
void setIO(string second = "") {
  unsyncIO();
  if ((int)second.size()) {
    setIn(second + ".in"), setOut(second + ".out");
  }
}
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
long long n, m, k;
vector<long long> dif;
long long fdiv(long long a, long long b) { return a / b; }
long long cdiv(long long a, long long b) { return (a + b - 1) / b; }
long long minU() {
  long long lo = 1, hi = 1e15;
  while (lo < hi) {
    long long mid = (lo + hi) / 2;
    long long res = 0;
    for (auto& t : dif) res += cdiv(t, mid);
    if (res <= k)
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo;
}
long long maxT() {
  long long lo = 1, hi = 1e15;
  while (lo < hi) {
    long long mid = (lo + hi + 1) / 2;
    long long res = 0;
    for (auto& t : dif) res += fdiv(t, mid);
    if (res >= k)
      lo = mid;
    else
      hi = mid - 1;
  }
  return lo;
}
void solve() {
  re(n, m, k);
  vector<long long> p(m);
  re(p);
  p.insert(begin(p), 0);
  p.push_back(n);
  dif.clear();
  for (int i = (0); i < ((int)p.size() - 1); ++i)
    dif.push_back(p[i + 1] - p[i]);
  m = (int)dif.size();
  k += m;
  long long minu = minU(), maxt = maxT();
  assert(minu >= maxt);
  vector<pair<long long, long long> > cond;
  for (auto& t : dif) {
    long long x = cdiv(t, minu), y = fdiv(t, maxt);
    if (x > y) {
      cond.push_back({fdiv(t, x), y == 0 ? INF : cdiv(t, y)});
    }
  }
  sort(begin(cond), end(cond));
  long long ans = INF;
  for (auto& t : cond) {
    ckmin(ans, minu - t.first);
    ckmax(minu, t.second);
  }
  ckmin(ans, minu - maxt);
  ps(ans);
}
int main() {
  setIO();
  int t;
  re(t);
  for (int i = (0); i < (t); ++i) solve();
}
