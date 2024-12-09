#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int n, m;
  cin >> n >> m;
  vector<long long int> pref(n + 1);
  for (long long int i = 1; i <= n; i++) {
    long long int c, t;
    cin >> c >> t;
    pref[i] = pref[i - 1] + c * t;
  }
  for (long long int i = 0; i < m; i++) {
    long long int v;
    cin >> v;
    auto p = lower_bound(pref.begin(), pref.end(), v) - pref.begin();
    cout << p << endl;
  }
  return 0;
}
