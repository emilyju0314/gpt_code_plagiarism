#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
inline int getint() {
  char c = getchar();
  int x = 0, mi = 1;
  while (c != EOF && c != '-' && !isdigit(c)) c = getchar();
  if (c == '-') {
    mi = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x * mi;
}
inline long long getll() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline double getdb() {
  static double x;
  scanf("%lf", &x);
  return x;
}
string getstr() {
  string s;
  char c;
  do {
    c = getchar();
  } while ((c == ' ' || c == '\r' || c == '\n') && c != EOF);
  if (c == EOF) return s;
  do {
    s.push_back(c);
    c = getchar();
  } while (c != ' ' && c != '\n' && c != '\r' && c != EOF);
  return s;
}
bool readingFail = false;
string getline() {
  string s;
  char c;
  while ((c = getchar()) != '\n' && c != '\r' && c != EOF) s.push_back(c);
  if (c == EOF) {
    readingFail = true;
    return s;
  }
  while (!s.empty() && (s.back() == '\n' || s.back() == '\r')) s.pop_back();
  return s;
}
void sc(char* const& x) { scanf("%s", x); }
void sc(int& x) { scanf("%d", &x); }
void sc(long long& x) { scanf("%lld", &x); }
void sc(double& x) { scanf("%lf", &x); }
template <typename T, typename... Args>
void sc(T& v, Args&... args) {
  sc(v);
  sc(args...);
}
void pr(const char* const& s) { printf("%s", s); }
void pr(char* const& s) { printf("%s", s); }
void pr(char const& x) { printf("%c", x); }
void pr(bool const& x) { printf("%d", x); }
void pr(int const& x) { printf("%d", x); }
void pr(long long const& x) { printf("%lld", x); }
void pr(double const& x) { printf("%.12f", x); }
void pr(long double const& x) { printf("%.12f", (double)x); }
template <typename T, typename... Args>
void pr(T const& v, Args const&... args) {
  pr(v);
  pr(' ');
  pr(args...);
}
template <typename... Args>
void prln(Args const&... args) {
  pr(args...);
  pr("\n");
}
template <>
void prln() {
  pr("\n");
}
template <typename T>
T gcd(T const& x, T const& y) {
  return abs(__gcd(x, y));
}
time_point<system_clock> timing;
void TBegin() { timing = system_clock::now(); }
double TEnd(const char* c = "time: ") {
  auto end = system_clock::now();
  auto d = duration_cast<microseconds>(end - timing);
  auto dt =
      double(d.count()) * microseconds::period::num / microseconds::period::den;
  printf("%s%.10f", c, dt);
  return dt;
}
void TTick(const char* c = "time:") {
  TEnd(c);
  TBegin();
}
void Fin() { freopen("in.txt", "r", stdin); }
template <typename T>
void updmax(
    T& a, T const& b, function<void(void)> f = [] {}) {
  if (a < b) {
    a = b;
    f();
  }
}
template <typename T>
void updmin(
    T& a, T const& b, function<void(void)> f = [] {}) {
  if (b < a) {
    a = b;
    f();
  }
}
template <typename T>
void fill(T a[], T v, int len) {
  for (decltype(0) i = 0, lim__lim = (len); i <= lim__lim; i++) a[i] = v;
}
template <typename T>
int descr(T* from, T* to) {
  sort(from, to);
  return (int)(unique(from, to) - from);
}
template <typename T>
int lbound(T* from, T* to, T const& val) {
  return (int)(lower_bound(from, to, val) - from);
}
template <typename T>
int ubound(T* from, T* to, T const& val) {
  return (int)(upper_bound(from, to, val) - from);
}
template <typename T>
void rm(vector<T>& v, function<bool(T const&)> cond) {
  v.erase(remove_if(v.begin(), v.end(), cond), v.end());
}
template <typename T>
void rm(set<T>& v, function<bool(T const&)> cond) {
  for (auto x = v.begin(); x != v.end();) {
    if (cond(*x))
      v.erase(x++);
    else
      ++x;
  }
}
template <typename T, typename R>
void rm(map<T, R>& v, function<bool(T const&)> cond) {
  for (auto x = v.begin(); x != v.end();) {
    if (cond(x->first))
      v.erase(x++);
    else
      ++x;
  }
}
template <typename T>
void rm(vector<T>& v, T const& x) {
  v.erase(remove_if(v.begin(), v.end(), [&](T const& e) { return e == x; }),
          v.end());
}
template <typename T>
void rm(set<T>& v, T const& x) {
  while (v.find(x) != v.end()) v.erase(v.find(x));
}
template <typename T, typename R>
void rm(map<T, R>& v, T const& x) {
  while (v.find(x) != v.end()) v.erase(v.find(x));
}
template <typename T>
T sgn(T const& v) {
  return v < 0 ? -1 : v > 0 ? 1 : 0;
}
template <typename T>
vector<T> getarr(int const& sz) {
  auto a = vector<int>(sz);
  for (decltype(0) i = 0, lim__lim = (sz - 1); i <= lim__lim; i++) sc(a[i]);
  return a;
}
vector<int> getbits(unsigned int x, int len = 32) {
  vector<int> a;
  for (decltype(0) i = 0, lim__lim = (len - 1); i <= lim__lim; i++)
    a.push_back(((1u << i) & x) != 0);
  return a;
}
string strbits(unsigned int x, int len = 32) {
  auto a = getbits(x, len);
  string s;
  for (auto& p : a) s.push_back(p + '0');
  reverse(s.begin(), s.end());
  return s;
}
const int mxn = 18;
long long n, y, k;
vector<int> proh[mxn], prob[mxn];
int u[mxn][mxn];
int ans[mxn];
long long Cnt(int t) {
  vector<int> v;
  for (decltype(1) i = 1, lim__lim = (n); i <= lim__lim; i++) v.push_back(i);
  for (decltype(1) i = 1, lim__lim = (t); i <= lim__lim; i++)
    rm<int>(v, ans[i]);
  static long long d[1 << mxn];
  int m = n - t;
  unsigned int sx = (1u << m) - 1;
  for (decltype(0u) i = 0u, lim__lim = (sx); i <= lim__lim; i++) d[i] = 0;
  d[0] = 1;
  for (decltype(1u) i = 1u, lim__lim = (sx); i <= lim__lim; i++) {
    int ck = 0;
    for (decltype(0) j = 0, lim__lim = (m - 1); j <= lim__lim; j++)
      ck += (i & (1u << j)) != 0;
    assert(ck > 0);
    int cv = v[ck - 1];
    for (decltype(0) j = 0, lim__lim = (m - 1); j <= lim__lim; j++) {
      unsigned int msk = 1u << j;
      if ((msk & i) == 0) continue;
      if (u[t + j + 1][cv] != 0) continue;
      bool valid = true;
      for (auto& p : proh[t + j + 1])
        if (p > t) {
          unsigned int pmsk = 1u << (p - t - 1);
          if ((i & pmsk) != 0) {
            valid = false;
            break;
          }
        }
      for (auto& p : prob[t + j + 1])
        if (p > t) {
          unsigned int pmsk = 1u << (p - t - 1);
          if ((i & pmsk) == 0) {
            valid = false;
            break;
          }
        }
      if (!valid) continue;
      d[i] += d[i - msk];
    }
  }
  return d[sx];
}
int main() {
  sc(n, y, k);
  y -= 2000;
  for (decltype(1) i = 1, lim__lim = (k); i <= lim__lim; i++) {
    int a, b;
    sc(a, b);
    ;
    proh[a].push_back(b);
    prob[b].push_back(a);
  }
  for (decltype(1) t = 1, lim__lim = (n); t <= lim__lim; t++) {
    for (decltype(1) v = 1, lim__lim = (n); v <= lim__lim; v++) {
      if (u[t][v] != 0) continue;
      bool used = false;
      for (decltype(1) i = 1, lim__lim = (t - 1); i <= lim__lim; i++)
        if (ans[i] == v) {
          used = true;
          break;
        }
      if (used) continue;
      ans[t] = v;
      for (decltype(1) i = 1, lim__lim = (n); i <= lim__lim; i++) u[i][v]++;
      for (auto& i : proh[t])
        for (decltype(1) j = 1, lim__lim = (v - 1); j <= lim__lim; j++)
          u[i][j]++;
      for (auto& i : prob[t])
        for (decltype(v + 1) j = v + 1, lim__lim = (n); j <= lim__lim; j++)
          u[i][j]++;
      long long cc = Cnt(t);
      for (decltype(1) i = 1, lim__lim = (n); i <= lim__lim; i++) u[i][v]--;
      for (auto& i : proh[t])
        for (decltype(1) j = 1, lim__lim = (v - 1); j <= lim__lim; j++)
          u[i][j]--;
      for (auto& i : prob[t])
        for (decltype(v + 1) j = v + 1, lim__lim = (n); j <= lim__lim; j++)
          u[i][j]--;
      if (cc >= y) break;
      ans[t] = 0;
      y -= cc;
    }
    if (ans[t] == 0) {
      prln("The times have changed");
      return 0;
    }
    for (decltype(1) i = 1, lim__lim = (n); i <= lim__lim; i++) u[i][ans[t]]++;
    for (auto& i : proh[t])
      for (decltype(1) j = 1, lim__lim = (ans[t] - 1); j <= lim__lim; j++)
        u[i][j]++;
    for (auto& i : prob[t])
      for (decltype(ans[t] + 1) j = ans[t] + 1, lim__lim = (n); j <= lim__lim;
           j++)
        u[i][j]++;
  }
  for (decltype(1) i = 1, lim__lim = (n); i <= lim__lim; i++) pr(ans[i], "");
  return 0;
}
