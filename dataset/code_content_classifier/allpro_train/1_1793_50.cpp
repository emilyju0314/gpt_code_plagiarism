#include <bits/stdc++.h>
using namespace std;
int n;
int x[5001];
int ans[5001][5001];
int init() {
  int i, j;
  for (i = 1; i <= n; i++) ans[i][1] = x[i];
  for (j = 2; j <= n; j++) {
    for (i = 1; i + j - 1 <= n; i++)
      ans[i][j] = ans[i][j - 1] ^ ans[i + 1][j - 1];
  }
  for (j = 2; j <= n; j++)
    for (i = 1; i + j - 1 <= n; i++)
      ans[i][j] = max(max(ans[i][j], ans[i][j - 1]), ans[i + 1][j - 1]);
  return 0;
}
int main() {
  int i;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> x[i];
  init();
  int j, k, p, q;
  cin >> k;
  while (k--) {
    cin >> p >> q;
    cout << ans[p][q - p + 1] << endl;
  }
  return 0;
}
