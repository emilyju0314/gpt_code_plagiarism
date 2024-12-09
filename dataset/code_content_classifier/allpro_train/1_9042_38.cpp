#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, a[110], b[110];
int main() {
  cin >> n >> m;
  if (n == 1) a[1] = 1;
  if (n == 2) a[1] = 3, a[2] = 4;
  if (n >= 3)
    if (n & 1) {
      a[1] = 2;
      for (i = 2; i < n; i++) a[i] = 1;
      a[n] = (n + 1) / 2;
    } else {
      for (i = 1; i < n; i++) a[i] = 1;
      a[n] = (n - 2) / 2;
    }
  if (m == 1) b[1] = 1;
  if (m == 2) b[1] = 3, b[2] = 4;
  if (m >= 3)
    if (m & 1) {
      b[1] = 2;
      for (i = 2; i < m; i++) b[i] = 1;
      b[m] = (m + 1) / 2;
    } else {
      for (i = 1; i < m; i++) b[i] = 1;
      b[m] = (m - 2) / 2;
    }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) cout << a[i] * b[j] << ' ';
    cout << '\n';
  }
  return 0;
}
