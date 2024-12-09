#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double eps = (double)1e-8;
const int mod = (int)1000000007;
const int maxn = (int)1e5 + 5;
int n, m, k;
int a[102][102][102];
char ch;
int fl, ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m >> k;
  memset((a), 0, sizeof(a));
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (m); j++) {
      for (int q = (1); q <= (k); q++) {
        cin >> ch;
        a[i][j][q] = (ch == '1');
      }
    }
  }
  ans = 0;
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (m); j++) {
      for (int q = (1); q <= (k); q++) {
        if (!a[i][j][q]) continue;
        fl = 0;
        if (a[i + 1][j][q]) {
          if (a[i - 1][j][q]) fl = 1;
          if (a[i][j - 1][q] && !a[i + 1][j - 1][q]) fl = 1;
          if (a[i][j][q - 1] && !a[i + 1][j][q - 1]) fl = 1;
        }
        if (a[i][j + 1][q]) {
          if (a[i][j - 1][q]) fl = 1;
          if (a[i - 1][j][q] && !a[i - 1][j + 1][q]) fl = 1;
          if (a[i][j][q - 1] && !a[i][j + 1][q - 1]) fl = 1;
        }
        if (a[i][j][q + 1]) {
          if (a[i][j][q - 1]) fl = 1;
          if (a[i - 1][j][q] && !a[i - 1][j][q + 1]) fl = 1;
          if (a[i][j - 1][q] && !a[i][j - 1][q + 1]) fl = 1;
        }
        ans += fl;
      }
    }
  }
  cout << ans;
  return 0;
}
