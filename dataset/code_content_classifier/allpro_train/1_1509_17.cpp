#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9, maxn = (int)1e5 + 1;
const double eps = (double)1e-8;
int main() {
  long long n, m, k, d, q, a[301][301];
  char x;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> x;
      if (x == '.')
        a[i][j] = 0;
      else
        a[i][j] = 1;
    }
  d = 1;
  q = 0;
  while (2 * d + 1 <= n && 2 * d + 1 <= m) {
    for (int i = d + 1; i <= n - d; i++)
      for (int j = d + 1; j <= m - d; j++)
        if (a[i][j] == 1 && a[i + d][j] == 1 && a[i - d][j] == 1 &&
            a[i][j + d] == 1 && a[i][j - d] == 1) {
          q++;
          if (q == k) {
            cout << i << " " << j << endl
                 << i - d << " " << j << endl
                 << i + d << " " << j << endl
                 << i << " " << j - d << " " << endl
                 << i << " " << j + d;
            return 0;
          }
        }
    d++;
  }
  cout << -1;
  return 0;
}
