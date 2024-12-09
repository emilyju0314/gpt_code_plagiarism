#include <bits/stdc++.h>
using namespace std;
string s, s1;
long long n, m, k, i, j, a[101][10001], b[101][10001], p, c[101][10001], res,
    ans = 1000 * 1000 * 1000;
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> s1;
    s = s1 + s1 + s1;
    k = 1000 * 1000 * 1000;
    for (j = 0; j < m; j++) {
      a[i][j] = 1000 * 1000 * 1000;
    }
    for (j = 0; j < 3 * m; j++) {
      if (s[j % m] == '1') {
        a[i][j % m] = 0;
        k = 0;
      } else {
        k++;
        a[i][j % m] = min(a[i][j % m], k);
      }
    }
    k = 1000 * 1000 * 1000;
    for (j = 3 * m - 1; j >= 0; j--) {
      if (s[j % m] == '1') {
        a[i][j % m] = 0;
        k = 0;
      } else {
        k++;
        a[i][j % m] = min(a[i][j % m], k);
      }
    }
  }
  for (j = 0; j < m; j++) {
    res = 0;
    for (i = 0; i < n; i++) {
      res += a[i][j];
    }
    if (ans > res) {
      ans = res;
    }
  }
  if (ans == 1000 * 1000 * 1000) {
    cout << -1;
    return 0;
  }
  cout << ans;
}
