#include <bits/stdc++.h>
using namespace std;
#pragma GCC push_options
#pragma GCC optimize("unroll-loops")
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int INF = 10e18;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n], b[n], c[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    for (long long i = 1; i <= n; i++) {
      c[i % n] = max(0ll, a[i % n] - b[i - 1]);
    }
    long long sum = accumulate(c, c + n, 0ll);
    long long res = INF;
    for (long long i = 0; i < n; i++) {
      res = min(res, sum + a[i] - c[i]);
    }
    cout << res << endl;
  }
  return 0;
}
