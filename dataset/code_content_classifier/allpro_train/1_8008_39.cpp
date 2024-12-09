#include <bits/stdc++.h>
using namespace std;
long long fix(long long cur, long long m) { return ((cur % m) + m) % m; }
long long fast_power_mod(long long x, long long y, long long m) {
  if (y == 0) return 1;
  long long temp = fast_power_mod(x, y / 2, m);
  temp = (temp * temp) % m;
  if (y % 2 != 0) temp = (temp * x) % m;
  return temp;
}
long long fast_power(long long x, long long y) {
  if (y == 0) return 1;
  long long temp = fast_power(x, y / 2);
  temp = (temp * temp);
  if (y % 2 != 0) temp = (temp * x);
  return temp;
}
int32_t main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    char arr[n][n];
    long long c = 0;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        if (!c) {
          if (j % 2 == 0 && k)
            arr[i][j] = 'L', k--;
          else
            arr[i][j] = 'S';
        } else {
          if (j % 2 == 0 || k == 0)
            arr[i][j] = 'S';
          else if (j % 2 == 1 && k)
            arr[i][j] = 'L', k--;
        }
      }
      c ^= 1;
    }
    if (k) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        cout << arr[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
