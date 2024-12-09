#include <bits/stdc++.h>
using namespace std;
long long mul(long long x, long long y, long long m) {
  x %= m;
  y %= m;
  long long ret = 0;
  while (y) {
    ret += x * (y % 10000) % m;
    ret %= m;
    y /= 10000;
    x *= 10000;
    x %= m;
  }
  return ret;
}
long long po(long long x, long long n, long long m) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = mul(ret, x, m);
    x = mul(x, x, m);
    n >>= 1;
  }
  return ret;
}
long long Po[22];
long long N;
int n, m = 6, M = 1000000;
long long Log(long long x, int a) {
  if (a == 1) {
    long long ret = 0;
    long long val = 1;
    for (int i = 0;; i++) {
      if (val == x % 5) return ret;
      ret++;
      val = val * 2 % 5;
    }
    exit(0);
  }
  long long tmp = Log(x, a - 1);
  for (int i = 0; i < 5; i++) {
    if (po(2, (tmp + (Po[a - 1] - Po[a - 2]) * i) % (Po[a] - Po[a - 1]),
           Po[a]) == x % Po[a]) {
      return (tmp + (Po[a - 1] - Po[a - 2]) * i) % (Po[a] - Po[a - 1]);
    }
  }
  exit(0);
}
void main2() {
  scanf("%lld", &N);
  long long tmp = N;
  n = 0;
  while (tmp) {
    n++;
    tmp /= 10;
  }
  long long x;
  long long a = ((1 << (n + m)) - (N * M % (1 << (n + m)))) % (1 << (n + m));
  while (1) {
    if ((N * M + a) % 5 == 0)
      a += (1 << (n + m));
    else
      break;
  }
  x = (N * M + a);
  x /= (1 << (n + m));
  printf("%lld\n", Log(x, n + m) + n + m);
}
int TC;
int main() {
  Po[0] = 1;
  for (int i = 1; i < 22; i++) {
    Po[i] = Po[i - 1] * 5;
  }
  scanf("%d", &TC);
  while (TC--) main2();
}
