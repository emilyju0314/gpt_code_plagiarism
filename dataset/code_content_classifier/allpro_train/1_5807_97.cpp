#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
const int M = 1000000007;
const double eps = 1e-9;
const double PI = acos(-1);
const int oo = 1000000000;
int n, m, g[501][501], an[501];
int main() {
  cin >> n >> m;
  int xo = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &g[i][j]);
    }
    xo ^= g[i][0];
  }
  if (!xo) {
    for (int i = 0; i < n && !xo; ++i) {
      for (int j = 0; j < m && !xo; ++j) {
        if (xo ^ g[i][0] ^ g[i][j]) {
          xo ^= g[i][0] ^ g[i][j];
          an[i] = j;
        }
      }
    }
  }
  if (xo) {
    puts("TAK");
    for (int i = 0; i < n; ++i) printf("%d ", an[i] + 1);
  } else {
    puts("NIE");
  }
  return 0;
}
