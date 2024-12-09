#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    if (a[x] == 1) {
      a[x] = 0;
      continue;
    } else if (x == 0) {
      a[1] = a[1] + a[x] - y;
      a[x] = 0;
    } else if (x == n - 1) {
      a[n - 1] = 0;
      a[x - 1] = a[x - 1] + y - 1;
    } else {
      a[x - 1] = a[x - 1] + y - 1;
      a[x + 1] = a[x + 1] + a[x] - y;
      a[x] = 0;
    }
  }
  for (int i = 0; i < n; i++) cout << a[i] << "\n";
  return 0;
}
