#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n + 1);
    for (long long i = 1; i <= n; i++) cin >> a[i];
    vector<long long> len(n + 1, 1);
    long long ans = INT_MIN;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= sqrt(i); j++) {
        if (i % j == 0) {
          if (a[i] > a[j]) len[i] = max(len[i], len[j] + 1);
          if (a[i] > a[i / j]) len[i] = max(len[i], len[i / j] + 1);
        }
      }
      ans = max(ans, len[i]);
    }
    cout << ans << "\n";
  }
}
