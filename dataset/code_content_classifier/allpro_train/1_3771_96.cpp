#include <bits/stdc++.h>
using namespace std;
int a[11][11];
int main() {
  int r, c, n, m;
  cin >> r >> c >> n >> m;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    a[x][y] = 1;
  }
  for (int i = 0; i < r; i++)
    for (int j = i; j < r; j++)
      for (int k = 0; k < c; k++)
        for (int l = k; l < c; l++) {
          int cnt = 0;
          for (int p = i; p <= j; p++)
            for (int q = k; q <= l; q++) cnt += a[p][q];
          ans += cnt >= m;
        }
  cout << ans;
}
