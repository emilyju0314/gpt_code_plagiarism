#include <bits/stdc++.h>
using namespace std;
long long n, m, k, i, j, t, l, a[1001][1001], x, y, c[10000];
int main() {
  cin >> n >> m >> k;
  for (i = 1; i <= k; i++) {
    cin >> x >> y;
    a[x][y] = 1;
    if (a[x - 1][y] + a[x][y - 1] + a[x - 1][y - 1] == 3) {
      cout << i;
      return 0;
    }
    if (a[x][y + 1] + a[x + 1][y] + a[x + 1][y + 1] == 3) {
      cout << i;
      return 0;
    }
    if (a[x][y + 1] + a[x - 1][y] + a[x - 1][y + 1] == 3) {
      cout << i;
      return 0;
    }
    if (a[x + 1][y] + a[x][y - 1] + a[x + 1][y - 1] == 3) {
      cout << i;
      return 0;
    }
  }
  cout << 0;
  return 0;
}
