#include <bits/stdc++.h>
using namespace std;
const int maxN = 1005;
const int MOD = 1e9 + 7;
int n, i, j, a[maxN];
long long Choose[maxN][maxN];
long long ans = 1, sum = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  Choose[0][0] = 1;
  for (j = 0; j <= maxN - 5; j++) {
    for (i = 0; i <= maxN - 5; i++) {
      if (i == 0 || j == 0 || i == j) {
        Choose[i][j] = 1;
      } else if (i <= j) {
        Choose[i][j] = Choose[i - 1][j - 1] + Choose[i][j - 1];
        Choose[i][j] %= MOD;
      }
    }
  }
  for (i = 0; i < n; i++) {
    sum += a[i];
    sum %= MOD;
    ans *= Choose[a[i] - 1][sum - 1];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
