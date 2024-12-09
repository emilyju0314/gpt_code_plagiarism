#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int n, m;
int a[105][105];
int ans, row[105], col[105];
void caluRow() {
  for (int i = 1; i <= n; i++) {
    int mi = 501;
    for (int j = 1; j <= m; j++) mi = min(mi, a[i][j]);
    if (mi > 0) {
      ans += mi;
      row[i] += mi;
      for (int j = 1; j <= m; j++) a[i][j] -= mi;
    }
  }
}
void caluCol() {
  for (int i = 1; i <= m; i++) {
    int mi = 501;
    for (int j = 1; j <= n; j++) mi = min(mi, a[j][i]);
    if (mi > 0) {
      ans += mi;
      col[i] += mi;
      for (int j = 1; j <= n; j++) a[j][i] -= mi;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  if (m > n) {
    caluRow();
    caluCol();
  } else {
    caluCol();
    caluRow();
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j]) {
        printf("-1");
        return 0;
      }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++)
    while (row[i]--) printf("row %d\n", i);
  for (int i = 1; i <= m; i++)
    while (col[i]--) printf("col %d\n", i);
  return 0;
}
