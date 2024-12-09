#include <bits/stdc++.h>
using namespace std;
int tab[1005][1005], n, m, l, res[1005][1005][11];
string a, b;
int main() {
  cin >> n >> m >> l;
  cin >> a >> b;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1]) {
        tab[i][j] = tab[i - 1][j - 1] + 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 1; k <= 10; k++) {
        res[i][j][k] =
            max(max(tab[i][j] + res[i - tab[i][j]][j - tab[i][j]][k - 1],
                    res[i - 1][j - 1][k]),
                max(res[i - 1][j][k], res[i][j - 1][k]));
      }
    }
  }
  int result = 0;
  for (int i = 1; i <= l; i++) {
    result = max(result, res[n][m][i]);
  }
  cout << result << endl;
  return 0;
}
