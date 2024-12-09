#include <bits/stdc++.h>
using namespace std;
inline namespace Infinity {
inline namespace IO {
const char CR = '\n';
const char SP = ' ';
inline void write(const int n) { printf("%d", n); }
inline void write(const unsigned n) { printf("%u", n); }
inline void write(const long long n) { cout << n; }
inline void write(const unsigned long long n) { cout << n; }
inline void writef(const double a, const int n = 15) { printf("%.*f", n, a); }
inline void writef(const long double a, const int n = 18) {
  cout << setprecision(n) << fixed << a;
}
inline void write(const char c) { printf("%c", c); }
inline void write(const char s[]) { printf("%s", s); }
inline void write(const string &s) { cout << s; }
inline void write(const pair<int, int> &p) {
  printf("%d %d", p.first, p.second);
}
template <class T>
inline void write(const T a) {
  for (auto i : a) write(i), write(SP);
}
inline void writeln() { write(CR); }
template <typename T>
inline void writeln(const T &a) {
  write(a);
  write(CR);
}
inline void writefln(const double a, int n) {
  printf("%.*f", n, a);
  write(CR);
}
inline void writefln(const long double a, int n = 18) {
  cout << setprecision(n) << fixed << a << endl;
}
inline void writesln(const int *a, const int l, const int r) {
  for (int i = l; i <= r; i++) printf("%d ", a[i]);
  writeln(CR);
}
template <class T>
inline void writelns(const T a) {
  for (__typeof a.begin() i = a.begin(); i != a.end(); i++) writeln(*i);
}
template <typename T, typename... types>
inline void write(const T &a, const types &...args) {
  write(a);
  write(args...);
}
template <typename... types>
inline void writeln(const types &...args) {
  write(args...);
  write(CR);
}
template <typename... types>
inline void writeSP(const types &...args) {
  write(args...);
  write(SP);
}
inline void writelnYN(bool b) { writeln(b ? "YES" : "NO"); }
inline void writelnyn(bool b) { writeln(b ? "Yes" : "No"); }
string caseSharpSpace(int n) { return "Case #" + to_string(n) + ": "; }
string caseNoSharpSpace(int n) { return "Case " + to_string(n) + ": "; }
string caseSharpNoSpace(int n) { return "Case #" + to_string(n) + ":"; }
string caseNoSharpNoSpace(int n) { return "Case " + to_string(n) + ":"; }
inline int read(int &n) { return scanf("%d", &n); }
inline int read(long long &n) { return cin >> n ? 1 : -1; }
template <typename T, typename... types>
inline int read(T &n, types &...args) {
  read(n);
  return read(args...);
}
inline char getcc() {
  char c;
  do c = getchar();
  while (c == ' ' || c == '\n');
  return c;
}
inline int getint() {
  int n;
  read(n);
  return n;
}
inline long long getll() {
  long long n;
  read(n);
  return n;
}
inline double getdouble() {
  double n;
  scanf("%lf", &n);
  return n;
}
inline vector<int> getints(int n) {
  vector<int> v(n);
  for (int i = 0; i < n; i++) v[i] = getint();
  return v;
}
inline vector<pair<int, int>> getpairs(int n) {
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    int a = getint(), b = getint();
    v[i] = pair<int, int>(a, b);
  }
  return v;
}
inline void read(string &str, const unsigned size) {
  char s[size];
  scanf("%s", s);
  str = string(s);
}
inline string getstr(const unsigned size = 1048576) {
  string s;
  read(s, size + 1);
  return s;
}
inline string getln(const unsigned size = 1048576) {
  char s[size + 1];
  scanf("%[^\n]", s);
  getchar();
  return string(s);
}
}  // namespace IO
inline namespace Functions {
inline constexpr int ctoi(const char c) { return c - '0'; }
inline constexpr char itoc(const int n) { return n + '0'; }
inline int dtoi(const double d) { return round(d); }
template <typename T>
inline bool in(T x, T l, T r) {
  return l <= x && x <= r;
}
template <class T>
inline int size(const T &a) {
  return a.size();
}
template <typename T1, typename T2>
inline pair<T1, T2> mkp(const T1 &a, const T2 &b) {
  return make_pair(a, b);
}
template <class T>
inline void sort(T &a) {
  std::sort(a.begin(), a.end());
}
template <class T1, class T2>
inline void sort(T1 &a, T2 comp) {
  std::sort(a.begin(), a.end(), comp);
}
template <class T1, typename T2>
inline int lbound(const T1 &a, const T2 k) {
  return lower_bound(a.begin(), a.end(), k) - a.begin();
}
template <class T1, typename T2>
inline int ubound(const T1 &a, const T2 k) {
  return upper_bound(a.begin(), a.end(), k) - a.begin();
}
template <class T1, class T2>
int count(T1 &a, T2 k) {
  return ubound(a, k) - lbound(a, k);
}
template <class T1, class T2>
int find(T1 &a, T2 k) {
  return count(a, k) ? lbound(a, k) : -1;
}
template <typename T>
inline void clear(T &a) {
  memset(a, 0, sizeof a);
}
template <typename T>
T gcd(T a, T b) {
  while (b) {
    T t = a % b;
    a = b;
    b = t;
  }
  return a;
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
long long qpow(long long a, long long b, long long c) {
  return b ? qpow(a * a % c, b >> 1, c) * (b & 1 ? a : 1) % c : 1;
}
template <typename T>
T exGcd(T a, T b, T &x, T &y) {
  T d = a;
  if (b) {
    d = exGcd(b, a % b, y, x);
    y -= a / b * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}
template <typename T>
T mps(T l, T r, T k) {
  return ((r - (r % k + k) % k) - (l + (k - l % k) % k)) / k + 1;
}
template <typename T>
T sgn(T a) {
  return a == 0 ? 0 : a > 0 ? 1 : -1;
}
template <typename T>
constexpr T sq(T a) {
  return a * a;
}
}  // namespace Functions
inline namespace TypeDefine {}
inline namespace Constant {
const int maxint = INT_MAX;
const long long maxll = LLONG_MAX;
}  // namespace Constant
}  // namespace Infinity
class DisjointSetUnion {
 public:
  DisjointSetUnion(int n) : a(n + 1), r(n + 1) { iota(a.begin(), a.end(), 0); }
  int find(int x) { return a[x] != x ? a[x] = find(a[x]) : x; }
  void join(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return;
    if (r[x] < r[y])
      a[x] = y;
    else
      a[y] = x;
    if (r[x] == r[y]) r[x]++;
  }
  bool same(int x, int y) { return find(x) == find(y); }

 protected:
  vector<int> a;
  vector<int> r;
};
class DimensionConvert {
 public:
  DimensionConvert(int, int m) : m(m) {}
  int ptoi(int x, int y) { return x * m + y; }
  int ptoi(const pair<int, int> &p) { return ptoi(p.first, p.second); }
  pair<int, int> itop(int n) { return pair<int, int>(n / m, n % m); }

 protected:
  int m;
};
int main(int, char *[]) {
  int n = getint();
  int m = getint();
  DimensionConvert dc(n, m);
  vector<pair<int, pair<int, int>>> v;
  v.reserve(n * m);
  DisjointSetUnion dsu(n * m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      v.push_back(mkp(getint(), mkp(i, j)));
      if (i && v[dc.ptoi(i - 1, j)].first == v.back().first)
        dsu.join(dc.ptoi(i - 1, j), dc.ptoi(i, j));
      if (j && v[dc.ptoi(i, j - 1)].first == v.back().first)
        dsu.join(dc.ptoi(i, j - 1), dc.ptoi(i, j));
    }
  for (int i = 0; i < n; i++) {
    auto begin = v.begin() + dc.ptoi(i, 0);
    auto end = v.begin() + dc.ptoi(i + 1, 0);
    vector<pair<int, pair<int, int>>> t(end - begin);
    copy(begin, end, t.begin());
    sort(t);
    for (int j = 1; j < size(t); j++)
      if (t[j].first == t[j - 1].first)
        dsu.join(dc.ptoi(t[j].second), dc.ptoi(t[j - 1].second));
  }
  for (int j = 0; j < m; j++) {
    vector<pair<int, pair<int, int>>> t;
    for (int i = 0; i < n; i++) t.push_back(v[dc.ptoi(i, j)]);
    sort(t);
    for (int i = 1; i < n; i++)
      if (t[i].first == t[i - 1].first)
        dsu.join(dc.ptoi(t[i].second), dc.ptoi(t[i - 1].second));
  }
  sort(v, [&dsu, &dc](const pair<int, pair<int, int>> &p1,
                      const pair<int, pair<int, int>> &p2) {
    return p1.first != p2.first
               ? p1.first < p2.first
               : dsu.find(dc.ptoi(p1.second)) < dsu.find(dc.ptoi(p2.second));
  });
  vector<int> xm(n), ym(m), mm(n * m);
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < size(v); i++) {
    int j = i;
    while (j < size(v) && v[j].first == v[i].first &&
           dsu.find(dc.ptoi(v[j].second)) == dsu.find(dc.ptoi(v[i].second)))
      j++;
    int m = 0;
    for (int k = i; k < j; k++)
      m = max(m, max(xm[v[k].second.first], ym[v[k].second.second]) + 1);
    for (int k = i; k < j; k++) {
      a[v[k].second.first][v[k].second.second] = m;
      xm[v[k].second.first] = ym[v[k].second.second] = m;
    }
    i = j - 1;
  }
  for (int i = 0; i < n; i++, writeln())
    for (int j = 0; j < m; j++) write(a[i][j], SP);
  return 0;
}
