#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, i, j, k, z = 0;
    long long int b, c, d, e, p, q, r, second;
    long long int x[101][101];
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        cin >> x[i][j];
      }
    }
    for (i = 1; i <= (n + 1) / 2; i++) {
      for (j = 1; j <= (m + 1) / 2; j++) {
        b = x[i][j];
        c = x[n + 1 - i][j];
        d = x[i][m + 1 - j];
        e = x[n + 1 - i][m + 1 - j];
        if ((n - i + 1) == i) {
          b = x[i][j];
          c = x[i][m + 1 - j];
          z = z + abs(b - c);
        } else if ((m - j + 1) == j) {
          b = x[i][j];
          c = x[n + 1 - i][j];
          z = z + abs(b - c);
        } else {
          p = abs(c - b) + abs(d - b) + abs(e - b);
          q = abs(b - c) + abs(d - c) + abs(e - c);
          r = abs(b - d) + abs(c - d) + abs(e - d);
          second = abs(b - e) + abs(e - c) + abs(e - d);
          z = z + min({p, q, r, second});
        }
      }
    }
    cout << z << endl;
  }
}
