#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long sum = 0;
    long long ct_0 = 0;
    long long ct_n = 0;
    long long a[n + 3][m + 4];
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        cin >> a[i][j];
        if (a[i][j] == 0) {
          ct_0++;
        } else if (a[i][j] < 0) {
          ct_n++;
        }
        sum += abs(a[i][j]);
      }
    }
    if (ct_0 > 0 || ct_n % 2 == 0) {
      cout << sum << "\n";
    } else {
      long long min_n = INT_MAX;
      for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= m; j++) {
          if (a[i][j] < 0) {
            a[i][j] = -a[i][j];
          }
          if (a[i][j] < min_n) min_n = a[i][j];
        }
      }
      cout << sum - 2 * min_n << "\n";
    }
  }
  return 0;
}
