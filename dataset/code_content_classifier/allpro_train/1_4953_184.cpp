#include <bits/stdc++.h>
using namespace std;
int a[400][400];
int b;
int n;
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &b);
        a[i][b] = j;
      }
    }
    for (int i = 0; i <= 0; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &b);
        a[i][b] = j;
      }
    }
    for (int i = 1; i <= n; i++) {
      int mp = 100000;
      int idx = -1;
      int ans = -1;
      int tp = 100000;
      for (int j = 1; j <= n; j++) {
        if (j == i) continue;
        if (mp > a[0][j]) {
          mp = a[0][j];
          idx = j;
        }
        if (tp > a[i][idx]) {
          tp = a[i][idx];
          ans = idx;
        }
      }
      if (i != 1) putchar(' ');
      printf("%d", ans);
    }
    puts("");
  }
}
