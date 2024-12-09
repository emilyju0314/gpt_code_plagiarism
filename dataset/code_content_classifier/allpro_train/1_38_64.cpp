#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int MM = 31625;
struct simpen {
  long long a, b, c;
  void print() { printf("%I64d %I64d %I64d\n", a, b, c); }
};
long long n, a[MM], b[MM], pr[MM], cpp = 0, cpr = 0, aa[MM], bb[MM], valen[MM],
                                   momod[MM];
bool prpr[MM];
simpen p[MM];
long long dio(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = dio(b, a % b, y, x);
  y = y - x * (a / b);
  return d;
}
void start() {
  for (int i = 2; i * i <= 1000000000; i++) {
    bool test = 1;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        test = 0;
        break;
      }
    }
    if (test) pr[cpr++] = i;
  }
}
long long get(long long x, const int &y) {
  long long ret = 0;
  while (!(x % pr[y])) x /= pr[y], ++ret;
  return ret;
}
long long cc(long long a, long long b) {
  if (b < 0) a *= -1, b *= -1;
  if (a < 0) return a / b;
  return (a + b - 1) / b;
}
long long floor(long long a, long long b) { return -cc(-a, -b); }
long long asdf(long long b, long long e, long long m) {
  long long t = 0;
  for (; e; e >>= 1, (b <<= 1) %= m)
    if (e & 1) (t += b) %= m;
  return t;
}
long long power(long long a, long long n, long long mod) {
  return (n == 0
              ? 1
              : (power(a * a % mod, n / 2, mod)) * (n % 2 == 1 ? a : 1) % mod);
}
int main() {
  scanf("%I64d", &n);
  for (int i = 0; i < n; i++) scanf("%I64d %I64d", &b[i], &a[i]);
  start();
  for (int i = 0; i < cpr; i++)
    aa[i] = get(a[n - 1], i), bb[i] = get(b[n - 1], i);
  long long res = -1;
  for (int i = 0; i < n - 1; i++) {
    bool test = 0;
    simpen cewe;
    for (int j = 0; j < cpr; j++) {
      long long a0 = aa[j], b0 = bb[j];
      long long a1 = get(a[i], j), b1 = get(b[i], j);
      if (a0 || a1 || b0 != b1) {
        if (b0 != b1 && !a0 && !a1) {
          printf("-1\n");
          return 0;
        }
        if (a1 || a0) {
          if (!test) {
            cewe.a = a0;
            cewe.b = -a1;
            cewe.c = b0 - b1;
          } else {
            long long aaa = a0, bbb = -a1, ccc = b0 - b1;
            long long gay = -(cewe.a * bbb - cewe.b * aaa);
            long long x = cewe.c * bbb - cewe.b * ccc;
            long long y = cewe.a * ccc - cewe.c * aaa;
            if (!gay) {
              if (x || y) {
                printf("-1\n");
                return 0;
              }
            } else {
              if (x % gay || y % gay) {
                printf("-1\n");
                return 0;
              } else {
                if (x / gay < 0 || y / gay < 0) {
                  printf("-1\n");
                  return 0;
                }
                if (res != -1 && x / gay != res) {
                  printf("-1\n");
                  return 0;
                }
                res = x / gay;
              }
            }
          }
          test = true;
        }
      }
    }
    if (test) {
      p[cpp] = cewe;
      cpp++;
    }
  }
  for (int i = 0; i < cpp; i++) {
    if (!p[i].b) {
      if (p[i].c % p[i].a) {
        printf("-1\n");
        return 0;
      }
      if (p[i].c * p[i].a > 0) {
        printf("-1\n");
        return 0;
      }
      if (res != -1 && (-p[i].c) / p[i].a != res) {
        printf("-1\n");
        return 0;
      }
      res = (-p[i].c) / p[i].a;
    }
  }
  if (res != -1) {
    for (int i = 0; i < cpp; i++) {
      p[i].c += p[i].a * res;
      if (p[i].b) {
        if (p[i].c % p[i].b) {
          printf("-1\n");
          return 0;
        }
        if (p[i].c * p[i].b > 0) {
          printf("-1\n");
          return 0;
        }
      } else if (p[i].c) {
        printf("-1\n");
        return 0;
      }
    }
  } else {
    long long m = 0, mmin = 0, mmax = 9223372036854775807;
    for (int i = 0; i < cpp; i++) {
      if (!p[i].a) {
        if (!p[i].c % p[i].b) {
          printf("-1\n");
          return 0;
        }
        if (!p[i].c * p[i].b > 0) {
          printf("-1\n");
          return 0;
        }
      } else {
        long long x, y;
        long long d = dio(p[i].a, p[i].b, x, y);
        if (p[i].c % d) {
          printf("-1\n");
          return 0;
        }
        x *= (-p[i].c) / d;
        momod[m] = abs(p[i].b / d);
        valen[m] = x % momod[m];
        m++;
        if (p[i].b < 0)
          mmin = max(mmin, cc(-p[i].c, p[i].a));
        else
          mmax = min(mmax, floor(-p[i].c, p[i].a));
      }
    }
    if (mmin > mmax) {
      printf("-1\n");
      return 0;
    }
    long long A = 0, B = 1;
    for (int i = 0; i < m; i++) {
      long long x, y;
      long long d = dio(B, momod[i], x, y);
      long long ans = A % d;
      if ((valen[i] - ans) % d) {
        printf("-1\n");
        return 0;
      }
      B /= d;
      momod[i] /= d;
      (A -= ans) /= d;
      (valen[i] -= ans) /= d;
      long long bbb = B * momod[i];
      A = (A + B) % B;
      valen[i] = (valen[i] + momod[i]) % momod[i];
      A = (asdf(asdf(x, B, bbb), valen[i], bbb) +
           asdf(asdf(y, momod[i], bbb), A, bbb)) %
          bbb;
      B = bbb * d;
      A = (A * d + ans) % B;
    }
    (A += B) %= B;
    res = cc(mmin - A, B) * B + A;
    if (res > mmax) {
      printf("-1\n");
      return 0;
    }
  }
  printf("%I64d\n", power(a[n - 1], res, mod) * b[n - 1] % mod);
  return 0;
}
