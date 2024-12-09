#include <bits/stdc++.h>
template <typename T>
inline T max(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
inline T min(T a, T b) {
  return a < b ? a : b;
}
template <typename T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
template <typename T>
inline bool repr(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool repl(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline T gcd(T a, T b) {
  T t;
  if (a < b) {
    while (a) {
      t = a;
      a = b % a;
      b = t;
    }
    return b;
  } else {
    while (b) {
      t = b;
      b = a % b;
      a = t;
    }
    return a;
  }
}
template <typename T>
inline T sqr(T x) {
  return x * x;
}
struct Cg {
  __attribute__((always_inline)) inline char operator()() { return getchar(); }
};
struct Cp {
  __attribute__((always_inline)) inline void operator()(char x) { putchar(x); }
};
__attribute__((always_inline)) inline bool IS(char x) {
  return x == 10 || x == 13 || x == ' ';
}
template <typename T>
struct Fr {
  T P;
  __attribute__((always_inline)) inline Fr &operator,(int &x) {
    x = 0;
    unsigned char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (f) x = -x;
    return *this;
  }
  __attribute__((always_inline)) inline operator int() {
    int x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(long long &x) {
    x = 0;
    unsigned char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (f) x = -x;
    return *this;
  }
  __attribute__((always_inline)) inline operator long long() {
    long long x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(char &x) {
    for (x = P(); IS(x); x = P())
      ;
    return *this;
  }
  __attribute__((always_inline)) inline operator char() {
    char x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(char *x) {
    char t = P();
    for (; IS(t); t = P())
      ;
    if (~t) {
      for (; !IS(t) && ~t; t = P()) *x++ = t;
    }
    *x++ = 0;
    return *this;
  }
  __attribute__((always_inline)) inline Fr &operator,(double &x) {
    x = 0;
    unsigned char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (t == '.') {
      double u = 0.1;
      for (t = P(); t >= '0' && t <= '9'; t = P(), u *= 0.1) x += u * (t - '0');
    }
    if (f) x = -x;
    return *this;
  }
  __attribute__((always_inline)) inline operator double() {
    double x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(long double &x) {
    x = 0;
    unsigned char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (t == '.') {
      double u = 0.1;
      for (t = P(); t >= '0' && t <= '9'; t = P(), u *= 0.1) x += u * (t - '0');
    }
    if (f) x = -x;
    return *this;
  }
  __attribute__((always_inline)) inline operator long double() {
    long double x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(unsigned int &x) {
    x = 0;
    unsigned char t = P();
    while (t < '0' || t > '9') t = P();
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    return *this;
  }
  __attribute__((always_inline)) inline operator unsigned int() {
    unsigned int x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(unsigned long long &x) {
    x = 0;
    unsigned char t = P();
    while (t < '0' || t > '9') t = P();
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    return *this;
  }
  __attribute__((always_inline)) inline operator unsigned long long() {
    unsigned long long x;
    *this, x;
    return x;
  }
};
Fr<Cg> in;
template <typename T>
struct Fw {
  T P;
  __attribute__((always_inline)) inline Fw &operator,(int x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      unsigned char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(int x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      unsigned char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator,(unsigned int x) {
    if (x) {
      unsigned char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(unsigned int x) {
    if (x) {
      unsigned char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator,(long long x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      unsigned char s[19], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(long long x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      unsigned char s[19], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator,(unsigned long long x) {
    if (x) {
      unsigned char s[20], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(unsigned long long x) {
    if (x) {
      unsigned char s[20], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator,(char x) {
    P(x);
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(char x) {
    P(x);
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator,(const char *x) {
    while (*x) P(*x++);
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(const char *x) {
    while (*x) P(*x++);
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(double x, int y) {
    if (y) {
      double t = 0.5;
      for (int i = y; i--;) t *= 0.1;
      if (x >= 0)
        x += t;
      else
        x -= t, P('-');
      *this, (long long)(abs(x));
      P('.');
      if (x < 0) x = -x;
      while (y--) {
        x *= 10;
        x -= floor(x * 0.1) * 10;
        P(((int)x) % 10 + '0');
      }
    } else if (x >= 0)
      *this, (long long)(x + 0.5);
    else
      *this, (long long)(x - 0.5);
    ;
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(long double x, int y) {
    if (y) {
      double t = 0.5;
      for (int i = y; i--;) t *= 0.1;
      if (x >= 0)
        x += t;
      else
        x -= t, P('-');
      *this, (long long)(abs(x));
      P('.');
      if (x < 0) x = -x;
      while (y--) {
        x *= 10;
        x -= floor(x * 0.1) * 10;
        P(((int)x) % 10 + '0');
      }
    } else if (x >= 0)
      *this, (long long)(x + 0.5);
    else
      *this, (long long)(x - 0.5);
    ;
    return *this;
  }
};
Fw<Cp> out;
struct vec {
  double x, y;
  vec() {}
  vec(double a, double b) { x = a, y = b; }
  inline vec &operator+=(const vec &a) {
    x += a.x, y += a.y;
    return *this;
  }
  inline vec &operator-=(const vec &a) {
    x -= a.x, y -= a.y;
    return *this;
  }
  inline vec &operator/=(const double &a) {
    x /= a, y /= a;
    return *this;
  }
  inline vec &operator*=(const double &a) {
    x *= a, y *= a;
    return *this;
  }
  inline vec operator+(const vec &b) const {
    vec a = *this;
    a += b;
    return a;
  }
  inline vec operator-(const vec &b) const {
    vec a = *this;
    a -= b;
    return a;
  }
  inline vec operator/(const double &b) const {
    vec a = *this;
    a /= b;
    return a;
  }
  inline vec operator*(const double &b) const {
    vec a = *this;
    a *= b;
    return a;
  }
  inline double operator*(const vec &a) const { return x * a.x + y * a.y; }
  inline double operator%(const vec &a) const { return x * a.y - y * a.x; }
  inline double sqrd() const { return sqr(x) + sqr(y); }
  inline double d() { return sqrt(sqrd()); }
  inline double a() { return atan2(y, x); }
};
inline double sqrdis(const vec &a, const vec &b) {
  return sqr(a.x - b.x) + sqr(a.y - b.y);
}
inline double dis(const vec &a, const vec &b) { return sqrt(sqrdis(a, b)); }
inline vec rotl(const vec &a) { return vec(-a.y, a.x); }
inline vec rotr(const vec &a) { return vec(a.y, -a.x); }
struct line {
  vec a, b;
  line() {}
  line(vec x, vec y) { a = x, b = y; }
};
inline double intf(const line &a, const line &b) {
  return (b.b % (a.a - b.a)) / (a.b % b.b);
}
inline vec intsec(const line &a, const line &b) {
  return a.a + a.b * intf(a, b);
}
inline line rotl(const line &a) { return line(a.a, rotl(a.b)); }
inline line rotr(const line &a) { return line(a.a, rotr(a.b)); }
const int N = 100007;
const double pi = acos(-1), eps = 1e-8;
vec s[N], a[N];
int n, q[N * 2], nxt[N], pre[N];
bool vis[N];
double r;
inline int getconvex(vec *s, vec *t, int n) {
  std::sort(s, s + n, [&](vec x, vec y) {
    return x.x < y.x || (x.x == y.x && x.y < y.y);
  });
  int qe = 1;
  q[0] = 0;
  for (int i = 1, iend = n - 1; i <= iend; i++) {
    for (; qe > 1 && (s[i] - s[q[qe - 2]]) % (s[q[qe - 1]] - s[q[qe - 2]]) >= 0;
         qe--)
      ;
    q[qe++] = i;
  }
  int te = qe;
  for (int i = (n - 1) - 1; ~i; i--) {
    for (;
         qe > te && (s[i] - s[q[qe - 2]]) % (s[q[qe - 1]] - s[q[qe - 2]]) >= 0;
         qe--)
      ;
    q[qe++] = i;
  }
  assert(q[qe - 1] == 0 && qe - 1 <= n);
  for (int i = 0, iend = qe - 1; i < iend; i++) t[i] = s[q[i]];
  return qe - 1;
}
inline bool chk(vec *s, int x) {
  vec a = s[x], b = s[pre[x]], c = s[nxt[x]];
  vec t = (c - b) / 2;
  double td = t.d();
  if (abs(td) < eps) return 0;
  vec u = vec(-t.y, t.x) * sqrt(r * r - td * td) / td;
  return dis(b + t + u, a) <= r;
}
inline int getsec(vec *s, vec *t, int n) {
  for (int i = 0, iend = n; i < iend; i++)
    nxt[i] = (i + 1) % n, pre[(i + 1) % n] = i;
  int qe = 0;
  for (int i = 0, iend = n; i < iend; i++) q[qe++] = i;
  for (int i = 0; i < qe; i++) {
    if (!vis[q[i]] && chk(s, q[i])) {
      q[qe++] = nxt[q[i]];
      q[qe++] = pre[q[i]];
      nxt[pre[q[i]]] = nxt[q[i]];
      pre[nxt[q[i]]] = pre[q[i]];
      vis[q[i]] = 1;
    }
  }
  int c = 0;
  for (int i = 0, iend = n; i < iend; i++)
    if (!vis[i]) t[c++] = s[i];
  return c;
}
inline double getxa(double x) {
  double h = sqrt(r * r - sqr(x / 2));
  double a = asin(x / 2 / r);
  return r * r * a - x * h / 2;
}
int main() {
  in, n, r;
  if (n == 1) {
    out, 0, '\n';
    return 0;
  }
  for (int i = 0, iend = n; i < iend; i++) in, s[i].x, s[i].y;
  n = getconvex(s, a, n);
  n = getsec(a, s, n);
  s[n] = s[0];
  double ans = 0;
  for (int i = 0, iend = n; i < iend; i++) ans += getxa(dis(s[i], s[i + 1]));
  for (int i = 1, iend = n - 1; i <= iend; i++)
    ans += abs((s[i + 1] - s[i]) % (s[i] - s[0])) / 2;
  printf("%.10lf\n", ans);
}
