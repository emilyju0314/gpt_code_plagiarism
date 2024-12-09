#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long>> a;
  vector<long long> l(n + m), r(n + m);
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a.push_back({x, 0});
  }
  for (long long i = 0; i < m; i++) {
    long long x;
    cin >> x;
    a.push_back({x, 1});
  }
  sort(a.begin(), a.end());
  long long last = -1e18;
  for (long long i = 0; i < n + m; i++) {
    if (a[i].second) {
      last = a[i].first;
    } else {
      l[i] = last;
    }
  }
  reverse(a.begin(), a.end());
  reverse(r.begin(), r.end());
  reverse(l.begin(), l.end());
  last = 1e18;
  for (long long i = 0; i < n + m; i++) {
    if (a[i].second) {
      last = a[i].first;
    } else {
      r[i] = last;
    }
  }
  long long ans = 0;
  for (long long i = 0; i < n + m; i++) {
    if (!a[i].second) {
      ans = max(ans, min(abs(a[i].first - l[i]), abs(a[i].first - r[i])));
    }
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout.precision(30);
  long long t = 1;
  while (t--) solve();
}
