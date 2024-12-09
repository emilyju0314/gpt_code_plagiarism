#include <bits/stdc++.h>
using namespace std;
int n, m, tmp, ans, arr[1001][1001];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 2 * m; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      tmp = arr[i][j * 2] + arr[i][j * 2 - 1];
      if (tmp) ans++;
    }
  }
  cout << ans << endl;
}
