#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    vector<long long> b(n);
    for (long long i = 0; i + 1 < n; i += 2) {
      b[i] = a[i + 1];
      b[i + 1] = -a[i];
    }
    for (long long i = 0; i < n; i++) {
      cout << b[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}
