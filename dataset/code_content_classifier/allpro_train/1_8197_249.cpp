#include <bits/stdc++.h>
using namespace std;
int n, m, c, first;
int a[1005];
int main() {
  for (int l = 0; l < 1002; ++l) a[l] = -1;
  cin >> n >> m >> c;
  for (int l = 0; l < m; ++l) {
    cin >> first;
    if (first <= c / 2) {
      for (int l2 = 1; l2 <= n; ++l2) {
        if (a[l2] == -1 || a[l2] > first) {
          cout << l2 << '\n';
          fflush(stdout);
          a[l2] = first;
          break;
        }
      }
    } else {
      for (int l2 = n; l2 > 0; --l2) {
        if (a[l2] < first) {
          cout << l2 << '\n';
          fflush(stdout);
          a[l2] = first;
          break;
        }
      }
    }
    bool f = 1;
    for (int l = 1; l <= n; ++l) {
      if (l < n && a[l] > a[l + 1] || a[l] == -1) f = 0;
    }
    if (f) break;
  }
  return 0;
}
