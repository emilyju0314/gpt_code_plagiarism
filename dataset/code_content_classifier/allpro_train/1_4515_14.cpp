#include <bits/stdc++.h>
using namespace std;
const unsigned long long MOD = ((unsigned long long)1 << 63) - 25;
const int MX = 2e5 + 5;
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
  mi(const int& v) {
    if (v < 0)
      val = v + MOD;
    else
      val = v;
  }
  mi(const unsigned long long& v) {
    ps("HUH");
    exit(0);
  }
  friend void pr(const mi& a) { pr(a.val); }
  friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
  friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
  friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
  mi operator-() const { return mi(-val); }
  mi& operator+=(const mi& m) {
    if ((val += m.val) >= MOD) val -= MOD;
    return *this;
  }
  mi& operator-=(const mi& m) {
    if (val >= m.val)
      val -= m.val;
    else
      val += MOD - m.val;
    return *this;
  }
  mi& operator*=(const mi& m) {
    unsigned long long a = val, b = m.val;
    long long ret =
        a * b - MOD * (unsigned long long)((long double)a * b / MOD);
    val = ret + ((ret < 0) - (ret >= (long long)MOD)) * MOD;
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
template <class T>
struct Mat {
  int r, c;
  vector<vector<T>> d;
  Mat(int _r, int _c) : r(_r), c(_c) { d.assign(r, vector<T>(c)); }
  Mat() : Mat(0, 0) {}
  Mat(const vector<vector<T>>& _d) : r((int)_d.size()), c((int)_d[0].size()) {
    d = _d;
  }
  friend void pr(const Mat& m) { pr(m.d); }
  Mat& operator+=(const Mat& m) {
    assert(r == m.r && c == m.c);
    for (int i = (0); i < (r); ++i)
      for (int j = (0); j < (c); ++j) d[i][j] += m.d[i][j];
    return *this;
  }
  Mat& operator-=(const Mat& m) {
    assert(r == m.r && c == m.c);
    for (int i = (0); i < (r); ++i)
      for (int j = (0); j < (c); ++j) d[i][j] -= m.d[i][j];
    return *this;
  }
  Mat operator*(const Mat& m) {
    assert(c == m.r);
    Mat x(r, m.c);
    for (int i = (0); i < (r); ++i)
      for (int j = (0); j < (c); ++j)
        for (int k = (0); k < (m.c); ++k) x.d[i][k] += d[i][j] * m.d[j][k];
    return x;
  }
  Mat operator+(const Mat& m) { return Mat(*this) += m; }
  Mat operator-(const Mat& m) { return Mat(*this) -= m; }
  Mat& operator*=(const Mat& m) { return *this = (*this) * m; }
  friend Mat pow(Mat m, long long p) {
    assert(m.r == m.c);
    Mat res(m.r, m.c);
    for (int i = (0); i < (m.r); ++i) res.d[i][i] = 1;
    for (; p; p /= 2, m *= m)
      if (p & 1) res *= m;
    return res;
  }
};
int getRow(Mat<mi>& m, int n, int i, int nex) {
  for (int j = (nex); j < (n); ++j)
    if (m.d[j][i] != 0) return j;
  return -1;
}
template <class T>
pair<T, int> gauss(Mat<T>& m) {
  int n = m.r, rank = 0, nex = 0;
  T prod = 1;
  for (int i = (0); i < (n); ++i) {
    int row = getRow(m, n, i, nex);
    if (row == -1) {
      prod = 0;
      continue;
    }
    if (row != nex) prod *= -1, swap(m.d[row], m.d[nex]);
    prod *= m.d[nex][i];
    rank++;
    auto x = 1 / m.d[nex][i];
    for (int k = (i); k < (m.c); ++k) m.d[nex][k] *= x;
    for (int j = (0); j < (n); ++j)
      if (j != nex) {
        auto v = m.d[j][i];
        if (v == 0) continue;
        for (int k = (i); k < (m.c); ++k) m.d[j][k] -= v * m.d[nex][k];
      }
    nex++;
  }
  return {prod, rank};
}
template <class T>
Mat<T> inv(Mat<T> m) {
  assert(m.r == m.c);
  int n = m.r;
  Mat<T> x(n, 2 * n);
  for (int i = (0); i < (n); ++i) {
    x.d[i][i + n] = 1;
    for (int j = (0); j < (n); ++j) x.d[i][j] = m.d[i][j];
  }
  if (gauss(x).second != n) return Mat<T>();
  Mat<T> res(n, n);
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n); ++j) res.d[i][j] = x.d[i][j + n];
  return res;
}
int n, b[60], r[60];
bool reach[60];
vector<int> blue[60], red[60];
Mat<mi> A;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  re(n);
  for (int i = (0); i < (n - 1); ++i) {
    re(b[i], r[i]);
    b[i]--, r[i]--;
    blue[b[i]].push_back(i);
    red[r[i]].push_back(i);
  }
  A = Mat<mi>(n - 1, n - 1);
  for (int i = (0); i < (n - 1); ++i) {
    A.d[i][i] = 2;
    for (auto& x : red[i]) A.d[i][x] -= 1;
    for (auto& x : blue[i]) A.d[i][x] -= 1;
  }
  A = inv(A);
  unsigned long long mx = (n - 1);
  for (int i = (0); i < (n - 1); ++i) mx *= 2;
  int q;
  re(q);
  for (int i = (0); i < (q); ++i) {
    int v;
    string second;
    re(v, second);
    v--;
    vector<int> dif(n);
    for (int j = (0); j < (n - 1); ++j) {
      dif[j] = (second[j] == 'R');
      for (auto& t : blue[j]) dif[j] -= second[t] == 'R';
      dif[j] += j == 0;
      dif[j] -= j == v;
    }
    vector<mi> x(n - 1), y(n - 1);
    for (int i = (0); i < (n - 1); ++i) {
      for (int j = (0); j < (n - 1); ++j) x[i] += A.d[i][j] * dif[j];
      y[i] = x[i] - (second[i] == 'R');
    }
    unsigned long long sum = 0;
    bool bad = 0;
    for (int i = (0); i < (n - 1); ++i) {
      if ((unsigned long long)x[i] > mx) bad = 1;
      sum += (unsigned long long)x[i];
      if (sum > mx) bad = 1;
      if ((unsigned long long)y[i] > mx) bad = 1;
      sum += (unsigned long long)y[i];
      if (sum > mx) bad = 1;
    }
    if (bad) {
      ps(-1);
      continue;
    }
    for (int i = (0); i < (n - 1); ++i) {
      long long sum = 2 * (unsigned long long)x[i];
      for (auto& t : blue[i]) sum -= (unsigned long long)x[t];
      for (auto& t : red[i]) sum -= (unsigned long long)x[t];
      if (sum != dif[i]) bad = 1;
    }
    for (int i = (0); i < (n); ++i) reach[i] = 0;
    queue<int> q;
    reach[v] = 1;
    q.push(v);
    while ((int)q.size()) {
      int x = q.front();
      q.pop();
      for (int i = (0); i < (n); ++i)
        if (!reach[i]) {
          if (second[i] == 'R' && r[i] == x) {
            reach[i] = 1;
            q.push(i);
            continue;
          }
          if (second[i] == 'B' && b[i] == x) {
            reach[i] = 1;
            q.push(i);
            continue;
          }
        }
    }
    for (int i = (0); i < (n - 1); ++i)
      if ((unsigned long long)x[i] && !reach[i]) {
        bad = 1;
      }
    if (bad) {
      ps(-1);
      continue;
    }
    ps(sum);
  }
}
