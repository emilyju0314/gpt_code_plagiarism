#include <bits/stdc++.h>
using namespace std;
int grid[610][610];
double THRES = 40.0;
int main() {
  ios_base::sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> grid[i][j];
    int diff = 0;
    for (int j = 0; j < m; j++)
      diff += abs(grid[n / 2 - 1][j] - grid[n / 2][j]);
    double ave = (double)diff / m;
    if (ave > THRES)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
