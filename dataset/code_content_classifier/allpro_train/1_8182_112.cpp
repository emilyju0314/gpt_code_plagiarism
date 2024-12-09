#include <bits/stdc++.h>
using namespace std;
string s[200];
int cnt[200][200];
int main() {
  int n, m, i, j;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      int x = 1;
      if (s[i][j - 1] == 'B') {
        x = -1;
      }
      cnt[i][j] += x;
      cnt[i - 1][j - 1] += x;
      cnt[i - 1][j] -= x;
      cnt[i][j - 1] -= x;
    }
  }
  int ans = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (cnt[i][j] != 0) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
