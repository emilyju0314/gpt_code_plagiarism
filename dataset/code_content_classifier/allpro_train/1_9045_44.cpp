#include <bits/stdc++.h>
using namespace std;
int n, m, ar[51][51], a, b, ans, sum, c[51][51];
int main() {
  ios::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  ans = 3000;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> ar[i][j];
      c[i][j] = ar[i][j] + c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
    }
  cin >> a >> b;
  for (int i = a; i <= n; i++) {
    for (int j = b; j <= m; j++) {
      sum = c[i][j] - c[i][j - b] - c[i - a][j] + c[i - a][j - b];
      ans = min(ans, sum);
    }
  }
  swap(a, b);
  for (int i = a; i <= n; i++) {
    for (int j = b; j <= m; j++) {
      sum = c[i][j] - c[i][j - b] - c[i - a][j] + c[i - a][j - b];
      ans = min(ans, sum);
    }
  }
  cout << ans << endl;
  return 0;
}
