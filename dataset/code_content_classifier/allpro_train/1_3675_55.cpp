#include <bits/stdc++.h>
using namespace std;
long long abs(long long, long long);
void solve() {
  long long n;
  cin >> n;
  long long a[n][n];
  double b[n][n], c[n][n];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < n; j++) cin >> a[i][j];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      b[i][j] = (a[i][j] + a[j][i]) / 2.0;
      b[j][i] = b[i][j];
      c[i][j] = (a[i][j] - a[j][i]) / 2.0;
      c[j][i] = -1 * c[i][j];
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) cout << setprecision(5) << b[i][j] << " ";
    cout << "\n";
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) cout << setprecision(5) << c[i][j] << " ";
    cout << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long TESTS = 1;
  while (TESTS--) {
    solve();
  }
  return 0;
}
long long abs(long long a, long long b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
