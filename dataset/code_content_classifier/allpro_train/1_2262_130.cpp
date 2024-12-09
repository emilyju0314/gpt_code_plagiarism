#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9 + 7;
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = ((res) * (x));
    res %= N;
    y = y >> 1;
    x = ((x) * (x));
  }
  return res;
}
long long powmod(long long a, long long b, long long n) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % n;
    }
    y = (y * y) % n;
    b /= 2;
  }
  return x % n;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    string s[n];
    for (long long i = 0; i < n; i++) {
      cin >> s[i];
    }
    for (long long i = 1; i < n - 1; i++) {
      for (long long j = 1; j < n - 1; j++) {
        if ((s[i][j] == '.') && (s[i][j + 1] == '.') && (s[i][j - 1] == '.') &&
            (s[i + 1][j] == '.') && (s[i - 1][j] == '.')) {
          s[i][j] = '#';
          s[i][j + 1] = '#';
          s[i][j - 1] = '#';
          s[i + 1][j] = '#';
          s[i - 1][j] = '#';
        }
      }
    }
    long long flag = 1;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        if (s[i][j] == '.') {
          flag = 0;
          break;
        }
      }
    }
    if (flag)
      cout << "YES";
    else
      cout << "NO";
  }
  return 0;
}
