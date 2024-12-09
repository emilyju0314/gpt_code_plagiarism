#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    reverse(a, a + n);
    long long ans = 0;
    long long mn = INT_MAX;
    for (long long i = 0; i < n; i++) {
      mn = min(a[i], mn);
      if (i + 1 <= mn) ans = i + 1;
    }
    cout << ans << endl;
  }
  return 0;
}
