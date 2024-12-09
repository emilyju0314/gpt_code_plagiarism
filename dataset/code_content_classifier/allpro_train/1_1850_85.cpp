#include <bits/stdc++.h>
using namespace std;
template <class _T>
inline _T sqr(const _T &first) {
  return first * first;
}
template <class _T>
inline string tostr(const _T &a) {
  ostringstream os("");
  os << a;
  return os.str();
}
const long double PI = 3.1415926535897932384626433832795L;
const double EPS = 1e-6;
char TEMPORARY_CHAR;
const int INF = 1e9;
inline void fft(vector<complex<long double> > &a, bool invert) {
  int n = (int)a.size();
  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    long double ang = 2 * PI / len * (invert ? -1 : 1);
    complex<long double> wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      complex<long double> w(1);
      for (int j = 0; j < len / 2; ++j) {
        complex<long double> u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert)
    for (int i = 0; i < n; ++i) a[i] /= n;
}
inline void input(int &a) {
  a = 0;
  while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') &&
         (TEMPORARY_CHAR != '-')) {
  }
  char neg = 0;
  if (TEMPORARY_CHAR == '-') {
    neg = 1;
    TEMPORARY_CHAR = getchar();
  }
  while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {
    a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0';
    TEMPORARY_CHAR = getchar();
  }
  if (neg) a = -a;
}
inline void out(long long a) {
  if (!a) putchar('0');
  if (a < 0) {
    putchar('-');
    a = -a;
  }
  char s[20];
  int i;
  for (i = 0; a; ++i) {
    s[i] = '0' + a % 10;
    a /= 10;
  }
  for (int j = (i)-1; j >= 0; j--) putchar(s[j]);
}
inline int nxt() {
  int(ret);
  input((ret));
  ;
  return ret;
}
struct lnum {
  vector<int> a;
  int base;
  lnum(int num = 0, int base = 1000000000) : base(base) {
    if (!num) a.resize(1);
    while (num) {
      a.push_back(num % base);
      num /= base;
    }
  }
  inline int len() const { return a.size(); }
  lnum &operator=(const lnum &l) {
    if (this != &l) {
      a = l.a;
      base = l.base;
    }
    return *this;
  }
  inline friend lnum operator+(const lnum &l, const lnum &r) {
    lnum ret(0, l.base);
    int base = l.base;
    int ln = l.len(), rn = r.len();
    int n = max(ln, rn);
    ret.a.resize(n);
    int o = 0;
    for (int i = 0; i < n; ++i) {
      int s = o;
      if (i < ln) s += l.a[i];
      if (i < rn) s += r.a[i];
      o = s >= base;
      if (o) s -= base;
      ret.a[i] = s;
    }
    if (o) ret.a.push_back(1);
    return ret;
  }
  inline friend lnum operator-(const lnum &l, const lnum &r) {
    lnum ret(0, l.base);
    int base = l.base;
    int n = l.len();
    int rn = r.len();
    ret.a.resize(n);
    int o = 0;
    for (int i = 0; i < n; ++i) {
      int s = l.a[i] - o;
      if (i < rn) s -= r.a[i];
      o = s < 0;
      if (o) s += base;
      ret.a[i] = s;
    }
    if (ret.len() > 1 && !ret.a.back()) ret.a.pop_back();
    return ret;
  }
  inline friend lnum operator*(const lnum &l, const lnum &r) {
    lnum ret(0, l.base);
    int base = l.base;
    if (l.len() * r.len() > 1000000) {
      vector<complex<long double> > fa(l.a.begin(), l.a.end()),
          fb(r.a.begin(), r.a.end());
      int n = 1;
      while (n < max(l.len(), r.len())) n <<= 1;
      n <<= 1;
      fa.resize(n), fb.resize(n);
      fft(fa, false), fft(fb, false);
      for (int i = 0; i < n; ++i) fa[i] *= fb[i];
      fft(fa, true);
      ret.a.resize(n);
      for (int i = 0; i < n; ++i) ret.a[i] = int(fa[i].real() + 0.5);
      int carry = 0;
      for (int i = 0; i < n; ++i) {
        ret.a[i] += carry;
        carry = ret.a[i] / base;
        ret.a[i] %= base;
      }
    } else {
      ret.a.resize(l.len() + r.len());
      for (int i = 0; i < l.len(); ++i)
        for (int j = 0, carry = 0; j < r.len() || carry; ++j) {
          long long cur = ret.a[i + j] +
                          (long long)l.a[i] * (j < r.len() ? r.a[j] : 0) +
                          carry;
          ret.a[i + j] = cur % base;
          carry = cur / base;
        }
    }
    while (ret.len() > 1 && !ret.a.back()) ret.a.pop_back();
    return ret;
  }
  inline friend lnum operator/(const lnum &l, const int &r) {
    lnum ret(0, l.base);
    ret.a.resize(l.len());
    int carry = 0;
    for (int i = l.len() - 1; i >= 0; --i) {
      long long cur = l.a[i] + (long long)carry * l.base;
      ret.a[i] = cur / r;
      carry = cur % r;
    }
    while (ret.len() > 1 && ret.a.back() == 0) ret.a.pop_back();
    return ret;
  }
  inline friend bool operator<(const lnum &l, const lnum &r) {
    if (l.len() < r.len()) return true;
    if (l.len() > r.len()) return false;
    int n = l.len();
    for (int i = n - 1; i >= 0; --i) {
      if (l.a[i] < r.a[i]) return true;
      if (l.a[i] > r.a[i]) return false;
    }
    return false;
  }
  inline friend bool operator>(const lnum &l, const lnum &r) { return r < l; }
  inline friend bool operator==(const lnum &l, const lnum &r) {
    if (l.len() != r.len()) return false;
    int n = l.len();
    for (int i = n - 1; i; --i) {
      if (l.a[i] != r.a[i]) return false;
    }
    return true;
  }
  inline friend bool operator!=(const lnum &l, const lnum &r) {
    return !(l == r);
  }
  inline void print() {
    if (base == 1000000000) {
      printf("%d", a.back());
      for (int i = a.size() - 2; i >= 0; --i) printf("%09d", a[i]);
    } else {
      for (int i = a.size() - 1; i >= 0; --i) printf("%d", a[i]);
    }
  }
};
int main() {
  int(n);
  input((n));
  ;
  pair<long long, long long> p[n];
  for (int i = 0; i < (int)(n); i++) {
    int a = nxt();
    int b = nxt();
    p[i].first = a + b;
    p[i].second = a - b;
  }
  sort(p, p + n);
  long long mi1[n + 1], mi2[n + 1];
  long long ma1[n + 1], ma2[n + 1];
  mi1[0] = 1e10, mi2[n] = 1e10;
  ma1[0] = -1e10, ma2[n] = -1e10;
  for (int i = 0; i < (int)(n); i++) {
    mi1[i + 1] = min(mi1[i], p[i].second);
    ma1[i + 1] = max(ma1[i], p[i].second);
  }
  for (int i = (n)-1; i >= 0; i--) {
    mi2[i] = min(mi2[i + 1], p[i].second);
    ma2[i] = max(ma2[i + 1], p[i].second);
  }
  long long l = 0, r = 4e9 + 1;
  while (l < r) {
    long long m = (l + r) / 2;
    int j = 0;
    bool ok = false;
    for (int i = 0; i < (int)(n); i++) {
      while (j < n && p[j].first - p[i].first <= m) ++j;
      if (ma1[i] - mi1[i] <= m && ma2[j] - mi2[j] <= m &&
          ma2[j] - mi1[i] <= m && ma1[i] - mi2[j] <= m) {
        ok = true;
        break;
      }
    }
    if (ok)
      r = m;
    else
      l = m + 1;
  }
  cout << setprecision(10);
  cout << fixed;
  cout << (double)l / 2 << endl;
  return 0;
}
