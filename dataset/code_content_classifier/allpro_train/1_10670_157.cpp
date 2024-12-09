#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long MOD = 1e5;
const long long ASO = 1e18;
const long long inf = -1e9;
const long long mod = -1e5;
const long long aso = -1e18;
long long t;
int main() {
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[MOD + 10];
    map<long long, long long> mp;
    long long ans = 0;
    long long mx = 0, mn = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      mx = max(mx, a[i]);
      mn = min(mn, a[i]);
      mp[a[i]]++;
    }
    for (int i = mn * 2; i <= mx * 2; ++i) {
      long long k = 0;
      map<long long, long long> c;
      for (int j = 1; j <= n; ++j) c[a[j]] = mp[a[j]];
      for (int j = 1; j <= n; ++j)
        if (c[i - a[j]] > 0 && c[a[j]] > 0) {
          if (i - a[j] == a[j])
            if (c[a[j]] < 2) continue;
          if (c[i - a[j]]) {
            c[i - a[j]]--;
            c[a[j]]--;
            k++;
          }
        }
      ans = max(ans, k);
    }
    cout << ans << "\n";
  }
  return 0;
}
