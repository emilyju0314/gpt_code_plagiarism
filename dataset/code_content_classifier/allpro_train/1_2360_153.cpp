#include <bits/stdc++.h>
using namespace std;
const int MAXN = 55;
int n, m;
int a[MAXN][MAXN];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    set<int> rows, columns;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        if (a[i][j] == 1) rows.insert(i), columns.insert(j);
      }
    }
    int res = min(n - rows.size(), m - columns.size());
    if (res % 2 == 0)
      cout << "Vivek" << endl;
    else
      cout << "Ashish" << endl;
  }
  return 0;
}
