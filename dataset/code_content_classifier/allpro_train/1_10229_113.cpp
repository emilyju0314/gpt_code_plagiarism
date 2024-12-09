#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, m, ta, tb, k;
  while (cin >> n >> m >> ta >> tb >> k) {
    vector<long long> A(n);
    for (__typeof(0) i = (0); i < (n); i++) cin >> A[i], A[i] += ta;
    vector<long long> B(m);
    for (__typeof(0) i = (0); i < (m); i++) cin >> B[i];
    if (k >= n) {
      cout << -1 << '\n';
      continue;
    }
    long long idx = 0, lo = 0, ans = -1;
    for (__typeof(0) i = (0); i < (k + 1); i++) {
      lo = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
      lo += k - i;
      if (lo >= m) {
        ans = -1;
        break;
      }
      ans = max(ans, B[lo] + tb);
    }
    cout << ans << '\n';
  }
  return 0;
}
