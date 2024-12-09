#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
unsigned long long T;
unsigned long long x;
unsigned long long times;
unsigned long long pr = 0;
inline unsigned long long read() {
  unsigned long long x = 0, ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
unsigned long long ans = 1;
unsigned long long divi[2000005];
struct factor {
  unsigned long long x, t;
};
factor p[2000005];
unsigned long long pre[2000005];
unsigned long long tt, pp;
inline void gettimes() {
  unsigned long long N = 0;
  unsigned long long divisor = 2;
  while (x) {
    unsigned long long u = x % divisor;
    divi[u]++;
    N = max(N, u);
    x /= divisor++;
    times++;
  }
  pr = max(pr, N);
  for (unsigned long long i = 1; i <= N; ++i) {
    if (divi[i]) {
      p[++tt].t = divi[i];
      p[tt].x = i;
    }
  }
  for (unsigned long long i = tt - 1; i > 0; --i) {
    pre[i] = pre[i + 1] + p[i + 1].t;
  }
}
inline unsigned long long C(unsigned long long M, unsigned long long N) {
  if (N > M) return 0;
  if (N == 1) return M;
  unsigned long long ret = 1;
  for (unsigned long long i = M; i > (M - N); --i) {
    ret *= i;
  }
  for (unsigned long long i = 1; i <= N; ++i) {
    ret /= i;
  }
  return ret;
}
unsigned long long res = 1;
int main() {
  T = read();
  while (T--) {
    for (unsigned long long i = 1; i <= pr; ++i) {
      divi[i] = pre[i] = p[i].t = p[i].x = 0;
    }
    x = read();
    times = 0;
    ans = 1;
    tt = 0;
    res = 1;
    gettimes();
    pp = tt;
    while (tt) {
      ans *= C(times - p[tt].x + 1 - pre[tt], p[tt].t);
      tt--;
    }
    while (pp) {
      res *= C(times - 1 - p[pp].x + 1 - pre[pp], p[pp].t);
      pp--;
    }
    cout << ans - res - 1 << endl;
    pr = max(pr, tt);
  }
  return 0;
}
