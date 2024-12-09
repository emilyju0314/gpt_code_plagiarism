#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int64_t n;
  cin >> n;
  vector<int64_t> a(n), b(n);
  for (int64_t i = 0; i < n; ++i) cin >> a[i];
  sort((a).begin(), (a).end());
  for (int64_t i = 0; i < n; ++i) b[i] = a[i];
  reverse((b).begin(), (b).end());
  int64_t ans = 0;
  for (int64_t i = 0; i < n; ++i)
    ans = (ans % 10007 + (a[i] % 10007) * (b[i] % 10007)) % 10007;
  cout << ans;
}
