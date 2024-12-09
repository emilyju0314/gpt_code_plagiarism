#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long INF = 1e18;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < (n); ++i) cin >> a[i];
  if (n == 1) {
    cout << a[0] << '\n';
    return 0;
  }
  array<long long, 3> dp = {-INF, -INF, -INF};
  array<long long, 3> dpa = {0, -INF, -INF};
  for (int i = 0; i < (n); ++i) {
    array<long long, 3> ndp = {-INF, -INF, -INF};
    array<long long, 3> ndpa = {-INF, -INF, -INF};
    for (int j = 0; j < (3); ++j) {
      for (int k : {-1, 1}) {
        ndp[(j + 3 + k) % 3] = max(ndp[(j + 3 + k) % 3], dp[j] + k * a[i]);
        if (k == (i % 2 ? -1 : 1))
          ndpa[(j + 3 + k) % 3] = max(ndpa[(j + 3 + k) % 3], dpa[j] + k * a[i]);
        else
          ndp[(j + 3 + k) % 3] = max(ndp[(j + 3 + k) % 3], dpa[j] + k * a[i]);
      }
    }
    dp = ndp;
    dpa = ndpa;
  }
  cout << dp[1] << endl;
  return 0;
}
