#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c[1001], a[1001], b = 0, p = -1;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < m; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i] >= c[j] && j > p) {
        b++;
        c[j] = 1001;
        p = j;
        break;
      }
      if (j == n - 1 && a[i] < c[j]) {
        cout << b;
        return 0;
      }
    }
  }
  cout << b;
  return 0;
}
