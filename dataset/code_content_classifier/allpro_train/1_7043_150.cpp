#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
using namespace std;
long long int n, m, c[1001][1001], ans = 1, a[1001], pwr2[1001], cnt, temp;
int main() {
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        c[i][j] = 1;
      else
        c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }
  pwr2[0] = 1;
  pwr2[1] = 1;
  for (int i = 2; i <= n; i++) pwr2[i] = (pwr2[i - 1] * 2) % MOD;
  for (int i = 0; i < m; i++) cin >> a[i];
  sort(a, a + m);
  for (int i = 0; i < m; i++) {
    if (i == 0)
      temp = a[i] - 1;
    else {
      temp = a[i] - a[i - 1] - 1;
      ans = (ans * pwr2[temp]) % MOD;
    }
    cnt += temp;
    ans = (ans * c[cnt][temp]) % MOD;
  }
  cnt += n - a[m - 1];
  ans = ans * c[cnt][n - a[m - 1]] % MOD;
  cout << ans << endl;
  return 0;
}
