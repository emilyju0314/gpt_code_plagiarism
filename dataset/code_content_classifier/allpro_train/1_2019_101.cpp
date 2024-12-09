#include <bits/stdc++.h>
using namespace std;
template <class T>
int size(const T& a) {
  return (int)a.size();
}
template <class T>
T sqr(const T& a) {
  return a * a;
}
char s1[1100000], s2[1100000];
int mod(char* s, int p) {
  int r = 0;
  for (int i = 0; s[i]; i++) {
    r = ((long long)r * 10 + s[i] - '0') % p;
  }
  return r;
}
int gcd(int a, int b) {
  while (a && b) (a > b ? a %= b : b %= a);
  return a + b;
}
int inv(int a, int p) {
  int b = p;
  int xa = 1, xb = 0;
  while (a && b) {
    if (a > b) {
      int k = a / b;
      xa = (p + (xa - (long long)k * xb) % p) % p;
      a %= b;
    } else {
      int k = b / a;
      xb = (p + (xb - (long long)k * xa) % p) % p;
      b %= a;
    }
  }
  return (a ? xa : xb);
}
int main() {
  scanf("%s %s", s1, s2);
  int c;
  scanf("%d", &c);
  int b = mod(s1, c);
  int res = (b - 1 + c) % c;
  if (s2[7] == 0) {
    int n;
    sscanf(s2, "%d", &n);
    for (int i = 1; i < n; i++) {
      res = (long long)res * b % c;
    }
    printf("%d", res ? res : c);
    return 0;
  }
  int phi = 1, dv = 1;
  {
    int a = c;
    for (int i = 2; i * i <= a; i++) {
      if (a % i == 0) {
        if (b % i == 0) {
          do {
            a /= i;
            dv *= i;
          } while (a % i == 0);
          continue;
        }
        a /= i;
        phi *= (i - 1);
        while (a % i == 0) {
          phi *= i;
          a /= i;
        }
      }
    }
    if (a > 1) phi *= a - 1;
  }
  int n = mod(s2, phi);
  n = (n - 1 + phi) % phi;
  c /= dv;
  res %= c;
  while (n) {
    if (n & 1) {
      res = (long long)res * b % c;
    }
    b = (long long)b * b % c;
    n >>= 1;
  }
  res = ((long long)inv(dv, c) * res) % c;
  res *= dv;
  c *= dv;
  if (!res) res = c;
  printf("%d", res);
  return 0;
}
