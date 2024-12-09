#include <bits/stdc++.h>
using namespace std;
bool a[100][100];
long long ab(long long x) { return (x >= 0) ? x : -x; }
int main() {
  ios_base::sync_with_stdio(0);
  for (int i = 0; i < 100; ++i)
    for (int j = 0; j < 100; ++j) a[i][j] = false;
  int n, k;
  cin >> n >> k;
  int xc = k / 2 + 1;
  int yc = k / 2 + 1;
  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    long long x = -1, xl = -1, yl = -1;
    long long val = 1000000000;
    for (int ii = 1; ii <= k; ++ii)
      for (int j = 1; j + m - 1 <= k; ++j) {
        bool t = true;
        for (int q = j; q <= j + m - 1; ++q)
          if (a[ii][q]) t = false;
        if (t) {
          long long curVal = 0;
          for (int q = j; q <= j + m - 1; ++q)
            curVal += ab(ii - xc) + ab(q - yc);
          if (curVal < val) {
            val = curVal;
            x = ii;
            xl = j;
            yl = j + m - 1;
          }
        }
      }
    if (val < 1000000000) {
      cout << x << " " << xl << " " << yl << "\n";
      for (int q = xl; q <= yl; ++q) a[x][q] = true;
    } else
      cout << -1 << "\n";
  }
  return 0;
}
