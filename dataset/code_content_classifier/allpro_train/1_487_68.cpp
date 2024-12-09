#include <bits/stdc++.h>
static const int MAXN = 202;
static const int LOGM = 15;
static int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
struct point {
  int x, y;
  point(int x = 0, int y = 0) : x(x), y(y) {}
};
struct line {
  int a, b, c;
  line() : a(0), b(0), c(0) {}
  line(const point &p, const point &q)
      : a(p.y - q.y), b(q.x - p.x), c(q.y * p.x - q.x * p.y) {
    int g = gcd(gcd(a, b), c);
    if (g != 1) {
      a /= g;
      b /= g;
      c /= g;
    }
    if (a < 0) {
      a = -a;
      b = -b;
      c = -c;
    }
  }
  inline bool contains(const point &p) { return a * p.x + b * p.y + c == 0; }
  inline bool operator<(const line &other) const {
    return a != other.a   ? a < other.a
           : b != other.b ? b < other.b
                          : c < other.c;
  }
  inline bool operator==(const line &other) const {
    return a == other.a && b == other.b && c == other.c;
  }
};
struct mat {
  static const int N = ::MAXN;
  int sz;
  double a[N][N];
  mat(int sz = N, int id = 0) : sz(sz) {
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j) a[i][j] = (i == j ? id : 0);
  }
  inline mat operator*(const mat &other) {
    assert(other.sz == this->sz);
    mat ret(sz, 0);
    for (int i = 0; i < sz; ++i)
      for (int k = 0; k < sz; ++k)
        for (int j = 0; j < sz; ++j)
          ret.a[i][j] += this->a[i][k] * other.a[k][j];
    return ret;
  }
  inline std::vector<double> operator*(const std::vector<double> &u) {
    assert(u.size() == this->sz);
    std::vector<double> v(sz);
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j < sz; ++j) v[i] += a[i][j] * u[j];
    return v;
  }
};
static int n, q;
static point p[MAXN];
static line l[MAXN * MAXN / 2];
static std::vector<int> pl[MAXN];
static std::vector<int> lp[MAXN * MAXN / 2];
static mat A, Ap[LOGM];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d%d", &p[i].x, &p[i].y);
  int l_num = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) l[l_num++] = line(p[i], p[j]);
  std::sort(l, l + l_num);
  l_num = std::unique(l, l + l_num) - &l[0];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < l_num; ++j)
      if (l[j].contains(p[i])) {
        pl[i].push_back(j);
        lp[j].push_back(i);
      }
  A = mat(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int j : pl[i])
      for (int k : lp[j]) A.a[i][k] += 1.0L / (pl[i].size() * lp[j].size());
  }
  Ap[0] = A;
  for (int i = 1; i < LOGM; ++i) Ap[i] = Ap[i - 1] * Ap[i - 1];
  scanf("%d", &q);
  std::vector<double> u(n);
  for (int i = 0, t, m; i < q; ++i) {
    scanf("%d%d", &t, &m);
    --t;
    std::fill(u.begin(), u.end(), 0);
    u[t] = 1.0;
    for (int j = 0; j < LOGM; ++j)
      if ((m - 1) & (1 << j)) u = Ap[j] * u;
    double max = -1.0;
    for (int j = 0; j < l_num; ++j) {
      double cur = 0.0;
      for (int k : lp[j]) cur += u[k];
      cur /= lp[j].size();
      max = std::max(max, cur);
    }
    printf("%.12lf\n", (double)max);
  }
  return 0;
}
