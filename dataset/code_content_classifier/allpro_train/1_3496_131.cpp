#include <bits/stdc++.h>
static inline unsigned long long rdtsc() {
  unsigned long long d;
  __asm__ __volatile__("rdtsc" : "=A"(d));
  return d;
}
using namespace std;
const int inf = (int)1e9;
const double eps = 1e-9;
const int maxn = 1010;
int a[maxn][maxn];
int n;
inline bool check() {
  for (int i = 0; (i) < (n); ++i)
    for (int j = 0; (j) < (n); ++j)
      if (i != j) {
        bool ok = false;
        if (a[i][j]) ok = true;
        for (int k = 0; (k) < (n); ++k)
          if (a[i][k] && a[k][j]) ok = true;
        if (!ok) return false;
      }
  return true;
}
int main() {
  scanf("%d", &n);
  if (n < 100) {
    while (true) {
      double T = clock() * 1. / CLOCKS_PER_SEC;
      if (T > 0.1) {
        printf("-1\n");
        return 0;
      }
      for (int i = 0; (i) < (n); ++i)
        for (int j = 0; (j) < (i); ++j) {
          int c = rand() & 1;
          a[i][j] = c;
          a[j][i] = 1 - c;
        }
      if (check()) break;
    }
  } else {
    for (int i = 0; (i) < (n); ++i)
      for (int j = 0; (j) < (i); ++j) {
        int c = rand() & 1;
        a[i][j] = c;
        a[j][i] = 1 - c;
      }
  }
  for (int i = 0; (i) < (n); ++i)
    for (int j = 0; (j) < (n); ++j) printf("%d%c", a[i][j], " \n"[j + 1 == n]);
  return 0;
}
