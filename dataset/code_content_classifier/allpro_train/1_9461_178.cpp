#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a[n + 2][m + 2];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    vector<string> v;
    int tot = n + m - 1;
    for (int i = 1; i <= tot; i++) {
      string s = "";
      int row = i, col = 1;
      if (row > n) {
        col += row - n;
        row = n;
      }
      while (row > 0 && col <= m) {
        s += (char)(a[row][col] + '0');
        row--, col++;
      }
      v.push_back(s);
    }
    int ans = 0, l = v.size();
    for (int i = 0; i < (l / 2); i++) {
      string s1 = v[i], s2 = v[l - 1 - i];
      int one = 0, zero = 0, one2 = 0, zero2 = 0;
      for (auto j : s1) {
        if (j == '0')
          one++;
        else
          zero++;
      }
      for (auto j : s2) {
        if (j == '0')
          one2++;
        else
          zero2++;
      }
      ans += min(zero + zero2, one + one2);
    }
    cout << ans << endl;
  }
}
