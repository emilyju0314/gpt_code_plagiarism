#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
int u[100005], v[100005];
int main() {
  int n, m, x, y;
  while (scanf("%d %d %d %d", &n, &m, &x, &y) == 4) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    int p = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      while (p < m && b[p] < a[i] - x) p++;
      if (p >= m) break;
      if (a[i] - x <= b[p] && b[p] <= a[i] + y) {
        u[cnt] = i + 1;
        v[cnt] = p + 1;
        cnt++;
        p++;
      }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) printf("%d %d\n", u[i], v[i]);
  }
  return 0;
}
