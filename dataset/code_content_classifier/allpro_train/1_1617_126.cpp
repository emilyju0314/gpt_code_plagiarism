#include <bits/stdc++.h>
using namespace std;
int n, mp[510][510];
long long f[510][510][2];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> mp[i][j];
      f[i][i][0] = 1;
    }
  }
  for (int len = 2; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = len + l - 1;
      for (int k = l; k < r; k++) {
        if (mp[l][r]) {
          f[l][r][0] += (f[l][k][0] + f[l][k][1]) *
                        (f[k + 1][r][0] + f[k + 1][r][1]) % 1000000007;
          f[l][r][0] %= 1000000007;
        } else
          break;
      }
      for (int k = l + 1; k < r; k++) {
        if (mp[l][k]) {
          f[l][r][1] += (f[l][k][0]) * (f[k][r][0] + f[k][r][1]) % 1000000007;
          f[l][r][1] %= 1000000007;
        }
      }
    }
  }
  cout << (f[1][n][0] + f[1][n][1]) % 1000000007 << endl;
}
