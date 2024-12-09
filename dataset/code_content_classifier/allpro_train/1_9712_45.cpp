#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const long long INF = 4e18 + 10;
const long long INF2 = 2e18 + 10;
const long long MAXN = 200010;
const long long LOGN = 19;
const long long MOD = 1000000007;
const long double EPS = 1e-7;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < n / 2; i++) {
    for (long long j = 1; j <= m; j++) {
      cout << i + 1 << ' ' << j << '\n';
      cout << n - i << ' ' << m - j + 1 << '\n';
    }
  }
  if (n & 1) {
    for (long long j = 1; j <= m / 2; j++) {
      cout << (n + 1) / 2 << ' ' << j << '\n';
      cout << (n + 1) / 2 << ' ' << m - j + 1 << '\n';
    }
    if (m & 1) {
      cout << (n + 1) / 2 << ' ' << (m + 1) / 2;
    }
  }
}
