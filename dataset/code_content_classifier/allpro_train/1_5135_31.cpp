#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];
int n, m, x, y;
int main() {
  cin >> n >> m;
  for (int k = 1; k <= m; k++) {
    cin >> x >> y;
    for (int i = x; i < x + 3 && i <= n; i++) {
      for (int j = y; j < y + 3 && j <= n; j++) {
        a[i][j]++;
        if (a[i][j] == 9) return cout << k << endl, 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
