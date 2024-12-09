#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int maxt = 1565;
struct pro {
  int sSmall, sLarge, tSmall, tLarge;
  double probFail;
  void read() {
    scanf("%d%d%d%d%lf", &sSmall, &sLarge, &tSmall, &tLarge, &probFail);
  }
  double calc() const { return probFail / (1 - probFail) * tLarge; }
  bool operator<(const pro &x) const { return calc() < x.calc(); }
};
inline void chkmin(long double &a, long double b) {
  if (a > b) a = b;
}
int n, t;
pro tasks[maxn];
int prv[maxn][maxt];
long double f[maxn][maxt], g[maxn][maxt];
int main() {
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; i++) {
    tasks[i].read();
  }
  sort(tasks, tasks + n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= t; j++) {
      f[i + 1][j] = f[i][j];
      prv[i + 1][j] = 8;
      if (j >= tasks[i].tSmall + tasks[i].tLarge) {
        if (f[i][j - tasks[i].tSmall - tasks[i].tLarge] + tasks[i].sSmall +
                tasks[i].sLarge * (1.0 - tasks[i].probFail) >
            f[i + 1][j]) {
          f[i + 1][j] = f[i][j - tasks[i].tSmall - tasks[i].tLarge] +
                        tasks[i].sSmall +
                        tasks[i].sLarge * (1.0 - tasks[i].probFail);
          prv[i + 1][j] = 1;
        }
        if (f[i][j - tasks[i].tSmall - tasks[i].tLarge] + tasks[i].sSmall +
                tasks[i].sLarge * (1.0 - tasks[i].probFail) ==
            f[i + 1][j]) {
          prv[i + 1][j] |= 1;
        }
      }
      if (j >= tasks[i].tSmall) {
        if (f[i][j - tasks[i].tSmall] + tasks[i].sSmall > f[i + 1][j]) {
          f[i + 1][j] = f[i][j - tasks[i].tSmall] + tasks[i].sSmall;
          prv[i + 1][j] = 2;
        }
        if (f[i][j - tasks[i].tSmall] + tasks[i].sSmall == f[i + 1][j]) {
          prv[i + 1][j] |= 2;
        }
      }
      if (j && f[i + 1][j - 1] > f[i + 1][j]) {
        f[i + 1][j] = f[i + 1][j - 1];
        prv[i + 1][j] = 4;
      }
      if (j && f[i + 1][j - 1] == f[i + 1][j]) {
        prv[i + 1][j] |= 4;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= t; j++) {
      g[i + 1][j] = t * 2.0;
      if (prv[i + 1][j] & 1)
        chkmin(g[i + 1][j],
               (1.0 - tasks[i].probFail) * j +
                   tasks[i].probFail *
                       (g[i][j - tasks[i].tSmall - tasks[i].tLarge] +
                        tasks[i].tSmall));
      if (prv[i + 1][j] & 2)
        chkmin(g[i + 1][j], g[i][j - tasks[i].tSmall] + tasks[i].tSmall);
      if (prv[i + 1][j] & 4) chkmin(g[i + 1][j], g[i + 1][j - 1]);
      if (prv[i + 1][j] & 8) chkmin(g[i + 1][j], g[i][j]);
    }
  }
  printf("%.20lf %.20lf\n", (double)f[n][t], (double)g[n][t]);
  return 0;
}
