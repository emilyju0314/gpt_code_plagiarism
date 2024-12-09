#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int a[maxn + 50][maxn + 50];
int n, m, ans = 0;
int h[maxn + 50], l[maxn + 50];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%d", &a[i][j]);
  if (m > n) {
    for (int i = 1; i <= n; ++i) {
      int MIN = 1000;
      for (int j = 1; j <= m; ++j) MIN = min(MIN, a[i][j]);
      if (MIN) {
        ans += MIN;
        h[i] = MIN;
        for (int j = 1; j <= m; ++j) a[i][j] -= MIN;
      }
    }
    for (int j = 1; j <= m; ++j) {
      int MIN = 1000;
      for (int i = 1; i <= n; ++i) MIN = min(MIN, a[i][j]);
      if (MIN) {
        ans += MIN;
        l[j] = MIN;
        for (int i = 1; i <= n; ++i) a[i][j] -= MIN;
      }
    }
  } else {
    for (int j = 1; j <= m; ++j) {
      int MIN = 1000;
      for (int i = 1; i <= n; ++i) MIN = min(MIN, a[i][j]);
      if (MIN) {
        ans += MIN;
        l[j] = MIN;
        for (int i = 1; i <= n; ++i) a[i][j] -= MIN;
      }
    }
    for (int i = 1; i <= n; ++i) {
      int MIN = 1000;
      for (int j = 1; j <= m; ++j) MIN = min(MIN, a[i][j]);
      if (MIN) {
        ans += MIN;
        h[i] = MIN;
        for (int j = 1; j <= m; ++j) a[i][j] -= MIN;
      }
    }
  }
  bool flag = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[i][j]) flag = 0;
  if (!flag)
    printf("-1");
  else {
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= h[i]; ++j) printf("row %d\n", i);
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= l[i]; ++j) printf("col %d\n", i);
  }
  return 0;
}
