#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, k, ans = 0, ex = 0;
  cin >> n >> k;
  vector<long long> a(200005);
  for (long long i = 1; i < n + 1; ++i) {
    cin >> a[i];
    long long rem = a[i];
    if (ex > 0) {
      rem = a[i] - (k - ex);
      ex = 0;
      ++ans;
    }
    if (rem <= 0) continue;
    if (rem % k == 0) {
      ans += rem / k;
      continue;
    }
    ex = rem % k;
    ans += rem / k;
  }
  if (ex > 0) ++ans;
  cout << ans << "\n";
  return 0;
}
