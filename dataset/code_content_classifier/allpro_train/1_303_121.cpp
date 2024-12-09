#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int x[MAXN + 10], y[MAXN + 10], d[MAXN + 10];
int main() {
  int i, j, k, n, m, Y0, Y1;
  while (scanf("%d%d", &n, &m) != EOF) {
    scanf("%d%d", &Y0, &Y1);
    memset(d, -1, sizeof(d));
    for (i = 0; i < n; i++) scanf("%d", x + i);
    for (i = 0; i < m; i++) scanf("%d", y + i);
    j = 0;
    int tt = 0;
    for (i = 0; i < n; i++) {
      while (y[j] < x[i] && j < m) j++;
      if (j > 0) {
        if (abs(y[j] - x[i]) < abs(y[j - 1] - x[i])) {
          if (d[j] == -1 || abs(x[d[j]] - y[j]) == abs(x[i] - y[j])) {
            d[j] = i;
            tt++;
          } else if (abs(x[d[j]] - y[j]) > abs(x[i] - y[j])) {
            d[j] = i;
          }
        } else if (abs(x[i] - y[j]) > abs(x[i] - y[j - 1])) {
          if (d[j - 1] == -1 ||
              abs(x[d[j - 1]] - y[j - 1]) == abs(x[i] - y[j - 1])) {
            d[j - 1] = i;
            tt++;
          } else if (abs(x[d[j - 1]] - y[j - 1]) > abs(x[i] - y[j - 1])) {
            d[j - 1] = i;
          }
        } else {
          if (d[j - 1] == -1 ||
              abs(x[d[j - 1]] - y[j - 1]) == abs(x[i] - y[j - 1])) {
            d[j - 1] = i;
            tt++;
          } else {
            d[j] = i;
            tt++;
          }
        }
      } else {
        if (d[j] == -1 || abs(x[d[j]] - y[j]) == abs(x[i] - y[j])) {
          d[j] = i;
          tt++;
        } else if (abs(x[d[j]] - y[j]) > abs(x[i] - y[j]))
          d[j] = i;
      }
    }
    cout << n - tt << endl;
  }
}
