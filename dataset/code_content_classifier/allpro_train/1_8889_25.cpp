#include <bits/stdc++.h>
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}
int min(int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}
int zt(int a, int b) { return max(a, b) - min(a, b); }
int round(int a, int b) {
  if ((a % b) * 2 >= b) {
    return (a / b) + 1;
  }
  return a / b;
}
int ceil(int a, int b) {
  if (a % b == 0) {
    return a / b;
  }
  return (a / b) + 1;
}
int gcd(int a, int b) {
  int c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
int lcm(int a, int b) {
  int c = gcd(a, b);
  a /= c;
  return a * b;
}
int nCr(int a, int b) {
  int i, r = 1;
  for (i = 1; i <= b; i++) {
    r *= (a + 1 - i);
    r /= i;
  }
  return r;
}
int fact(int a) {
  int i, r = 1;
  for (i = 1; i <= a; i++) {
    r *= i;
  }
  return r;
}
int pow(int a, int b) {
  int i, r = 1;
  for (i = 1; i <= b; i++) {
    r *= a;
  }
  return r;
}
long long llmax(long long a, long long b) {
  if (a > b) {
    return a;
  }
  return b;
}
long long llmin(long long a, long long b) {
  if (a < b) {
    return a;
  }
  return b;
}
long long llzt(long long a, long long b) { return llmax(a, b) - llmin(a, b); }
long long llround(long long a, long long b) {
  if ((a % b) * 2 >= b) {
    return (a / b) + 1;
  }
  return a / b;
}
long long llceil(long long a, long long b) {
  if (a % b == 0) {
    return a / b;
  }
  return (a / b) + 1;
}
long long llgcd(long long a, long long b) {
  long long c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
long long lllcm(long long a, long long b) {
  long long c = llgcd(a, b);
  a /= c;
  return a * b;
}
long long llnCr(long long a, long long b) {
  long long i, r = 1;
  for (i = 1; i <= b; i++) {
    r *= (a + 1 - i);
    r /= i;
  }
  return r;
}
long long llfact(long long a) {
  long long i, r = 1;
  for (i = 1; i <= a; i++) {
    r *= i;
  }
  return r;
}
long long llpow(long long a, long long b) {
  long long i, r = 1;
  for (i = 1; i <= b; i++) {
    r *= a;
  }
  return r;
}
double dbmax(double a, double b) {
  if (a > b) {
    return a;
  }
  return b;
}
double dbmin(double a, double b) {
  if (a < b) {
    return a;
  }
  return b;
}
double dbzt(double a, double b) { return dbmax(a, b) - dbmin(a, b); }
int sortfncsj(const void *a, const void *b) {
  if (*(int *)a > *(int *)b) {
    return 1;
  }
  if (*(int *)a == *(int *)b) {
    return 0;
  }
  return -1;
}
int sortfnckj(const void *a, const void *b) {
  if (*(int *)a < *(int *)b) {
    return 1;
  }
  if (*(int *)a == *(int *)b) {
    return 0;
  }
  return -1;
}
int llsortfncsj(const void *a, const void *b) {
  if (*(long long *)a > *(long long *)b) {
    return 1;
  }
  if (*(long long *)a == *(long long *)b) {
    return 0;
  }
  return -1;
}
int llsortfnckj(const void *a, const void *b) {
  if (*(long long *)a < *(long long *)b) {
    return 1;
  }
  if (*(long long *)a == *(long long *)b) {
    return 0;
  }
  return -1;
}
int dbsortfncsj(const void *a, const void *b) {
  if (*(double *)a > *(double *)b) {
    return 1;
  }
  if (*(double *)a == *(double *)b) {
    return 0;
  }
  return -1;
}
int dbsortfnckj(const void *a, const void *b) {
  if (*(double *)a < *(double *)b) {
    return 1;
  }
  if (*(double *)a == *(double *)b) {
    return 0;
  }
  return -1;
}
int strsortfncsj(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}
int strsortfnckj(const void *a, const void *b) {
  return strcmp((char *)b, (char *)a);
}
long long rep(long long k, long long x) {
  long long ks = llceil(k, 2), pt;
  if (x % 2) {
    return (x + 1) / 2;
  } else {
    pt = x / 2;
    if (k % 2 == 0) {
      return ks + rep(k / 2, pt);
    } else {
      if (pt == 1) {
        return ks + rep(k - ks, k - ks);
      } else {
        return ks + rep(k - ks, pt - 1);
      }
    }
  }
}
int main(void) {
  long long i, j, n, m, k, a, b, c, w, r = 0, l, t, q;
  scanf("%lld%lld", &n, &q);
  for (i = 0; i < q; i++) {
    scanf("%lld", &a);
    printf("%lld\n", rep(n, a));
  }
  return 0;
}
