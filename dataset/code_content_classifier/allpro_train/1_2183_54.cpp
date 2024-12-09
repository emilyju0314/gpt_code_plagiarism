#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, p, k;
    cin >> n >> p >> k;
    vector<long long> a(n + 1);
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    vector<long long> pref(n + 1);
    for (long long i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + a[i];
    }
    long long ans = 0;
    for (long long i = 0; i < k; i++) {
      long long u = 0;
      long long v = p;
      if (pref[i] > v) break;
      if (i != 0) {
        u += i;
        v -= pref[i];
      }
      for (long long j = i + k; j <= n; j += k) {
        if (a[j] > v) break;
        v -= a[j];
        u += k;
      }
      ans = max(ans, u);
    }
    cout << ans << endl;
  }
  return 0;
}
