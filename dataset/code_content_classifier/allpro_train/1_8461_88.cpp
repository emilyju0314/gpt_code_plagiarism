#include <bits/stdc++.h>
using namespace std;
int n, m;
double p, f[1010][1010];
double dp(int x, int y) {
  if (!x) return 1.0 / (y + 1.0);
  if (!y) return 1.0;
  if (f[x][y]) return f[x][y];
  return f[x][y] = 1.0 + ((y * 1.0) / (y + 1.0) * (1.0 - dp(y - 1, x)) - 1.0) *
                             (1.0 - 1.0 / (dp(y, x - 1) + 1.0 / (y + 1.0)) /
                                        (y + 1.0));
}
signed main() {
  cin >> n >> m;
  p = dp(n, m);
  printf("%.12lf %.12lf", p, 1.0 - p);
  return 0;
}
