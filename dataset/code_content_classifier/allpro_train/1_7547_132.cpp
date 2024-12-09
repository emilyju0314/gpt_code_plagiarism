#include <bits/stdc++.h>
using namespace std;
template <typename _T>
using pair2 = pair<_T, _T>;
template <typename _T>
using pair3 = pair<pair<_T, _T>, _T>;
template <typename _T>
using pair4 = pair<pair<_T, _T>, pair<_T, _T> >;
template <typename _T>
using priq = priority_queue<_T>;
template <typename _T>
using qrip = priority_queue<_T, vector<_T>, greater<_T> >;
const long double pi = acosl(-1);
const int Inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
unsigned Rand() { return rand() * 32768 + rand(); }
int rand(int a, int b) { return Rand() % (b - a + 1) + a; }
template <typename _T>
inline _T chmin(_T& a, _T b) {
  return a > b ? (a = b) : a;
}
template <typename _T>
inline _T chmax(_T& a, _T b) {
  return a < b ? (a = b) : a;
}
template <typename _T, int len>
struct BIT {
  _T dt[len];
  inline void add(int a, _T x) {
    while (a < len) {
      dt[a] += x;
      a += a & -a;
    }
  }
  inline void add(int l, int r, _T x) {
    add(l, x);
    add(r + 1, -x);
  }
  inline _T get(int a) {
    _T ans = 0;
    while (a) {
      ans += dt[a];
      a -= a & -a;
    }
    return ans;
  }
  inline _T get(int l, int r) { return get(r) - get(l - 1); }
};
template <typename _T, int len>
struct segbit {
  _T dt[2][len];
  inline void add(int a, _T x) {
    int b = a;
    while (a < len) {
      dt[0][a] += x;
      dt[1][a] += x * b;
      a += a & -a;
    }
  }
  inline void add(int l, int r, _T x) {
    add(l, x);
    add(r + 1, -x);
  }
  inline _T sum(int a) {
    _T ans = 0;
    int b = a;
    while (a) {
      ans += (b + 1) * dt[0][a] - dt[1][a];
      a -= a & -a;
    }
    return ans;
  }
  inline _T sum(int l, int r) { return sum(r) - sum(l - 1); }
};
struct fastIO {
  inline fastIO operator>>(int& num) {
    num = 0;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    bool foo = 0;
    if (c == '-') {
      foo = 1;
      c = getchar();
    }
    while (c >= '0' && c <= '9') {
      num = (num << 3) + (num << 1) + c - '0';
      c = getchar();
    }
    if (foo) num = -num;
    return *this;
  }
  inline fastIO operator>>(long long& num) {
    num = 0;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    bool foo = 0;
    if (c == '-') {
      foo = 1;
      c = getchar();
    }
    while (c >= '0' && c <= '9') {
      num = (num << 3) + (num << 1) + c - '0';
      c = getchar();
    }
    if (foo) num = -num;
    return *this;
  }
  inline fastIO operator>>(float& num) {
    scanf("%f", &num);
    return *this;
  }
  inline fastIO operator>>(double& num) {
    scanf("%lf", &num);
    return *this;
  }
  inline fastIO operator>>(long double& num) {
    scanf("%Lf", &num);
    return *this;
  }
  inline fastIO operator>>(char& num) {
    num = getchar();
    while (num == ' ' || num == '\n') num = getchar();
    return *this;
  }
  inline fastIO operator>>(char* num) {
    int cnt = 0;
    char c = getchar();
    while (c == ' ' || c == '\n') c = getchar();
    while (c != ' ' && c != '\n') {
      num[cnt++] = c;
      c = getchar();
    }
    num[cnt] = 0;
    return *this;
  }
  inline fastIO operator>>(string& num) {
    cin >> num;
    return *this;
  }
  inline void printInt(const int& num) {
    if (num < 10) {
      putchar(num + '0');
      return;
    }
    printInt(num / 10);
    putchar((num % 10) + '0');
  }
  inline void printll(const long long& num) {
    if (num < 10) {
      putchar(num + '0');
      return;
    }
    printll(num / 10);
    putchar((num % 10) + '0');
  }
  inline fastIO operator<<(const int& num) {
    if (num < 0)
      putchar('-'), printInt(-num);
    else
      printInt(num);
    return *this;
  }
  inline fastIO operator<<(const long long& num) {
    if (num < 0)
      putchar('-'), printll(-num);
    else
      printll(num);
    return *this;
  }
  inline fastIO operator<<(const float& num) {
    printf("%.10f", num);
    return *this;
  }
  inline fastIO operator<<(const double& num) {
    printf("%.16lf", num);
    return *this;
  }
  inline fastIO operator<<(const long double& num) {
    printf("%.20Lf", num);
    return *this;
  }
  inline fastIO operator<<(const char& num) {
    putchar(num);
    return *this;
  }
  inline fastIO operator<<(const char* num) {
    for (int i = 0; num[i]; i++) putchar(num[i]);
    return *this;
  }
  inline fastIO operator<<(const string& num) {
    cout << num;
    return *this;
  }
  template <typename _T>
  inline fastIO operator<<(const vector<_T>& vec) {
    printf("{ ");
    for (__typeof((vec).begin()) i = (vec).begin(), ed = (vec).end(); i != ed;
         i++)
      operator<<(*i) << ' ';
    printf("}");
    return *this;
  }
} fio;
const long double eps = 1e-10;
struct point {
  long double x, y;
  long double ang;
  point() {}
  point(long double x, long double y) : x(x), y(y) { ang = atan2l(y, x); }
  inline point operator+(const point& pt) const {
    return point(x + pt.x, y + pt.y);
  }
  inline point operator-(const point& pt) const {
    return point(x - pt.x, y - pt.y);
  }
  inline point operator*(const long double& a) const {
    return point(x * a, y * a);
  }
  inline point operator/(const long double& a) const {
    return point(x / a, y / a);
  }
  inline long double operator*(const point& pt) const {
    return x * pt.x + y * pt.y;
  }
  inline long double operator%(const point& pt) const {
    return x * pt.y - y * pt.x;
  }
  inline long double length() const { return x * x + y * y; }
  inline long double operator^(const point& pt) const {
    return acosl(*this * pt) / length() / pt.length();
  }
  inline long double getangle() { return ang = atan2l(y, x); }
  inline bool operator<(const point& p) const { return ang < p.ang; }
};
inline bool xsmaller(const point& x, const point& y) {
  return fabs(x.x - y.x) < 1e-10 ? x.y < y.y : x.x < y.x;
}
inline bool ysmaller(const point& x, const point& y) {
  return fabs(x.y - y.y) < 1e-10 ? x.x < y.x : x.y < y.y;
}
struct line {
  point a, b;
  line() {}
  line(point a, point b) : a(a), b(b) {}
};
point intersect(line x, line y) {
  point p1 = x.a, v1 = x.b - x.a;
  point p2 = y.a, v2 = y.b - y.a;
  return p1 + v1 * (((p2 - p1) % v2) / (v1 % v2));
}
const int jt[2] = {998244353, 2066076461};
const int ch[2] = {233, 277};
template <int len>
struct DSU {
  int fa[len], sz[len];
  DSU() {
    for (int i = 0; i < (len); i++) fa[i] = i, sz[i] = 1;
  }
  void init() {
    for (int i = 0; i < (len); i++) fa[i] = i, sz[i] = 1;
  }
  int root(int x) { return fa[x] == x ? x : (fa[x] = root(fa[x])); }
  bool conn(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return 0;
    fa[a] = b;
    sz[b] += sz[a];
    return 1;
  }
};
template <typename _T>
inline _T qp(_T a, int b) {
  if (!b) {
    return 1;
  }
  _T x = qp(a, b >> 1);
  x = x * x;
  if (b & 1) {
    x = x * a;
  }
  return x;
}
template <int R, int C = R>
struct matrix {
  int mat[R][C];
  int* operator[](int x) { return mat[x]; }
  matrix() {
    for (int i = 0; i < (R); i++)
      for (int j = 0; j < (C); j++) mat[i][j] = 0;
  }
  matrix(int x) {
    for (int i = 0; i < (R); i++)
      for (int j = 0; j < (C); j++) mat[i][j] = (i == j ? x : 0);
  }
  matrix<R, C> operator+(const matrix<R, C> m) {
    matrix<R, C> ans;
    for (int i = 0; i < (R); i++)
      for (int j = 0; j < (C); j++)
        ans.mat[i][j] = (mat[i][j] + m.mat[i][j]) % jt;
    return ans;
  }
  template <int D>
  matrix<R, D> operator*(const matrix<C, D> m) {
    matrix<R, D> ans;
    for (int i = 0; i < (R); i++)
      for (int j = 0; j < (C); j++)
        for (int k = 0; k < (D); k++)
          ans.mat[i][k] =
              (ans.mat[i][k] + ((long long)mat[i][j]) * m.mat[j][k]) % jt;
    return ans;
  }
  void debug() {
    for (int i = 0; i < (R); i++) {
      for (int j = 0; j < (C); j++)
        if (0) cout << mat[i][j] << ' ';
      if (0) cout << endl;
    }
    if (0) cout << endl;
  }
};
int n, m;
char tmp[1000005];
struct HashStr {
  string s;
  vector<int> hsh[2], mii[2];
  void inihash() {
    for (int $ = 0; $ < (2); $++) {
      mii[$].resize(((int)((s).size())) + 1);
      mii[$][0] = 1;
      for (int i = 1; i <= (((int)((s).size()))); i++) {
        mii[$][i] = 1ll * mii[$][i - 1] * ch[$] % jt[$];
      }
      hsh[$].resize(((int)((s).size())) + 1);
      for (int i = 0; i < (((int)((s).size()))); i++) {
        hsh[$][i + 1] = (1ll * hsh[$][i] * ch[$] + s[i]) % jt[$];
      }
    }
  }
  void init() {
    fio >> tmp;
    s = tmp;
    inihash();
  }
  long long get(int l, int r) {
    return ((hsh[0][r] - 1ll * hsh[0][l] * mii[0][r - l] % jt[0] + jt[0]) %
            jt[0]) *
               jt[1] +
           ((hsh[1][r] - 1ll * hsh[1][l] * mii[1][r - l] % jt[1] + jt[1]) %
            jt[1]);
  }
};
HashStr a, b, s;
int ag[1000005], bg[1000005];
segbit<long long, 1000005> bit;
int main() {
  fio >> n >> m;
  a.init();
  b.init();
  s.init();
  for (int i = 0; i < (n); i++) {
    int l = -1, r = min(n - i, m - 1) + 1;
    while (r - l > 1) {
      int $ = (l + r) >> 1;
      if (a.get(i, i + $) == s.get(0, $)) {
        l = $;
      } else {
        r = $;
      }
    }
    ag[i] = l;
  }
  for (int i = 0; i < (n); i++) {
    int l = -1, r = min(i + 1, m - 1) + 1;
    while (r - l > 1) {
      int $ = (l + r) >> 1;
      if (b.get(i - $ + 1, i + 1) == s.get(m - $, m)) {
        l = $;
      } else {
        r = $;
      }
    }
    bg[i] = l;
  }
  long long $ = 0;
  for (int i = (n)-1; i >= 0; i--) {
    bit.add(m - bg[i], 1);
    if (i + m - 1 < n) {
      bit.add(m - bg[i + m - 1], -1);
    }
    $ += bit.sum(1, ag[i]);
  }
  fio << $ << '\n';
  return 0;
}
