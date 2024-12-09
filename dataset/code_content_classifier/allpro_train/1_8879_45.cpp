#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
template <class T>
inline void gmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline void gmin(T &a, T b) {
  if (b < a) a = b;
}
using namespace std;
const int N = 1e5 + 20, M = 2e6 + 10, Z = 1e9 + 7, maxint = 2147483647,
          ms1 = 16843009, ms31 = 522133279, ms63 = 1061109567,
          ms127 = 2139062143;
const double PI = acos(-1.0), eps = 1e-8;
void fre() {
  freopen("/Users/luras/Desktop/in.txt", "r", stdin);
  freopen("/Users/luras/Desktop/out.txt", "w", stdout);
}
const int INF = 1e9;
int casenum, casei;
long long f[N];
double g[N];
const int TOP = 1e5 + 10;
long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
void init() {
  for (int i = 1; i <= TOP; i++) {
    f[i] = i;
    g[i] = 1;
  }
  f[1] = 2;
  for (int i = 2; i <= TOP; i++) {
    if (f[i] != 1) {
      for (int j = i; j <= TOP; j += i) {
        int num = 0;
        while (f[j] % i == 0) {
          num++;
          f[j] /= i;
        }
        for (int k = 1; k <= num; k += 2) {
          g[j] *= i;
        }
      }
    }
  }
  for (int i = 2; i <= TOP; i++) {
    f[i] = g[i - 1] * i;
    if (f[i] <= sqrt(f[i - 1])) {
      printf("%lld %lld\n", f[i], f[i - 1]);
      f[i] = (sqrt(f[i - 1]) / f[i] + 2) * f[i];
    }
  }
  for (int i = 2; i <= TOP; i++) {
    g[i] = (1.0 * f[i] * f[i] - f[i - 1]) / (i - 1);
    if (g[i] < 0) {
      int go = 1;
      printf("%lld %lld", f[i], f[i - 1]);
    }
  }
}
int n;
int main() {
  init();
  while (~scanf("%d", &n)) {
    for (int i = 2; i <= n + 1; i++) {
      printf("%.0f\n", g[i]);
    }
  }
  return 0;
}
